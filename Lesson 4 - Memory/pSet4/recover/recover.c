#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: ./recover image.raw\n");
        return 1;
    }

    char *infile = argv[1];

    // Open input file
    FILE *raw_file = fopen(infile, "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    int count = 0;
    int blockRead = 0;
    char buffer[BLOCK_SIZE];
    FILE *outptr = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (buffer[0] =0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            char filename[8];

            // Generate filename and try to open the file
            sprintf(filename, "%03d.jpg", count);

            // If the file exists, increment the counter and try again
            // Now filename contains the name of the first non-existing file
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                printf("Could not create output file.\n");
                return 1;
            }
            count++;
        }
        fwrite(buffer, 1, BLOCK_SIZE, outptr);
        blockRead++;
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(raw_file);
    return 0;
}