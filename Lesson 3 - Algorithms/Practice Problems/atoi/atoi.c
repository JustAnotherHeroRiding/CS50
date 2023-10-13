#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int result = (int)input[strlen(input) - 1];
    // TODO
    if (strlen(input) > 1)
    {
        input[strlen(input) - 1] = '\0'; // Set the last character to null terminator
        result += convert(input);        // Recursively call the function with the shortened string
    }
    return result;
}