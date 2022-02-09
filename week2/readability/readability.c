#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int L = count_letters(text);
    float W = (count_words(text) / 1.0);
    int S = count_sentences(text);
    // printf("%i letters\n", L);
    // printf("%i words\n", W);
    // printf("%i sentences\n", S);
    float letter_avg = (L/W) * 100;
    float sentence_avg = (S/W) * 100;
    float index = 0.0588 * letter_avg - 0.296 * sentence_avg - 15.8;
    printf("%.4f\n", index);
}

int count_letters(string text)
{
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

    if (n == 0)
    {
        return words;
    }

    else
    {
        words = 1;
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