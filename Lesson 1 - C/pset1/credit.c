#include <cs50.h>
#include <stdio.h>
#include <string.h>

string check_card(long number, size_t length, char *numberStr);

int main(void)
{
    long number;
    char numberStr[20];
    size_t length;

    number = get_long("Number ");

    snprintf(numberStr, sizeof(numberStr), "%ld", number);

    length = strlen(numberStr);

    /* All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55
    (they also have some other potential starting numbers which we won’t concern ourselves with for this problem);
    and all Visa numbers start with 4. */
    check_card(number, length, numberStr);

    return 0;
}
bool luhn_check(size_t length, char *numberStr, long number)
{
    int result = 0;
    bool alternate = false; // To determine whether to multiply by 2

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = numberStr[i] - '0';

        if (alternate)
        {
            int product = digit * 2;
            if (product >= 10)
            {
                // If the product is two digits, add its individual digits
                result += (product % 10) + (product / 10);
            }
            else
            {
                result += product;
            }
        }
        else
        {
            result += digit;
        }

        alternate = !alternate; // Toggle the alternate flag
    }

    if (result % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string check_card(long number, size_t length, char *numberStr)
{
    // printf("Length: %i\n", length);
    /*     printf("%s\n", numberStr);
     */

    // I need to implement a function that checks if the number is valid using Luhn’s Algorithm
    if ((length < 13 || length > 16) || luhn_check(length, numberStr, number) == false)
    {
        printf("INVALID\n");
    }
    else if (numberStr[0] == '4')
    {
        printf("VISA\n");
    }
    else if (numberStr[0] == '5' && (numberStr[1] == '1' || numberStr[1] == '2' || numberStr[1] == '3' || numberStr[1] == '4' || numberStr[1] == '5'))
    {
        printf("MASTERCARD\n");
    }
    else if (numberStr[0] == '3' && (numberStr[1] == '4' || numberStr[1] == '7'))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}