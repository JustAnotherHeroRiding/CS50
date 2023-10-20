#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // printf("grayscale\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            int count = 0;

            // Iterate over the 3x3 area surrounding the pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Skip pixels outside the image
                    if (ni < 0 || ni >= height || nj < 0 || nj >= width)
                    {
                        continue;
                    }

                    totalRed += copy[ni][nj].rgbtRed;
                    totalGreen += copy[ni][nj].rgbtGreen;
                    totalBlue += copy[ni][nj].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = round(totalRed / count);
            image[i][j].rgbtGreen = round(totalGreen / count);
            image[i][j].rgbtBlue = round(totalBlue / count);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    int kernelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int kernelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int GxRed = 0;
            int GyRed = 0;

            int GxGreen = 0;
            int GyGreen = 0;

            int GxBlue = 0;
            int GyBlue = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {

                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // printf("di + dj = %d\n", di + dj);
                    // printf("di - dj = %d\n", di - dj);
                    //  Skip pixels outside the image
                    if (ni < 0 || ni >= height || nj < 0 || nj >= width)
                    {
                        GxRed += 0;
                        GyRed += 0;
                        GxGreen += 0;
                        GyGreen += 0;
                        GxBlue += 0;
                        GyBlue += 0;
                        continue;
                    }

                    // So far the logic is the same as blur in that we loop over the 3x3 area surrounding the pixel
                    // Skipping over any out of bounds boxes
                    GxRed += copy[ni][nj].rgbtRed * kernelX[di + 1][dj + 1];
                    GyRed += copy[ni][nj].rgbtRed * kernelY[di + 1][dj + 1];

                    GxGreen += copy[ni][nj].rgbtGreen * kernelX[di + 1][dj + 1];
                    GyGreen += copy[ni][nj].rgbtGreen * kernelY[di + 1][dj + 1];

                    GxBlue += copy[ni][nj].rgbtBlue * kernelX[di + 1][dj + 1];
                    GyBlue += copy[ni][nj].rgbtBlue * kernelY[di + 1][dj + 1];
                }
            }
            image[i][j].rgbtRed = fmin(round(sqrt(GxRed * GxRed + GyRed * GyRed)), 255);
            image[i][j].rgbtGreen = fmin(round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen)), 255);
            image[i][j].rgbtBlue = fmin(round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue)), 255);
        }
    }
    return;
}
