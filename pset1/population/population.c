#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int init_ppltn;
    do
    {
        init_ppltn = get_int("Please enter the initial population: ");
    }
    while (init_ppltn < 9);

    // TODO: Prompt for end size
    int final_ppltn;
    do
    {
        final_ppltn = get_int("Please enter the final population: ");
    }
    while (final_ppltn < init_ppltn);

    // TODO: Calculate number of years until we reach threshold
    int years_passed = 0;
    int current_ppltn;

    if (final_ppltn == init_ppltn)
    {
        // If the end population is the same as the starting population, stop
        printf("Years: %i\n", years_passed);
    }

    else
    {
        do
        {
            current_ppltn = init_ppltn + (init_ppltn / 3) - (init_ppltn / 4);
            init_ppltn = current_ppltn;
            years_passed++;
        }
        while (current_ppltn < final_ppltn);
        printf("Years: %i\n", years_passed);
    }

}
