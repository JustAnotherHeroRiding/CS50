#include <stdio.h>
#include <cs50.h>
const int N = 3;

float average(int length, int array[]);

int main(void)
{
    /* int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average %f\n", (score1 + score2 + score3) / 3.0 ); */

    /*  scores[0] = get_int("Score 1: ");
     scores[1] = get_int("Score 2: ");
     scores[2] = get_int("Score 3: "); */

    int scores[N];

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average %f\n", average(N, scores));
    return 0;
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float)length;
}