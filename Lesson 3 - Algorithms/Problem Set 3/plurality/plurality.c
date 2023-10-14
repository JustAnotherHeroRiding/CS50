#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

candidate winners[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void sort_winners(int length);

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
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(candidates[i].name, name) == 0)
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
    int winnersCount = 1;

    int winner = 0;
    bool singleWinner = false;
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("%s with %i votes:\n", candidates[i].name, candidates[i].votes);

        if (candidates[i].votes >= winner)
        {
            winners[winnersCount - 1] = candidates[i];
            winner = candidates[i].votes;
            winnersCount++;
        }
    }
    // TODO
    sort_winners(winnersCount - 1);
    if ((winnersCount > 1) && (winners[0].votes != winners[1].votes))
    {
        printf("%s\n", winners[0].name);
    }
    else
    {
        for (int i = 0; i < winnersCount - 1; i++)
        {
            printf("%s\n", winners[i].name);

            // /printf("Votes: %i\n", winners[i].votes);
        }
    }
}

void sort_winners(int length)
{
    bool sorting = true;
    while (sorting)
    {
        sorting = false; // Assume the array is sorted
        for (int i = 0; i < length - 1; i++)
        {
            // Swap adjacent elements if they are in the wrong order
            if (winners[i].votes < winners[i + 1].votes)
            {
                candidate swap = winners[i];
                winners[i] = winners[i + 1];
                winners[i + 1] = swap;
                sorting = true; // If a swap happened, the array might not be sorted yet
            }
        }
    }
}