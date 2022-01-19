#include <stdio.h>
#include <cs50.h>

void validate_card(long card_number);

int main(void)
{
    // Ask user for card number
    long card_number = get_long("Enter the card number: ");


    validate_card(card_number);
}

// check if the number the user entered is a valid credit card number
void validate_card(long card_number)
{
    int current_digit = 0;
    while (card_number != 0)
    {
        current_digit = card_number % 10;
        printf("%i\n", current_digit);
        card_number /= 10;
    }