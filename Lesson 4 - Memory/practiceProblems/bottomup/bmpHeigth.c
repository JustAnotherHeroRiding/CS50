#include <stdio.h>
#include <stdlib.h>
#include "bmp.h" // Your BMP header definition

int main() {
    FILE* inptr = fopen("harvard_bottomup.bmp", "rb");
    if (inptr == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read input BMP header and info header
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Check if the original biHeight is positive
    if (bi.biHeight > 0) {
        printf("The input BMP is already a bottom-up DIB.\n");
        fclose(inptr);
        return 2;
    }

    // Calculate the new biHeight (make it positive)
    int newBiHeight = -bi.biHeight;
    printf("newBiHeight: %d\n", newBiHeight);

    // Create a new BMP file for writing
    FILE* outptr = fopen("output.bmp", "wb");
    if (outptr == NULL) {
        printf("Error creating output file.\n");
        fclose(inptr);
        return 3;
    }

    // Write the BMP header and info header to the new file
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Allocate memory for pixel data
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    RGBTRIPLE* image = malloc(sizeof(RGBTRIPLE) * bi.biWidth * newBiHeight);

    // Read the pixel data from the input file
    for (int i = 0; i < newBiHeight; i++) {
        fread(&image[i * bi.biWidth], sizeof(RGBTRIPLE), bi.biWidth, inptr);
        fseek(inptr, padding, SEEK_CUR);
    }

    // Write the pixel data to the new file
    for (int i = 0; i < newBiHeight; i++) {
        fwrite(&image[i * bi.biWidth], sizeof(RGBTRIPLE), bi.biWidth, outptr);
        for (int j = 0; j < padding; j++) {
            fputc(0x00, outptr);
        }
    }

    // Clean up and close files
    free(image);
    fclose(inptr);
    fclose(outptr);

    return 0;
}
