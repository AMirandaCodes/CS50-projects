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
