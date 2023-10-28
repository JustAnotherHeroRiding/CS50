// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table

FILE *dictFile;
unsigned int dictLength = 0;

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    // printf("%d\n", index);
    node *cursor = table[index];
    while (cursor != NULL)
    {

        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    dictFile = fopen(dictionary, "r");
    if (dictFile == NULL)
    {
        return false;
    }
    char c;
    // Prepare to spell-check
    int index = 0;
    char word[LENGTH + 1];

    while (fread(&c, sizeof(char), 1, dictFile))
    {
        // Allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // Append character to word
            word[index] = c;
            index++;

            // Ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // Consume remainder of alphabetical string
                while (fread(&c, sizeof(char), 1, dictFile) && isalpha(c))
                    ;

                // Prepare for new word
                index = 0;
            }
        }

        // Ignore words with numbers (like MS Word can)
        else if (isdigit(c))
        {
            // Consume remainder of alphanumeric string
            while (fread(&c, sizeof(char), 1, dictFile) && isalnum(c))
                ;

            // Prepare for new word
            index = 0;
        }

        // We must have found a whole word
        else if (index > 0)
        {
            // Terminate current word
            word[index] = '\0';
            if (table[hash(word)])
            {
                node *cursor = table[hash(word)];
                while (cursor->next != NULL)
                {
                    cursor = cursor->next;
                }
                cursor->next = malloc(sizeof(node));
                if (cursor->next == NULL)
                {
                    return false;
                }
                strcpy(cursor->next->word, word);
                cursor->next->next = NULL;
            }
            else
            {

                table[hash(word)] = malloc(sizeof(node));
                strcpy(table[hash(word)]->word, word);
                table[hash(word)]->next = NULL;
            }

            // Prepare for next word
            index = 0;
        }
    }
    // Here we need to store all the words into the hash table
    // Our initial hash table will consist of 26 buckets for each letter
    // Each node of the linked list will consist of separate linked lists
    // for the table[2] bucket, the first element will be a node containing (cat, pointer to caterpillar node)
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    rewind(dictFile);
    int c;
    unsigned int lines = 0;

    while ((c = fgetc(dictFile)) != EOF)
    {
        // printf("%c", c);
        if (c == '\n') // Increment count if this character is newline
            lines++;
    }
    // printf("%d\n", lines);
    return lines;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    fclose(dictFile);
    return true;
}
