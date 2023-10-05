#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(string bit);
string decimalToBinary(char c, char binary[8]);
int main(void)
{
    string message = get_string("Message: ");
    // TODO
    for (int i = 0; i < strlen(message); i++)
    {
        char emptyBinary[8];
        string binary = decimalToBinary(message[i], emptyBinary);
        //printf("%s", binary);
        print_bulb(binary);
        printf("\n");
    }
}

string decimalToBinary(char c, char binary[8])
{
    int ascii = (int)c;
    // printf("%i\n", c);

    // We divide the number by 2
    // We will probably take the ascii code
    // If c % 2 has a remainder, add a 1, if not then add a 0
    // printf("%i\n", ascii);

    for (int i = 7; i >= 0; i--)
    {
        if (ascii % 2 == 0)
        {
            binary[i] = '0';
        }
        else
        {
            binary[i] = '1';
        }

        ascii = (int)(ascii / 2);
    }

    return binary;
}

void print_bulb(string bit)
{
    for (int i = 0; i < strlen(bit); i++)
    {
        // printf("%c\n", bit[i]);
        if (bit[i] == '0')
        {
            // Dark emoji
            printf("\U000026AB");
        }
        else if (bit[i] == '1')
        {
            // Light emoji
            printf("\U0001F7E1");
        }
    }
}
