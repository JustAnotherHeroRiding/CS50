// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// const char VOWELS[] = {'a', 'e', 'i', 'o', 'u'};

string replace(string s);

int main(int argc, string argv[])
{
    // int length = sizeof(VOWELS) / sizeof(VOWELS[0]);

    if (argc != 2)
    {
        if (argc > 2)
        {
            printf("Please enter only one argument\n");
        }
        else if (argc == 0)
        {
            printf("Please enter an argument\n");
        }

        return 1;
    }

    printf("%s\n", replace(argv[1]));
}

string replace(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        switch (toupper(s[i]))
        {
        case 'A':
            s[i] = '6';
            break;

        case 'E':
            s[i] = '3';
            break;
        case 'I':
            s[i] = '1';
            break;
        case 'O':
            s[i] = '0';
            break;

        default:
            break;
        }
    }

    return s;
}
