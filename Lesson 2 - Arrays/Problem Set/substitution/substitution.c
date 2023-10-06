#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isAlphabet(string s);
bool checkDuplicate(string alphabet);

    int main(int argc, string argv[])
{
    if (argc != 2 || !isAlphabet(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    } else if (!checkDuplicate(argv[1])) {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    string alphabet = argv[1];

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
}

bool checkDuplicate(string alphabet)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (alphabet[i] == alphabet[j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isAlphabet(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}