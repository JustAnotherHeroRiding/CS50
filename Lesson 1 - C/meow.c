#include <stdio.h>

/* While loop */
/* int main(void)
{
    int i = 0;

    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
} */

void meow(int n);

int main(void)
{
    meow(10);
}
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}