# Problem 4: Recover

## Project brief
This exercise implements a **forensic recovery tool** that restores deleted JPEG files from a raw memory card image.  
The program identifies JPEG signatures in 512-byte blocks and reconstructs image files sequentially.  

The program must:
- Be implemented in a file called **recover.c** inside a folder called `recover`.
- Accept exactly **one command-line argument** (the forensic image filename, e.g., `card.raw`).
- Print a usage message and return 1 if:
  - No argument is provided.
  - More than one argument is provided.
- Attempt to open the forensic image for reading:
  - If the file cannot be opened, print an error message and return 1.
- Search through the card in **512-byte blocks** looking for JPEG headers:
  - JPEG signature starts with bytes: `0xff 0xd8 0xff` followed by `0xe0`–`0xef`.
- Each time a JPEG is found:
  - Close the previous file (if open).
  - Create a new file named `###.jpg` where `###` is a zero-padded counter (e.g., `000.jpg`, `001.jpg`, etc.).
- Continue writing blocks to the current JPEG until another signature is found.
- Ensure that no memory leaks occur (program should be leak-free).

## Approach
This problem focuses on **file I/O, buffer management, and data recovery** techniques.  
The skills practiced include:
- Handling **command-line arguments** for input validation.
- Using `fopen`, `fread`, `fwrite`, and `fclose` to manage file streams.
- Recognizing **JPEG signatures** to identify file boundaries.
- Reading and writing data in fixed-size **512-byte blocks**.
- Managing filenames dynamically for recovered images.
- Ensuring proper cleanup of resources (closing files correctly).

---

## My solution

### Description
The program:
- Validates the command-line argument.
- Opens the raw memory card image for reading.
- Reads it in 512-byte blocks into a buffer.
- Detects JPEG signatures and writes out files accordingly.
- Produces sequentially numbered JPEG files until the card is fully read.

### How to use it
1. Navigate to the corresponding folder.
2. Compile with: `make recover`
3. Run the program with: `./recover card.raw`
4. The program will generate recovered images in the same folder, named:
`000.jpg
001.jpg
002.jpg
...
` (In the distribution’s card.raw, you should find 50 images.)

#### Code snippet
```c
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accepts only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");

    // Checks that the file can be opened for reading
    if (card == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    // Buffer information copied over
    uint8_t buffer[512];
    // Filename
    char filename[8];
    // JPEGs found so far
    int count = 0;

    // Current output JPEG
    FILE *img = NULL;

    // While there are still blocks left to read
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If already writing to a file, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new filename
            sprintf(filename, "%03i.jpg", count);
            count++;

            // Open new JPEG file
            img = fopen(filename, "w");
        }

        // Write to the current JPEG if one is open
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close the last image if open
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
}

```
