#include <stdio.h>
#include <cs50.h>

#define ARRAYLENGTH 10
int numbers[ARRAYLENGTH] = {
    97,
    82,
    85,
    90,
    105,
    82,
    97,
    85,
    107,
    66,
};
void sort_array();

int main(void)
{

    sort_array();
    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        printf("%i\n", numbers[i]);
    }
}

void sort_array()
{
    int temp;

    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        temp = i;
        for (int j = i; j < ARRAYLENGTH; j++)
        {
            if (numbers[j] > numbers[temp])
            {
                temp = j;
            }
        }
        int swap = numbers[i];
        if (temp != i)
        {
            numbers[i] = numbers[temp];
            numbers[temp] = swap;
        }
    }
}