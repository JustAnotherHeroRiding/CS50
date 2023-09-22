#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*  for (int i = 0; i < 4; i++)
     {
         printf("?");
     }
     printf("\n"); */

    /*  for (int i = 1; i < 10; i++)
     {
         printf("#");
         if (i % 3 == 0){
             printf("\n");
         }
     } */
    /*  int n = get_int("Size: ");

     while (n < 1)
     {
         n = get_int("Please enter a positive number: ");
     } */

    // Prompt user for positive integer
    int n;
    do
    {
        n = get_int("Size: ");
    } while (n < 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}