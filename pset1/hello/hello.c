#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Greet user
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}