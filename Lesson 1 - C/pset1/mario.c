#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height ");
    } while (height > 8 || height < 1);
    // Only accepts numbers between 1 and 8
    // The do while loop with run again if the number is higher than 8 and lower than 1

    // First loop will loop for each row that we should print
    for (int i = 1; i <= height; i++)
    {   
        // This will print the spaces as we start with 1 hash and increase
        // This needs to be in centered
        for (int j = height; j > i; j--)
        // On the first row, if the height is 5
        // j will be 5 and will print 5 spaces
        // i will be 1
        {
            printf("%s", " ");
        }
        // Here we print the first hash block
        // Once again on the first row J is one
        // if i is 1, we will print 1 hash
        // if i is 2, we will print 2 hashes
        for (int j = 1; j <= i; j++)
        {
            printf("%s", "#");
        }
        // Two spaces in the middle
        printf("  ");
        // Second hash block
        for (int j = 1; j <= i; j++)
        {
            printf("%s", "#");
        }

        printf("\n");
    }
}