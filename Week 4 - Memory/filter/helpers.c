#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Find average of RGB values in the pixel and assign that value to the amt of RGB
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            // Calculate average RGB of each pixel
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Changing RGB of each pixel to the average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            // Calculating new sepiaRGB values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // Ensure sepia values are between 0 and 255 inclusive
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // Changing the colors for each pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //for 1 row
    for (int row = 0; row < height; row ++)
    {
        // create an array of flipped image for each row
        RGBTRIPLE flip[width];
        for (int i = 0; i < width; i ++)
        {
            flip[i] = image[row][width - 1 - i];
        }

        for (int col = 0; col < width; col ++)
        {
            image[row][col] = flip[col];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // MAKE 2 LOOPS, 1 TO CHANGE THE PIXEL, 1 TO FIND THE AVG RGB OF SURROUNDING PIXELS
    // 3 CASES: CORNER, EDGE, NORMAL
    // Make a new array to store the blurred image, else for every iteration the RGB values will be affected
    RGBTRIPLE newImage[height][width];

    for (int row = 0; row < height; row ++)
    {
        for (int col = 0; col < width; col ++)
        {
            int avgRed;
            int avgGreen;
            int avgBlue;

            // CORNER PIXEL =======================
            if (row == 0 && col == 0)   // TOP LEFT
            {
                avgRed = round((image[row][col].rgbtRed + image[row][col + 1].rgbtRed + \
                                image[row + 1][col].rgbtRed + image[row + 1][col + 1].rgbtRed) / 4.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row][col + 1].rgbtGreen + \
                                image[row + 1][col].rgbtGreen + image[row + 1][col + 1].rgbtGreen) / 4.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row][col + 1].rgbtBlue + \
                                image[row + 1][col].rgbtBlue + image[row + 1][col + 1].rgbtBlue) / 4.0);
                // Assign to newImage
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }
            else if (row == 0 && col == width - 1)   // TOP RIGHT
            {
                avgRed = round((image[row][col].rgbtRed + image[row][col - 1].rgbtRed + \
                                image[row + 1][col - 1].rgbtRed + image[row + 1][col].rgbtRed) / 4.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row][col - 1].rgbtGreen + \
                                image[row + 1][col - 1].rgbtGreen + image[row + 1][col].rgbtGreen) / 4.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row][col - 1].rgbtBlue + \
                                image[row + 1][col - 1].rgbtBlue + image[row + 1][col].rgbtBlue) / 4.0);
                // Assign to newImage
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }
            else if (row == height - 1 && col == width - 1)  // BOT RIGHT
            {
                avgRed = round((image[row][col].rgbtRed + image[row - 1][col - 1].rgbtRed + \
                                image[row - 1][col].rgbtRed + image[row][col - 1].rgbtRed) / 4.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row - 1][col - 1].rgbtGreen + \
                                image[row - 1][col].rgbtGreen + image[row][col - 1].rgbtGreen) / 4.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row - 1][col - 1].rgbtBlue + \
                                image[row - 1][col].rgbtBlue + image[row][col - 1].rgbtBlue) / 4.0);
                // Assign to newImage
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }
            else if (row == height - 1 && col == 0) // BOT LEFT
            {
                avgRed = round((image[row][col].rgbtRed + image[row - 1][col].rgbtRed + \
                                image[row - 1][col + 1].rgbtRed + image[row][col + 1].rgbtRed) / 4.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row - 1][col].rgbtGreen + \
                                image[row - 1][col + 1].rgbtGreen + image[row][col + 1].rgbtGreen) / 4.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row - 1][col].rgbtBlue + \
                                image[row - 1][col + 1].rgbtBlue + image[row][col + 1].rgbtBlue) / 4.0);
                // Assign to newImage
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }


            // EDGE PIXEL ========================
            else if (row == 0)   // TOP EDGE
            {
                avgRed = round((image[row][col].rgbtRed + image[row][col - 1].rgbtRed + image[row][col + 1].rgbtRed + \
                                image[row + 1][col].rgbtRed + image[row + 1][col - 1].rgbtRed + image[row + 1][col + 1].rgbtRed) / 6.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row][col - 1].rgbtGreen + image[row][col + 1].rgbtGreen + \
                                image[row + 1][col].rgbtGreen + image[row + 1][col - 1].rgbtGreen + image[row + 1][col + 1].rgbtGreen) / 6.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row][col - 1].rgbtBlue + image[row][col + 1].rgbtBlue + \
                                image[row + 1][col].rgbtBlue + image[row + 1][col - 1].rgbtBlue + image[row + 1][col + 1].rgbtBlue) / 6.0);
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }
            else if (col == 0)   // LEFT EDGE
            {
                avgRed = round((image[row][col].rgbtRed + image[row - 1][col].rgbtRed + image[row + 1][col].rgbtRed + \
                                image[row][col + 1].rgbtRed + image[row - 1][col + 1].rgbtRed + image[row + 1][col + 1].rgbtRed) / 6.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row - 1][col].rgbtGreen + image[row + 1][col].rgbtGreen + \
                                image[row][col + 1].rgbtGreen + image[row - 1][col + 1].rgbtGreen + image[row + 1][col + 1].rgbtGreen) / 6.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row - 1][col].rgbtBlue + image[row + 1][col].rgbtBlue + \
                                image[row][col + 1].rgbtBlue + image[row - 1][col + 1].rgbtBlue + image[row + 1][col + 1].rgbtBlue) / 6.0);
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }
            else if (col == width - 1)   // RIGHT EDGE
            {
                avgRed = round((image[row][col].rgbtRed + image[row - 1][col].rgbtRed + image[row + 1][col].rgbtRed + \
                                image[row][col - 1].rgbtRed + image[row - 1][col - 1].rgbtRed + image[row + 1][col - 1].rgbtRed) / 6.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row - 1][col].rgbtGreen + image[row + 1][col].rgbtGreen + \
                                image[row][col - 1].rgbtGreen + image[row - 1][col - 1].rgbtGreen + image[row + 1][col - 1].rgbtGreen) / 6.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row - 1][col].rgbtBlue + image[row + 1][col].rgbtBlue + \
                                image[row][col - 1].rgbtBlue + image[row - 1][col - 1].rgbtBlue + image[row + 1][col - 1].rgbtBlue) / 6.0);
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }
            else if (row == height - 1)  // BOT EDGE
            {
                avgRed = round((image[row][col].rgbtRed + image[row][col - 1].rgbtRed + image[row][col + 1].rgbtRed + \
                                image[row - 1][col].rgbtRed + image[row - 1][col - 1].rgbtRed + image[row - 1][col + 1].rgbtRed) / 6.0);
                avgGreen = round((image[row][col].rgbtGreen + image[row][col - 1].rgbtGreen + image[row][col + 1].rgbtGreen + \
                                image[row - 1][col].rgbtGreen + image[row - 1][col - 1].rgbtGreen + image[row - 1][col + 1].rgbtGreen) / 6.0);
                avgBlue = round((image[row][col].rgbtBlue + image[row][col - 1].rgbtBlue + image[row][col + 1].rgbtBlue + \
                                image[row - 1][col].rgbtBlue + image[row - 1][col - 1].rgbtBlue + image[row - 1][col + 1].rgbtBlue) / 6.0);
                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }

            // REST OF PIXELS
            else
            {
                avgRed = round((image[row - 1][col - 1].rgbtRed + image[row - 1][col].rgbtRed + image[row - 1][col + 1].rgbtRed + \
                                image[row][col - 1].rgbtRed + image[row][col].rgbtRed + image[row][col + 1].rgbtRed + \
                                image[row + 1][col - 1].rgbtRed + image[row + 1][col].rgbtRed + image[row + 1][col + 1].rgbtRed) / 9.0);

                avgGreen = round((image[row - 1][col - 1].rgbtGreen + image[row - 1][col].rgbtGreen + image[row - 1][col + 1].rgbtGreen + \
                                image[row][col - 1].rgbtGreen + image[row][col].rgbtGreen + image[row][col + 1].rgbtGreen + \
                                image[row + 1][col - 1].rgbtGreen + image[row + 1][col].rgbtGreen + image[row + 1][col + 1].rgbtGreen) / 9.0);

                avgBlue = round((image[row - 1][col - 1].rgbtBlue + image[row - 1][col].rgbtBlue + image[row - 1][col + 1].rgbtBlue + \
                                image[row][col - 1].rgbtBlue + image[row][col].rgbtBlue + image[row][col + 1].rgbtBlue + \
                                image[row + 1][col - 1].rgbtBlue + image[row + 1][col].rgbtBlue + image[row + 1][col + 1].rgbtBlue) / 9.0);

                newImage[row][col].rgbtRed = avgRed;
                newImage[row][col].rgbtGreen = avgGreen;
                newImage[row][col].rgbtBlue = avgBlue;
            }

        }   //end of col loop
    }   //end of row loop

    // Change to blurred
    for (int row = 0; row < height; row ++)
    {
        for (int col = 0; col < width; col ++)
        {
            image[row][col] = newImage[row][col];
        }
    }
    return;
}