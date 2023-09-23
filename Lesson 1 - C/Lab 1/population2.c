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
    int years = 0;
    int population = start_size;

    while (population < end_size)
    {
        int born = population / 3;
        int killed = population / 4;
        population = population + born - killed;
        years++;
        printf("Current size: %i, born: %i, killed: %i\n", population, born, killed);
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
