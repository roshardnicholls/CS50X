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

    for (int i = 0; i < height; i++)
    {
        printf("#\n");
    }
}