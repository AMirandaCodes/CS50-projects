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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate each row (height)
    for (int h = 0; h < height; h++)
    {
        // Iterate through each pixel of a row (width)
        for (int w = 0; w < width; w++)
        {
            // Calculate new sepia colour (double) using formulas
            double sepiaRed = (0.393 * image[h][w].rgbtRed) + (0.769 * image[h][w].rgbtGreen) +
                              (0.189 * image[h][w].rgbtBlue);
            double sepiaGreen = (0.349 * image[h][w].rgbtRed) + (0.686 * image[h][w].rgbtGreen) +
                                (0.168 * image[h][w].rgbtBlue);
            double sepiaBlue = (0.272 * image[h][w].rgbtRed) + (0.534 * image[h][w].rgbtGreen) +
                               (0.131 * image[h][w].rgbtBlue);

            // Round each sepia colour
            int adjusted_sepiaRed = round(sepiaRed);
            int adjusted_sepiaGreen = round(sepiaGreen);
            int adjusted_sepiaBlue = round(sepiaBlue);

            // Cap each colour to 255 (in case result is over 255)
            if (adjusted_sepiaRed > 255)
            {
                adjusted_sepiaRed = 255;
            }
            if (adjusted_sepiaGreen > 255)
            {
                adjusted_sepiaGreen = 255;
            }
            if (adjusted_sepiaBlue > 255)
            {
                adjusted_sepiaBlue = 255;
            }

            // Set pixel to new sepia colour
            image[h][w].rgbtRed = adjusted_sepiaRed;
            image[h][w].rgbtGreen = adjusted_sepiaGreen;
            image[h][w].rgbtBlue = adjusted_sepiaBlue;
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
