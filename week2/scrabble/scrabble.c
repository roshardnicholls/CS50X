#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("Score 1: %i\n", score1);
    printf("Score 2: %i\n", score2);
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    n = strlen(word);
    int letter_index;
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        if (islower(word[i]))
        {
            letter_index = word[i] - 97;
            score += POINTS[letter_index];
        }

        else (isupper(word[i]))
        {
            letter_index = word[i] - 65;
            score += POINTS[letter_index];
        }
    }

    return score;
}
