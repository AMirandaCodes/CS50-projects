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
