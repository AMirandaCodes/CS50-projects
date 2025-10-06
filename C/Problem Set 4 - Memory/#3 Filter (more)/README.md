# Problem 3: Filter (more)

## Project brief
This exercise implements a set of **image filters** for BMP files by manipulating the RGB values of each pixel. The program works with 24-bit BMPs and applies one of four filters to an input image:

- **Grayscale**: Converts the image into shades of gray by averaging RGB values.
- **Reflection**: Mirrors the image horizontally (like a mirror placed on the right side).
- **Blur**: Softens the image by applying a **box blur**, averaging each pixel with its neighbors.
- **Edges**: Detects and highlights edges using the **Sobel operator**, computing gradients in both x and y directions.

The program must:
- Be implemented in **helpers.c** inside a folder called `filter-more`.
- Preserve the input file format and metadata.
- Correctly manipulate pixel arrays without modifying the provided function signatures.
- Ensure RGB values are capped at 255 when necessary.

## Approach
This problem focuses on **image processing and pixel manipulation**, where the key tasks are:

- Understanding BMP representation (headers + pixel grid).
- Traversing 2D arrays of pixels (`image[height][width]`).
- Applying mathematical formulas for averaging and gradient detection.
- Preserving the integrity of original image data by working with temporary storage when needed.

The skills practiced include:
- Implementing algorithms for grayscale, reflection, blur, and edge detection.
- Using **nested loops** to iterate over images.
- Applying the **Sobel operator** for edge detection (`Gx` and `Gy` kernels).
- Handling edge cases (literally) for borders and corners of the image.

---

## My solution

### Description
The program:
- Reads a BMP image using distribution code.
- Applies the selected filter based on user input.
- Implements the following functions in `helpers.c`:
  - `grayscale`: Averages RGB values to create grayscale.
  - `reflect`: Swaps pixels horizontally in each row.
  - `blur`: Averages neighboring pixels in a 3x3 grid for smoothing.
  - `edges`: Detects edges using Sobel kernels and gradient magnitude.

### How to use it
1. Download the CS50 distribution code and place your `helpers.c` in the `filter-more` folder.
2. Compile with: `make filter`
3. Run the program with:

`./filter -g infile.bmp outfile.bmp   # grayscale`

`./filter -r infile.bmp outfile.bmp   # reflect`

`./filter -b infile.bmp outfile.bmp   # blur`

`./filter -e infile.bmp outfile.bmp   # edges`

5. The output file (`outfile.bmp`) will contain the filtered image.

#### Code snippet
```c
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
```
_(The other filters were coded in Problem 2 Filter (less) )_
