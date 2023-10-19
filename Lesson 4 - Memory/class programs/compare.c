#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /* int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    } */

    char *s = get_string("s: ");
    char *t = get_string("t: ");
    // This will not work as it compares
    // the adress of the first char of the string
    // if (s == t)

    printf("%p\n", s);
    printf("%p\n", t);
    /* if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    } */
}