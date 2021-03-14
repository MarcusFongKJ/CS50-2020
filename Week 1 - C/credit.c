// Import files
# include <cs50.h>
# include <stdio.h>
# include <math.h>

int main(void)
{
    //Get credit card number
    long num = get_long("Number: ");

    //Length of credit card number
    long labs();
    long nDigits = floor(log10(labs(num))) + 1;

    long sum1 = 0;
    long sum2 = 0;
    long lenVal;
    long lenPow;

    for (int i = 1; i <= nDigits; i += 1)
    {
        long power = pow(10, i);

        if (i % 2 == 0) //every other number from second value from back (multiply each by 2 then sum digits)
        {
            long val1 = num % power;
            lenVal = floor(log10(labs(val1))) + 1;
            lenPow = floor(log10(labs(power))) + 1;

            // fix remainder issue (eg for values like 101, if % 100, remainder is 1 [unable to get 0])
            //lenPow - 1 needs to be equal to lenVal, else val = 0

            if (lenPow - 1 == lenVal)
            {
                while (val1 >= 10)   //finding first digit of remainder
                {
                    val1 = val1 / 10;
                }
            }
            else
            {
                val1 = 0;
            }

            // sum of product's DIGITS (range lies from 0-18 [0 to 9 x 2])
            // if val1 <= 4, digit is actual (0-8)
            if (val1 <= 4)
            {
                sum1 = sum1 + (val1 * 2);
            }

            // else (10-18), need to split value of digits (first digit - floor division by 10, second digit - modulo 10)
            else
            {
                long first = floor(val1 * 2 / 10);
                long second = (val1 * 2) % 10;
                sum1 = sum1 + first + second;
            }
        }

        else //every other number from first value from back (sum)
        {
            long val2 = num % power;
            lenVal = floor(log10(labs(val2))) + 1;
            lenPow = floor(log10(labs(power))) + 1;

            if (lenPow - 1 == lenVal)  //finding first digit of remainder
            {
                while (val2 >= 10)
                {
                    val2 = val2 / 10;
                }
            }
            else
            {
                val2 = 0;
            }

            sum2 = sum2 + val2;
        }

    }   //end of for loop


    long checksum = sum1 + sum2;
    // printf("checksum: %li\n", checksum);

    if (checksum % 10 == 0) // Valid checksum (last value = 0)
    {
        // check validity of card number
        // AMEX (15 digits), MasterCard (16 digits), VISA (13 or 16 digits)
        if (nDigits == 15 || nDigits == 16 || nDigits == 13)    //Valid card digit length
        {
            //AMEX start with 34 or 37
            //MasterCard numbers start with 51, 52, 53, 54, or 55 (other potential starting numbers are not of concern in the question)
            //Visa numbers start with 4
            // to find first digit,  floor num by 10^(nDigits - 1)
            // to find first 2 digits, floor num by 10^(nDigits - 2)
            long power = pow(10, (nDigits - 2));
            long visaPower = pow(10, (nDigits - 1));
            long start = floor(num / power);
            long visaStart = floor(num / visaPower);

            if (start == 34 || start == 37)
            {
                printf("AMEX\n");
            }
            else if (start == 51 || start == 52 || start == 53 || start == 54 || start == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                if (visaStart == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }

        else    //Invalid card digit length
        {
            printf("INVALID\n");
        }
    }

    else    // Invalid card (checksum is wrong)
    {
        printf("INVALID\n");
    }

}