# Problem 4: Mario (more)

## Project brief
This exercise recreates the famous double pyramid structure from Super Mario Bros., where Mario hops over adjacent pyramids of blocks. The program asks the user for the pyramid’s height and prints two side-by-side pyramids with a gap of two spaces between them.

## Approach
This problem emphasises:
- Input validation: re-prompting the user until they enter a positive integer between 1 and 8.
- Nested loops: printing spaces, hashes, and the fixed two-space gap.
- Formatting alignment: ensuring both pyramids grow evenly and symmetrically.
- Practicing iteration control to handle multiple conditions in one row (spaces + left pyramid + gap + right pyramid).

## My solution

### Description
The program:
- Prompts the user to enter an integer height between 1 and 8.
- Rejects invalid input and asks again until the user provides a valid number.
- Prints two adjacent pyramids of the specified height, separated by a gap of two spaces.
- Each row contains the correct number of leading spaces, hashes, and aligned pyramids

### How to use it
1. Make sure you have the CS50 library installed.
2. Navigate to the corresponding folder.
3. Compile with: *make mario*
4. Run the program: *./mario*
5. Enter a number between 1 and 8 to generate the pyramid.

#### Code Snippet
```c
#include <cs50.h>
#include <stdio.h>

void print_left_spaces(int left_spaces);
void print_left_pyramid(int left_bricks);
void print_gap(int gap);
void print_right_pyramid(int right_pyramid);

int main(void)
{
    // Ask user for the height
    int height;
    do
    {
        height = get_int("What is the height?\n");
    }
    while (height < 1 || height > 8);

    // Print pyramids and spaces
    for (int i = 0; i < height; i++)
    {
        print_left_spaces(height - i - 1);
        print_left_pyramid(i + 1);
        print_gap(2);
        print_right_pyramid(i + 1);
    }
}
// Prints spaces to the left
void print_left_spaces(int left_spaces)
{
    for (int i = 0; i < left_spaces; i++)
    {
        printf(" ");
    }
}
// Prints bricks to the left
void print_left_pyramid(int left_bricks)
{
    for (int i = 0; i < left_bricks; i++)
    {
        printf("#");
    }
}
// Prints gap (which should is two spaces)
void print_gap(int gap)
{
    for (int i = 0; i < gap; i++)
    {
        printf(" ");
    }
}
// Prints bricks to the right
void print_right_pyramid(int right_pyramid)
{
    for (int i = 0; i < right_pyramid; i++)
    {
        printf("#");
    }
    printf("\n");
}

```
