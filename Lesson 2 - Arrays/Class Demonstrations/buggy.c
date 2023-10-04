#include <stdio.h>
#include <cs50.h>

void print_column(int heigth);

int main(void)
{
    int h = get_int("Heigth: ");
    print_column(h);
}

void print_column(int heigth)
{
    for (int i = 0; i < heigth; i++)
    {
        printf("#\n");
    }
}