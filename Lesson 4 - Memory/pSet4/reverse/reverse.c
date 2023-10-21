#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 2;
    }
    // Read header
    // TODO #3
    WAVHEADER header;

    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) != true)
    {
        printf("Invalid WAV format.\n");
        return 3;
    }
    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);
    

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    // char buffer[block_size];

    // printf("%i\n", block_size);

    // Move the file pointer to the end of the file
    fseek(input, 0, SEEK_END);

    // Get the size of the file
    long filesize = ftell(input);

    filesize -= sizeof(WAVHEADER);

    // Calculate the number of blocks
    int num_blocks = filesize / block_size;

    // Allocate memory for the buffer
    char *buffer = malloc(block_size);

    int remaining_bytes = filesize % block_size;

    // If there are remaining bytes, read and write them first
    if (remaining_bytes > 0)
    {
        // Move the file pointer to the start of the remaining bytes
        fseek(input, sizeof(WAVHEADER), SEEK_SET);

        // Read the remaining bytes into the buffer
        fread(buffer, remaining_bytes, 1, input);

        // Write the remaining bytes to the output file
        fwrite(buffer, remaining_bytes, 1, output);
    }

    // Loop from the last full block to the first block
    for (int i = num_blocks - 1; i >= 0; i--)
    {
        // Move the file pointer to the start of the current block
        fseek(input, sizeof(WAVHEADER) + i * block_size, SEEK_SET);

        // Read the block into the buffer
        fread(buffer, block_size, 1, input);

        // Write the buffer to the output file
        fwrite(buffer, block_size, 1, output);
    }

    // Free the buffer
    free(buffer);

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] != 'W' || header.format[1] != 'A' || header.format[2] != 'V' || header.format[3] != 'E')
    {
        return false;
    }
    /* for (int i = 0; i < 3; i++)
    {
        printf("%c", header.format[i]);
    }
    printf("%c", header.format[3]);
    printf("\n"); */
    return true;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    // we calculate the size of each block with the following calculation: number of channels multiplied by bytes per sample.
    int block_size = header.numChannels * (header.bitsPerSample / 8);
    return block_size;
}