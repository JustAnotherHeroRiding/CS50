// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;
typedef int16_t SHORT;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Assuming HEADER_SIZE is the size of your header
    BYTE header[HEADER_SIZE];
    SHORT buffer;

    // TODO: Copy header from input file to output file

    // Read the header from the input file
    fread(header, HEADER_SIZE, 1, input);

    // Write the header to the output file
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    while (fread(&buffer, 2, 1, input) == 1)
    {
        int value = buffer; // Store the value from the buffer
        //printf("%d\n", value);
        value = value * factor;       // Multiply the value by factor
        fwrite(&value, 2, 1, output); // Write the result to the output file
    }

    // Close files
    fclose(input);
    fclose(output);
}
