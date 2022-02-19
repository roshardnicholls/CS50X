#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_key(string k);
char substitute(char c, string k);

int main(int argc, string argv[])
{
    // If the user enters 2+ or 0 line arguments, print an error message and stop the program
    if (argc != 2)
    {
        printf("Please enter 1 command-line argument.\n");
        return 1;
    }

    // If the key is invalid, print an error message and stop the program
    bool valid = validate_key(argv[1]);
    if (!valid)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char cipherchar = substitute(plaintext[i], argv[1]);
            printf("%c", cipherchar);
        }

        else
        {
            printf("%c", plaintext[i]);
        }

    }

    printf("\n");

    return 0;
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
                for (int j = i + 1; j < n; j++)
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

char substitute(char c, string k)
{
    char substituted_letter;
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
    int target_position;
    bool target_found = false;
    int counter = 0;

    while (!target_found)
    {
        if (c == upper_alphabet[counter] || c == lower_alphabet[counter])
        {
            target_position = counter;
            target_found = true;
        }

        counter++;
    }

    if (islower(c))
    {
        substituted_letter = tolower(k[target_position]);
    }

    else
    {
        substituted_letter = toupper(k[target_position]);
    }

    return substituted_letter;
}