#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Display error message if user enters 0 or 2+ command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Display error message if key contains non-digit characters
    bool key_check = only_digits(argv[1]);
    if (!key_check)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key from a string to an int
    int key = atoi(argv[1]);

    string text = get_string("plaintext: ");

    // Call the rotate function to rotate each alphabetical character by "key"
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char cipherchar = rotate(text[i], key);
        printf("%c", cipherchar);
    }

    printf("\n");
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

        // If the character is not a digit, immediately return false
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

    // Only rotate alphabetical characters
    if(isalpha(c))
    {
        // Shift the character by n using ASCII values and return the rotated letter
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