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

// Choose number of buckets in hash table
const unsigned int N = 150000;

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
    return false;
}

// Hashes word to a number
/* unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // Let's also try a hash using the sum of ascii value
    unsigned int asciiSum = 0;
    for (int i = 0; word[i] != '\0';i++) {
        asciiSum += (int) word[i];
    }
    return asciiSum % N;
} */

#define BASE 256

unsigned int hash(const char *word)
{
    unsigned int hashValue = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hashValue = (hashValue * BASE + word[i]) % N;
    }
    return hashValue;

    /*  unsigned long hash = N;
     int c;

     while ((c = *word++))
         hash = ((hash << 5) + hash) + c;
         // hash * 33 + c

     return hash;  */
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
    // unsigned int bucketIndex = 0;
    char c;
    // Prepare to spell-check
    int index = 0;
    char word[LENGTH + 1];

    // This is the way words are read in speller.c, but perhaps fscan(file, %s, word) will be much quicker
    // If fcanf returns EOF it means that the end of the file has been reached

    // I have now started inserting the words at the begining of the linked list instead of at the end
    // The speed is the same as the speller50 with 0.03 seconds
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
            unsigned int hashedValue = hash(word);
            // printf("Hashed index %u\n", hashedValue);

            // Let's try and insert the words at the beginning of the linked list instead of at the ends
            if (table[hash(word)])
            {
                // If there is already a node in the linked list at the hash index
                // We create a cursor to it and a tmp copy
                node *cursor = table[hash(word)];
                node *tmp = cursor;

                // Here we create the new node that we are about to add
                node *new = malloc(sizeof(node));
                // Copying the word
                strcpy(new->word, word);
                // Setting the next pointer to NULL
                new->next = NULL;
                // setting the cursor to the new nodes
                // This is setting the pointer to the first node to be the pointer to the new node
                cursor = new;
                // The second element is then the tmp, which was the initial first element
                cursor->next = tmp;
                // Finally we add it to the hash table
                table[hash(word)] = cursor;
            }
            else
            {
                // bucketIndex++;
                // printf("Found a word! %u", bucketIndex);

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
