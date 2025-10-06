# Problem 1: Volume  

## Project brief  
This exercise works with **WAV audio files** by modifying their **volume**. WAV files contain a 44-byte header followed by audio samples (16-bit signed integers). By multiplying each sample by a **scaling factor**, the program increases or decreases the loudness of the audio.  

The program must:  
- Accept **three command-line arguments**:  
  1. `input.wav` – original file.  
  2. `output.wav` – new file to be created.  
  3. `factor` – floating-point number by which to scale volume.  
- Validate that the correct number of arguments is given.  
- Copy the **44-byte header** from input to output unchanged.  
- Read each sample (16-bit integer), scale it by `factor`, and write it to the output file.  
- Close all opened files properly.  

## Approach
This problem introduces low-level file I/O and binary data manipulation in C. The key concepts and skills practiced are:
- Reading and writing binary files with `fread` and `fwrite`.
- Working with precise integer types (`uint8_t` for header bytes, `int16_t` for samples).
- Understanding WAV file structure (fixed 44-byte header + samples).
- Command-line argument validation.
- Preventing resource leaks by properly closing files.

---

## My solution

### Description
The program:
- Validates that exactly three command-line arguments are provided.
- Opens the input and output files safely, exiting if an error occurs.
- Reads the header from the input and writes it directly to the output.
- Iterates over each 16-bit sample, multiplies it by factor, and writes the result.
- Closes both files at the end.

### How to use it
1. Navigate to the volume folder.
2. Compile with: `make volume`
3. Run with: `./volume input.wav output.wav factor` . Replace factor with a positive float (e.g., 0.5 to halve volume, 2.0 to double it).

#### Code snippet
```c
// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Create a buffer for a single sample
    int16_t buffer;

    // Read every single sample until there are no more
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Update volume of sample
        buffer *= factor;

        // Write the updated sample into new file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

```
