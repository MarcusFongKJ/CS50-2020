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
        //Check argument whether = 26 characters
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        //Only contain alphabetic characters
        for (int i = 0; i < 26; i += 1)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }

        //No repeated characters
        for (int i = 0; i < 26; i += 1)
        {
            for (int j = i + 1; j < 26; j += 1)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }

        // Printing outputs
        string text = get_string("plaintext: ");
        string key = argv[1];   //store argument in variable (key)
        printf("ciphertext: ");

        int val;
        for (int i = 0, n = strlen(text); i < n; i += 1)
        {
            // Convert text[i] to find index of key
            if (isupper(text[i]))
            {
                val = text[i] - 65;
                printf("%c", toupper(key[val]));    //if is initially upper, change to upper
            }
            else if (islower(text[i]))
            {
                val = text[i] - 97;
                printf("%c", tolower(key[val]));    //if is initially lower, change to lower
            }
            else    //if not alphabet, no change
            {
                printf("%c", text[i]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}