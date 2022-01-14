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
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Move to the next row
        printf("\n");
    }
}