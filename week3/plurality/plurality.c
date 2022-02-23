#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // If user votes for a valid candidate, return true; else, return false.
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // If there is only one candidate, that candidate is the winner
    if (candidate_count == 1)
    {
        printf("%s\n", candidates[0].name);
    }

    else
    {
        int max_votes = candidates[0].votes;

        // Loop over vote counts and update max_votes if a larger vote count is encountered
        for (int i = 0; i < candidate_count - 1; i++)
        {
            if (max_votes < candidates[i + 1].votes)
            {
                max_votes = candidates[i + 1].votes;
            }
        }

        // Print candidate(s) who have the number of votes equal to max_votes
        for (int i = 0; i < candidate_count; i++)
        {
            if (candidates[i].votes == max_votes)
            {
                printf("%s\n", candidates[i].name);
            }
        }
    }
    return;
}