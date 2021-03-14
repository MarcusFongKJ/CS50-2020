# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>

int main(void)
{
    // Coleman-Liau Index (index = 0.0588 * L - 0.296 * S - 15.8)

    // Functions
    int count_letters(string text);
    int count_words(string text);
    int count_sentences(string text);

    // Get text from user
    string text = get_string("Text: ");

    // Letters
    int letters = count_letters(text);
    // Words
    int words = count_words(text);
    // Sentences
    int sentences = count_sentences(text);

    // Calculating Coleman-Liau index
    float L = 100.0 * letters / words;    // L = average number of letters per 100 words in the text
    float S = 100.0 * sentences / words;  // S = average number of sentences per 100 words in the text
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Output
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// ========== Functions below ==========

int count_letters(string text)
{
    // For every character in text that is an alphabetic character, count will increase by 1
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i += 1)
    {
        if (isalpha(text[i]))   // Using isalpha function from <ctype.h> to check for alphabetic character
        {
            count += 1;
        }
    }

    return count;
}

int count_words(string text)
{
    // For every white-space character in text, count will increase by 1
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i += 1)
    {
        if (isspace(text[i]))   // Using isspace function from <ctype.h> to check for white-space characters
        {
            count += 1;
        }
    }

    return count + 1; // count + 1 to account for the last word
}

int count_sentences(string text)
{
    // ASCII codes: "!" = 33, "." = 46, "?" = 63
    // If char in text is = 33, 46 or 63, then count + 1
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i += 1)
    {
        if ((text[i] == 33) || (text[i] == 46) || (text[i] == 63))
        {
            count += 1;
        }
    }

    return count;
}