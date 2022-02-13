#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_key(key);
// char substitute(char c, string k);

int main(int argc, string argv[])
{
    // If the user enters 2+ or 0 line arguments, print an error message and stop the program
    if (argc != 2)
    {
        printf("Please enter 1 command-line argument.\n");
        return 1;
    }

    bool valid = validate_key(argv[1]);
    if (!valid)
    {
        return 1;
    }
}

bool validate_key(string k)
{
    int n = strlen(k);
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!isalpha(k[i]))
            {
                printf("Key must contain letters only.\n");
                return false;
            }

            else
            {
                for (int j = i; j < n; j++)
                {
                    if (k[j] == k[i])
                    {
                        printf("Key must contain non-repeating characters.\n");
                        return false;
                    }
                }
            }
        }
    }

    return true;
}