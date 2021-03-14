# include <cs50.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Ensure argument is digit and positive
        for (int i = 0, n = strlen(argv[1]); i < n; i += 1)
        {
            if (!isdigit(argv[1][i]))   //Digits
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

            if (argv[1] < 0)    //Positive integer
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // Convert argv[1] to integer
        int key = atol(argv[1]);     //Use atol() from stdlib.h to convert string to integer

        // Printing outputs
        string text = get_string("plaintext: ");
        printf("ciphertext: ");

        // Iterate over each character of the plaintext
        for (int i = 0, n = strlen(text); i < n; i += 1)
        {
            if (isupper(text[i]))   // if uppercase letter, rotate it, preserving case, then print out the rotated character
            {
                // Encipher using formula
                int p = text[i] - 65;   // Alphabetic values (A=0, B=1, ..., Z=25)
                int cipher = (p + key) % 26;    // Applying formula
                printf("%c", cipher + 65);  // Convert back to ASCII by adding 65
            }
            else if (islower(text[i]))  // if lowercase letter, rotate it, preserving case, then print out the rotated character
            {
                // Encipher using formula
                int p = text[i] - 97;   // Alphabetic values (a=0, b=1, ..., z=25)
                int cipher = (p + key) % 26;    // Applying formula
                printf("%c", cipher + 97);  // Convert back to ASCII by adding 97
            }
            else    // if neither, print out the character as is
            {
                printf("%c", text[i]);
            }
        }

        printf("\n");
        return 0
    }

    else    //If no argument is input into ./caesar
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}