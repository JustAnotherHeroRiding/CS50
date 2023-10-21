#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
    char buffer[BLOCK_SIZE];
    FILE *outptr = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {

        // Read the first 4 bytes of the buffer
        unsigned char first_four_bytes[4];
        memcpy(first_four_bytes, buffer, 4);

        // Check if the first three bytes are 0xff, 0xd8, 0xff
        if (first_four_bytes[0] == 0xff &&
            first_four_bytes[1] == 0xd8 &&
            first_four_bytes[2] == 0xff)
        {
            // Check if the first 4 bits of the fourth byte are 1110 (0xe)
            // This is done by bitwise AND with 0xf0 and then comparing with 0xe0
            if ((first_four_bytes[3] & 0xf0) == 0xe0)
            {
                if (outptr != NULL) {
                    fclose(outptr);
                }
                char filename[8];

                // Generate filename and try to open the file
                sprintf(filename, "%03d.jpg", count);

                // If the file exists, increment the counter and try again
                // Now filename contains the name of the first non-existing file

                // It seems that this line is leaking memory as there are 49 opened files at the end
                // I tried closing them at the end of each loop but this broke the images instead
                outptr = fopen(filename, "w");
                if (outptr == NULL)
                {
                    printf("Could not create output file.\n");
                    return 1;
                }
                count++;
            }
        }

        if (outptr != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outptr);
            // This also breaks it as I think the checks above are crucial to the program and this breaks them
            // fclose(outptr);
        }
        // This breaks the functionality
        // fclose(outptr);
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(raw_file);
    return 0;
}