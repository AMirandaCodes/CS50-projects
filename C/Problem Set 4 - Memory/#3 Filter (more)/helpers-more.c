#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate each row (height)
    for (int h = 0; h < height; h++)
    {
        // Iterate through each pixel of a row (width)
        for (int w = 0; w < width; w++)
        {
            // Calculate the average pixel value
            double average =
                (image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0;

            int gray = round(average);

            // Set each colour to the average value
            image[h][w].rgbtRed = gray;
            image[h][w].rgbtGreen = gray;
            image[h][w].rgbtBlue = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate each row (height)
    for (int h = 0; h < height; h++)
    {
        // Iterate through each pixel of the row (width)
        for (int w = 0; w < width / 2; w++)
        {
            // Swap pixels on horizontally opposite sides
            // temp = a;
            // a = b;
            // b = temp;
            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][width - 1 - w];
            image[h][width - 1 - w] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Creates a temporary image to store the blurred pixels
    RGBTRIPLE temp[height][width];

    // Iterate each row (height)
    for (int h = 0; h < height; h++)
    {
        // Iterate through each pixel of a row (width)
        for (int w = 0; w < width; w++)
        {
            int red_total = 0;
            int green_total = 0;
            int blue_total = 0;
            int count = 0;

            // Loop over 3x3 grid around the pixel
            for (int delta_h = -1; delta_h <= 1; delta_h++)
            {
                for (int delta_w = -1; delta_w <= 1; delta_w++)
                {
                    int neighbour_h = h + delta_h;
                    int neighbour_w = w + delta_w;

                    // Check boundaries
                    if (neighbour_h >= 0 && neighbour_h < height && neighbour_w >= 0 &&
                        neighbour_w < width)
                    {
                        red_total += image[neighbour_h][neighbour_w].rgbtRed;
                        green_total += image[neighbour_h][neighbour_w].rgbtGreen;
                        blue_total += image[neighbour_h][neighbour_w].rgbtBlue;
                        count++;
                    }
                }
            }
            temp[h][w].rgbtRed = round((float) red_total / count);
            temp[h][w].rgbtGreen = round((float) green_total / count);
            temp[h][w].rgbtBlue = round((float) blue_total / count);
        }
    }

    // Copy temp back to image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp[h][w];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Sobel kernels
    int gx_grid[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int gy_grid[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int gx_red = 0, gx_green = 0, gx_blue = 0;
            int gy_red = 0, gy_green = 0, gy_blue = 0;

            // Loop 3x3 around pixel
            for (int dh = -1; dh <= 1; dh++)
            {
                for (int dw = -1; dw <= 1; dw++)
                {
                    int nh = h + dh;
                    int nw = w + dw;

                    // Skip if outside image (treat as black = 0)
                    if (nh < 0 || nh >= height || nw < 0 || nw >= width)
                        continue;

                    // Get kernel position
                    int kernel_row = dh + 1;
                    int kernel_col = dw + 1;

                    // Apply kernels
                    gx_red += image[nh][nw].rgbtRed * gx_grid[kernel_row][kernel_col];
                    gx_green += image[nh][nw].rgbtGreen * gx_grid[kernel_row][kernel_col];
                    gx_blue += image[nh][nw].rgbtBlue * gx_grid[kernel_row][kernel_col];

                    gy_red += image[nh][nw].rgbtRed * gy_grid[kernel_row][kernel_col];
                    gy_green += image[nh][nw].rgbtGreen * gy_grid[kernel_row][kernel_col];
                    gy_blue += image[nh][nw].rgbtBlue * gy_grid[kernel_row][kernel_col];
                }
            }

            // Combine Gx and Gy
            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

            // Cap at 255
            temp[h][w].rgbtRed = (red > 255) ? 255 : red;
            temp[h][w].rgbtGreen = (green > 255) ? 255 : green;
            temp[h][w].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    // copy back
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp[h][w];
        }
    }
}
