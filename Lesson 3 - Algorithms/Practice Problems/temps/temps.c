// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);
void sort_citiesOptimized(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
        // printf("Largest temp %i: \n", temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
/* repeat (numOfElements - 1) times

  set the first unsorted element as the minimum

  for each of the unsorted elements

    if element < currentMinimum

      set element as new minimum

  swap minimum with first unsorted position */

void sort_citiesOptimized(void)
{
    bool sorting = true;
    while (sorting)
    {
        sorting = false; // Assume the array is sorted
        for (int i = 0; i < NUM_CITIES - 1; i++)
        {
            // Swap adjacent elements if they are in the wrong order
            if (temps[i].temp < temps[i + 1].temp)
            {
                avg_temp swap = temps[i];
                temps[i] = temps[i + 1];
                temps[i + 1] = swap;
                sorting = true; // If a swap happened, the array might not be sorted yet
            }
        }
    }
}

void sort_cities(void)
{
    // Bubble sort
    // Take the current element and compare it to the next element
    // If the current element is smaller than the next element, swap them
    // If no swapping took place, the array is sorted
    bool sorting = true;
    while (sorting)
    {
        for (int i = 0; i < NUM_CITIES - 1; i++)
        {
            int swaps = 0;

            for (int j = 0; j < NUM_CITIES - 1; j++)
            {
                if (temps[j].temp < temps[j + 1].temp && j != i)
                {
                    avg_temp swap = temps[j];
                    temps[j] = temps[j + 1];
                    temps[j + 1] = swap;
                    swaps++;
                }
            }
            if (swaps == 0)
            {
                sorting = false;
            }
        }
    }

    // Selection sort working implementation
    /*  int temp;
     for (int i = 0; i < NUM_CITIES; i++)
     {
         temp = i;

         for (int j = i; j < NUM_CITIES; j++)
         {
             if (temps[j].temp > temps[temp].temp)
             {
                 temp = j;
             }
         }
         avg_temp swap = temps[i];
         if (temp != i)
         {
             temps[i] = temps[temp];
             temps[temp] = swap;
         }
     } */
}
// Add your code here
// for (int i = 0; i < NUM_CITIES - 1; i++)
//{
// Here we need to implement the sorting algorithm
// Let us try Selection sort as it is the simplest
// This algo will compare each element and save the largest temp value
// At the end of the loop it will place the largest temp value in the first position
// We keep looping over until the array is sorted(we looped n times over the array)
//    int largest_temp_index = i;
//    avg_temp largest_temp;
//    for (int j = i + 1; j < NUM_CITIES - 1; j++)
//    {
//        largest_temp = temps[j];
//
//        if (temps[j].temp > temps[largest_temp_index].temp)
//        {
//            largest_temp_index = j;
//            largest_temp = temps[j];
//        }
//        temps[largest_temp_index] = temps[i];
//        temps[j] = temps[i];     // Swap the found largest temp with the current element
//        temps[i] = largest_temp; // Swap the current element with the temp
//
//        // printf("Largest temp: %s %i F \n", temps[j].city, temps[j].temp);
//    }
//}
// Here we need to implement a sorting algorithm for the temperatures
// We can use one of the sorting algorithms we learned in class
// possibly bubble sort, selection sort, or insertion sort
