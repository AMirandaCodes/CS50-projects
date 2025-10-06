# Problem 3: Mario (less)

## Project brief
In this exercise, the goal is to recreate a half-pyramid structure similar to the one seen in Super Mario Bros., using hashes (#) for bricks. The program should prompt the user for the pyramid’s height and then output a right-aligned pyramid of that size.

For example, if the user inputs 4, a half-pyramid 4-blocks high is printed:

       #
      ##
     ###
    ####

## Approach
This problem focuses on practicing loops, nested iteration, and input validation in C. The key skills I’m developing here are:
- Using get_int from cs50.h to obtain valid integer input.
- Implementing input validation by re-prompting until the user enters a positive integer within the allowed range.
- Applying nested for loops to build each row of the pyramid: one loop for spaces and another for hashes.
- Using printf formatting to align text output correctly.

## My solution

### Description
The program:
- Prompts the user to enter the pyramid’s height (must be a positive integer).
- Validates the input, asking again if the user enters invalid data.
- Prints a half-pyramid of the given height, aligned to the right.
- Uses # to represent blocks, with the bottom row matching the input height. 

### How to Use It
1. Make sure you have the CS50 library installed.
2. Navigate to the corresponding folder.
3. Compile the program with: *make mario*
4. Run the program with: *./mario*
5. Enter the desired pyramid height when prompted.

#### Code Snippet
```c
#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);
void print_spaces(int spaces);

int main(void)
{
    // Ask the user about the pyramid's height
    int height;
    do
    {
        height = get_int("Pyramid's height: ");
    }
    while (height < 1);

    // Print the pyramid
    for (int i = 0; i < height; i++)
    {
        print_spaces(height - i - 1);
        print_row(i + 1);
    }
}
// Prints spaces
void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

// Prints hashes
void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
