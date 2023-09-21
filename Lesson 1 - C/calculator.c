#include <stdio.h>
#include <cs50.h>

int add(int x, int y);

/* int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

     int z = add(x, y);

    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
} */

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    double z = (double)x / (double)y;

    printf("%.25f\n", z);
}