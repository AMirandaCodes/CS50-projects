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

    // Checks that the file can be opnened for reading
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
        // Create JPEGs from the data
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
