// Import files
# include <cs50.h>
# include <stdio.h>

int main(void)
{
    // Get user's name and store under variable 'name'
    string name = get_string("What's your name? \n");

    // Print out personalised greeting message to user
    printf("hello, %s\n", name);
}