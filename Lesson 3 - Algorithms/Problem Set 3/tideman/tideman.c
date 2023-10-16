#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int voter_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {

        if (strcasecmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // This is called in a for loop above for each voter so no need to loop over the voters here
    // It is called with the ranks array where ranks[i] is the voter's ith preference
    // This means ranks[0] is the first preference, ranks[1] is the second preference, etc.

    // This function updates the global preferences array to add the current voter's preferences
    // preferences[i][j] is number of voters who prefer i over j
    // Each voter will rank each candidate

    // If we have 2 candidates Alice and Bob
    // If we have 2 voters, both rank Alice as first and Bob as second
    // Then the ranks for the first voter will be [0, 1]
    // The ranks for the second voter will be [0, 1] as he voted the same way

    // Then this function will be called each voter

    // For the first voter we need to update the preferences array using the two votes
    // This means that preferences[0][1] will be incremented by 1

    // The second voter will also update preferences[0][1] by 1 as he voted the same way

    // The result at the end is that preferences[0][1] will be 2
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }

        // printf("Candidate: %s\n", candidates[i]);
        // printf("Candidate preference: %i over %s\n", preferences[i][ranks[i + 1]], candidates[ranks[i + 1]]);
        // printf("Candidate rank %i\n", ranks[i]);
    }

    // printf("Final preference for %s over %s: %i", candidates[0], candidates[1], preferences[0][1]);
    //  TODO
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
                // printf("Added pairs %s over %s\n", candidates[i], candidates[j]);
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
                // printf("Added pairs %s over %s\n", candidates[j], candidates[i]);
            }
        }
    }
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Here we need to sort each pairs but i need to visualize them as I am not sure how to do this
    // In the previous function we have a struct
    for (int i = 0; i < pair_count; i++)
    {
        //printf("%s has %i votes,  %s has %i votes\n", candidates[pairs[i].winner], preferences[pairs[i].winner][pairs[i].loser], 
        //candidates[pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);
        int difference = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        for (int j = i + 1; j < pair_count; j++)
        {
            if (difference < preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner])
            {
                pair temp = pairs[j];
                pairs[j] = pairs[i];
                pairs[i] = temp;
            }
        }
    }
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{


    // This loop will look in all the pairs but it won't check if there is a cycle
    // How can we detect if locking in a pair will create a cycle?
    // We have to somehow check the locked array
    // How can we detect if a cycle is created in the locked in array?
    for (int i = 0; i < pair_count; i++) {
        printf("Winner: %s, Loser: %s\n", candidates[pairs[i].winner], candidates[pairs[i].loser]);
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}