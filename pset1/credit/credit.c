#include <stdio.h>
#include <cs50.h>

char validate_card(long card_number);

int main(void)
{
    // Ask user for card number
    long card_number = get_long("Enter the card number: ");


    validate_card(card_number);
}

// check if the number the user entered is a valid credit card number
char validate_card(long card_number)
{
    int current_digit = 0;
    int card_length = 0;
    int luhn_part1 = 0;
    int luhn_part2 = 0;
    int luhn_total = 0;
    // Loop over the card number starting from the end
    while (card_number != 0)
    {
        current_digit = card_number % 10;
        card_length++;

        // Implementing Luhn's Algorithm
         // Sum of doubled digits

        // Every other digit starting from second to last
        if (card_length % 2 == 0)
        {
            current_digit *= 2;
            if (current_digit >= 10)
            {
                luhn_part2 += (current_digit / 10) + (current_digit % 10);
            }
            else
            {
                luhn_part2 += current_digit;
            }
        }
        else
        {
            luhn_part1 += current_digit;
        }
        // printf("%i\n", current_digit);

        // Remove the last digit so that we can use the next digit on following loop
        card_number /= 10;
    }
    // printf("Luhn Part 1: %i\n", luhn_part1);
    // printf("Luhn Part 2: %i\n", luhn_part2);

    luhn_total = luhn_part1 + luhn_part2;
    if (luhn_total % 10 == 0
      && (card_length == 13 || card_length == 15 || card_length == 16))
    {
        printf("Valid");
    }
    else
    {
        printf("INVALID\n");
    }
}