#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*  int x;
     printf("Enter a number: ");
     scanf("%i", &x);

     printf("You entered %i\n", x); */

    char *s = malloc(4);

    printf("Enter a string: ");

    scanf("%s", s);
    printf("You entered %s\n", s);
    free(s);
}