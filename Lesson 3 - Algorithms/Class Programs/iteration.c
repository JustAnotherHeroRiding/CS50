#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int heigth = get_int("Height: ");
    draw(heigth);
}

void draw(int n)
{
    /*  for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < i + 1; j++)
         {

             printf("#");
         }
         printf("\n");
     } */

    // If nothing to draw
    if (n <= 0)
    {
        return;
    }
    
    // Pring Pyramid of height n - 1
    draw(n - 1);
    // Print one more row

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}