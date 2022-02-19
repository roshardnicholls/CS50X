#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for text, then compute the number of letters, words, and sentences.
    string text = get_string("Text: ");
    int L = count_letters(text);
    float W = (count_words(text) / 1.0); // Type float used so that averages are calulated as floats
    int S = count_sentences(text);

    // Compute the Coleman-Liau index
    float letter_avg = (L / W) * 100;
    float sentence_avg = (S / W) * 100;
    float index = (0.0588 * letter_avg) - (0.296 * sentence_avg) - 15.8;

    // Assign the index to an equivalent grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 15.5)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    // Count the number of letters in the text, return that number
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalnum(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    int n = strlen(text);

    // If the string is empty, no counting needed, words = 0
    if (n == 0)
    {
        return words;
    }

    else
    {
        // If the string is not empty, then there is at least one word
        words = 1;

        // Count the number of words and return that number
        for (int i = 0; i < n; i++)
        {
            if (isspace(text[i]))
            {
                words++;
            }
        }
        return words;
    }
}

int count_sentences(string text)
{
    // Count the number of sentences and return that number
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}