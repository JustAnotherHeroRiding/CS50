#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    //printf("%i\n", key);


    string plaintext = get_string("plaintext: ");
    string ciphertext;
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
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
