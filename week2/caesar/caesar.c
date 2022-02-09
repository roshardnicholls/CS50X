#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    bool key_check = only_digits(argv[1]);

    if (!(key_check))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if(isdigit(s[i]))
        {
            continue;
        }

        else
        {
            return false;
        }
    }

    return true;
}