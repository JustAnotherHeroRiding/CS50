#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // printf("%s\n", buffer);

    // Create array to store plate numbers
    char plates[8][8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';
        // Save plate number in array
        // Copy the plate number into the array
        strcpy(plates[idx], buffer);
        //plates[idx] = strdup(buffer);
        // printf("Plate number: %s, index = %i, saved plate number = %s\n", buffer, idx, plates[idx]);

        // The pointers for buffer and plates[idx] are the same
        // They return the same memory block
        // This means that the same memory block keeps getting changed
        // The reason that plates array prints the same is that all the elements
        // in the array just a pointer to the same address
        idx++;
    }

    // printf("Buffer pointer %p plates[5] pointer %p\n", buffer, plates[5]);
    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
   /*  for (int i = 0; i < idx; i++)
    {
        free(plates[i]);
    } */
}
