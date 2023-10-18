#include <stdio.h>
#include <cs50.h>

/* int main(void)
{
    int n = 50;
    int *p = &n;
    //printf("%i\n", n);
    printf("%p\n", p);
    printf("%i\n", *p);
} */

int main(void)
{ /*
string s = "HI!";
printf("String array address: %p\n", s);
printf("First char: %p\n", &s[0]);
printf("Second char: %p\n", &s[1]);
printf("Third char: %p\n", &s[2]);
printf("Fourth char: %p\n", &s[3]);
*/
    // string s = "HI!";
    //  This is the same thing and what string is
    //  The double quotes are interpreted as an &
    //  Which means that what is saved in s is the address
    //  Printing a string is a for loop that will print the char
    //  stored at the dress, which is 'H', and keep going
    //  until the null terminator "/0" is reached
    char *s = "HI!";
    // printf("%s\n", s);

    // printf("%c", s[0]);
    // printf("%c", s[1]);
    // printf("%c\n", s[2]);
    printf("%c", *s);
    printf("%c", *(s + 1));
    printf("%c\n", *(s + 2));
}