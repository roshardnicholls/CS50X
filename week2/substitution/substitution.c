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

    // If the key is invalid, stop the program
    // Error messages are handled by the validate_key function
    bool valid = validate_key(argv[1]);
    if (!valid)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Substitute each alphabetic char with the corresponding char in the key
        if (isalpha(plaintext[i]))
        {
            char cipherchar = substitute(plaintext[i], argv[1]);
            printf("%c", cipherchar);
        }

        // Leave non-alphabetic characters unchanged
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

    // Reject all keys that are not 26 chars
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            // Reject all keys that contain non-alphabetic chars
            if (!isalpha(k[i]))
            {
                printf("Key must contain letters only.\n");
                return false;
            }

            else
            {
                for (int j = i + 1; j < n; j++)
                {
                    // Reject all keys that contain repeating chars
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

    // Avoid case conversions later by declaring both uppercase and lowercase alphabets as strings
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";

    int target_position; // Used to match position of original snad substituted chars
    bool target_found = false;
    int counter = 0;

    while (!target_found)
    {
        // Once original char's position is found, set target_found to true and break out of the loop
        if (c == upper_alphabet[counter] || c == lower_alphabet[counter])
        {
            target_position = counter;
            target_found = true;
        }
        counter++;
    }

    // Convert the char in key to corresponding case of the original char
    // Return the substituted letter
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