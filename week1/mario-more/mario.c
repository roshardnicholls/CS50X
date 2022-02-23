#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Ask user for pyramid height, re-prompt if height is not between 1 and 8
    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1  || height > 8);

    // Create pyramid
    for (int i = 0; i < height; i++)
    {
        int offset = (height - 1) - i;

        // Padding for left pyramid (right-aligned)
        for (int j = 0; j < offset; j++)
        {
            printf(" ");
        }

        // Print the left pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Print the gap between pyramids
        printf("  ");

        // Print the right pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        // Move to the next row
        printf("\n");
    }
}
