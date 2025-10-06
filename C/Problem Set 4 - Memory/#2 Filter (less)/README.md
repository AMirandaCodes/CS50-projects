# Problem 2: Filter (less)

## Project brief
This exercise implements **image filters** by manipulating the RGB values of pixels in a bitmap (BMP).  
The program reads a BMP file, processes each pixel, and outputs a new BMP with a chosen filter applied.  

The filters supported are:
- **Grayscale** → converts the image to black and white.
- **Sepia** → gives the image a reddish-brown vintage effect.
- **Reflect** → mirrors the image horizontally.
- **Blur** → softens the image by averaging surrounding pixels.

The program must:
- Compile with `make filter`.
- Be run with a command specifying the filter (`-g`, `-s`, `-r`, `-b`).
- Accept an input BMP and produce an output BMP.
- Modify pixel values correctly according to the chosen filter.

## Approach
This problem focuses on **image manipulation, 2D arrays, and struct usage in C**.  

The skills practiced include:
- Working with **structs** (`RGBTRIPLE`) that store pixel data.
- Traversing **2D arrays** (rows and columns of pixels).
- Performing **mathematical transformations** (averaging, weighted sums).
- Handling **edge cases** (rounding values, capping at 255).
- Understanding **file formats** (BMP headers, image data).

---

## My solution

### Description
The program:
- Loads the BMP file into memory.
- Calls the filter function chosen by the user:
  - **grayscale:** average R, G, B values.
  - **sepia:** apply weighted formula, cap values at 255.
  - **reflect:** swap pixels horizontally across the center.
  - **blur:** average each pixel’s value with its neighbors.
- Outputs a new BMP file with the transformed image.

### How to use it
1. Make sure you have the CS50 library and distribution files (`filter.c`, `helpers.c`, `helpers.h`, `bmp.h`, `Makefile`).
2. Navigate to the corresponding folder.
3. Compile with: `make filter`.
4. Run the program with a filter option and file paths: `./filter -g images/yard.bmp out.bmp`

Options:
- -g → grayscale
- -s → sepia
- -r → reflect
- -b → blur

#### Code snippet
```c
// Grayscale filter
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int average = round((red + green + blue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}
```
_(Full implementation in helpers.c)_
