#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[1024];

    for (int i = 0; i < 1024; i++)
    {
        // scores[i] = i;
        printf("%d\n", scores[i]);
    }

    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 13;

    y = x;
    *y = 13;
    
}