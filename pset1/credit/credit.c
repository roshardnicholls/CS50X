#include <stdio.h>
#include <cs50.h>

char validate_card(long card_number);
void classify_card(long card_number);

int main(void)
{
    // Ask user for card number
    long card_number = get_long("Enter the card number: ");

    // Validate whether number entered is (syntactically) valid
    char card_status = validate_card(card_number);

    // If number is potentially valid, try and determine type of card, else number is invalid
    if (card_status == 'V')
    {
        classify_card(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Check if the number the user entered is a valid credit card number
char validate_card(long card_number)
{
    int current_digit = 0;
    int card_length = 0;
    int luhn_part1 = 0;
    int luhn_part2 = 0;
    int luhn_total = 0;

    /* Loop over the card number starting from the end
    and implement Luhn's Algorithm
    */
    while (card_number != 0)
    {
        current_digit = card_number % 10;
        card_length++;

        // Every other digit starting from second to last gets doubled
        if (card_length % 2 == 0)
        {
            current_digit *= 2;

            // Add the products' digits together into one partial sum
            if (current_digit >= 10)
            {
                luhn_part2 += (current_digit / 10) + (current_digit % 10);
            }
            else
            {
                luhn_part2 += current_digit;
            }
        }

        // Add the digits that were not doubled together into another partial sum
        else
        {
            luhn_part1 += current_digit;
        }

        // Remove the last digit so that we can use the next digit on the following loop
        card_number /= 10;
    }

    luhn_total = luhn_part1 + luhn_part2; // Add the partial sums together

    /* A number is potentially valid if the total's last digit is 0
    and the card length is either 13, 15, or 16; else it's invalid */
    if (luhn_total % 10 == 0 && (card_length == 13 || card_length == 15 || card_length == 16))
    {
        return 'V'; // Card number is (potentially) valid
    }
    else
    {
        return 'I'; // Card number is invalid
    }
}

void classify_card(long card_number)
{
    // Divide number by 10 until only first two digits remain
    do
    {
        card_number /= 10;
    }
    while (card_number > 99);

    if (card_number >= 40 && card_number <= 49)
    {
        printf("VISA\n");
    }
    else if (card_number >= 51 && card_number <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (card_number == 34 || card_number == 37)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}