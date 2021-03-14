// Import files
# include <cs50.h>
# include <stdio.h>

int main(void)
{
    // Get height ensuring it is between 1 and 8 inclusive
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Use a loop to make pyramid
    for (int row = 1; row <= height; row += 1) //row starts from 1 and increases till height indicated by user
    {
        // LEFT HALF OF PYRAMID
        //=================================
        // Creating space before #
        for (int i = height; i > row; i -= 1)
        {
            printf(" ");
        }

        // Printing the #
        for (int col = 0; col < row; col += 1) //col starts from 0, as long as col is less than row num, print # then increase col by 1
        {
            printf("#");
        }
        //=================================

        //DIVIDER
        printf("  ");

        //RIGHT HALF OF PYRAMID
        //=================================
        for (int col = 0; col < row; col += 1) //col starts from 0, as long as col is less than row num, print # then increase col by 1
        {
            printf("#");
        }
        //=================================

        // Next row
        printf("\n");
    }
}