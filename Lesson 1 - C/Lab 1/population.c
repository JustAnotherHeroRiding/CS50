#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;

    do
    {
        start_size = get_int("Start Size: ");
    } while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {

        end_size = get_int("End Size: ");
    } while (end_size < start_size);
    // TODO: Calculate number of years until we reach threshold

    // Every year start_size / 3 llamas are born and start_size / 4 llamas will die
    float born;
    float killed;
    int years = 0;
    int population = start_size;

    for (int i = 1; population < end_size; i++)
    {
        born = population / 3;
        killed = population / 4;
        population = population + born - killed;
        printf("Current size: %i, born: %f, killed: %f\n", population, born, killed);
        years = i;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
