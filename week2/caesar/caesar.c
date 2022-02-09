#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    bool key_check = only_digits(argv[1]);

    if (!key_check)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string text = get_string("plaintext: ");
    char cipherchar = rotate(text[0], key);
    printf("%c\n", cipherchar);
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

char rotate(char c, int n)
{
    char rotated_letter;
    if(isalpha(c))
    {
        if(islower(c))
        {
            rotated_letter = ((((c - 97) + n) % 26) + 97);
            return (char) rotated_letter;
        }

        else
        {
            rotated_letter = ((((c - 65) + n) % 26) + 65);
            return (char) rotated_letter;
        }
    }
    return c;
}