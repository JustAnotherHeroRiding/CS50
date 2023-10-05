#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string encode(string plaintext, int key, char *lowercase, char *uppercase);
bool isNonNegativeInteger(string str);

int main(int argc, string argv[])
{
    if (argc != 2 || !isNonNegativeInteger(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // If you reach this point, argv[1] is a valid non-negative integer
    int key = atoi(argv[1]);
    key = key % 26;
    // Your program logic here
    // printf("%i\n", key);

    char lowercase[27];
    char uppercase[27];
    int x;

    for (x = 0; x < 26; x++)
    {
        lowercase[x] = 'a' + x;
        uppercase[x] = 'A' + x;
    }

    lowercase[x] = '\0'; // null terminate the array
    uppercase[x] = '\0';

    // printf("%s \n %s", lowercase, uppercase);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: %s", encode(plaintext, key, lowercase, uppercase));
    printf("\n");
    return 0;
}

string encode(string plaintext, int key, char *lowercase, char *uppercase)
{
    int length = strlen(plaintext);
    char *cipher = malloc(length + 1); // +1 for the null terminator
    // printf("%s \n %s", lowercase, uppercase);
    if (cipher == NULL)
    {
        // Handle memory allocation error
        return NULL;
    }

    for (int i = 0; i < length; i++)
    {
        int index = (i + key) % 26;
        if (isalpha(plaintext[i]))
        {

            if (islower(plaintext[i]))
            {

                cipher[i] = lowercase[index];
            }
            else
            {
                cipher[i] = uppercase[index];            }
        }
    }

    cipher[length] = '\0'; // Null-terminate the cipher string

    return cipher;
}
bool isNonNegativeInteger(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false; // Not a digit
        }
    }

    int num = atoi(str);
    return num >= 0; // Check if it's non-negative
}
