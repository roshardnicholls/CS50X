#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1  || height > 8);

    printf("Height = %i\n", height);
}