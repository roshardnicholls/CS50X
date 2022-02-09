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
    L = count_letters(text);
    W = count_words(text);
    S = count_sentences(text);
    printf("%i letters", L);
    printf("%i word", W);
    printf("%i sentences", S);
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text), i++)
    {
        if (isalnum(text[i])
        {
            letters++
        }
    }
    return letters
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text), i++)
    {
        if (isspace(text[i])
        {
            words++
        }
    }
    return words
}

int sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text), i++)
    {
        if (text[i] == "." || text[i] == "!" || text[i] == "?")
        {
            sentences++
        }
    }
    return sentences
}