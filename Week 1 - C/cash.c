// Import files
# include <cs50.h>
# include <stdio.h>
# include <math.h>

int main(void)
{
    // Get change value
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // Covert to cents
    int cents = round(dollars * 100);

    // Counting num of coins required
    int count = 0;

    while (cents - 25 >= 0) //num of 25c coins
    {
        cents -= 25;
        count += 1;
    }
    while (cents - 10 >= 0) //num of 10c coins
    {
        cents -= 10;
        count += 1;
    }
    while (cents - 5 >= 0) //num of 5c coins
    {
        cents -= 5;
        count += 1;
    }
    while (cents - 1 >= 0) //num of 1c coins required to reduce change to 0
    {
        cents -= 1;
        count += 1;
    }

    printf("%i\n", count);
}