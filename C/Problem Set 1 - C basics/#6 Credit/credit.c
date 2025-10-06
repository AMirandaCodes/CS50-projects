#include <cs50.h>
#include <math.h>
#include <stdio.h>

int multiplied_dig_calc(long card_no);
int non_multiplied_calc(long card_no);
int length_card_calc(long card_no);
int first_digits_calc(long length_card, long card_no);

int main(void)
{
    long card_no;
    do
    {
        card_no = get_long("Credit card no.: ");
    }
    while (card_no < 1000);

    // Perform calculations: sum of digits, length no., & first digits
    int multiplied = multiplied_dig_calc(card_no);
    int non_multiplied = non_multiplied_calc(card_no);
    int checksum = multiplied + non_multiplied;
    int length_card = length_card_calc(card_no);
    int first_digits = first_digits_calc(length_card, card_no);

    // Check if all the conditions are met, and print type of card
    if ((checksum % 10 == 0) && (length_card == 15) && (first_digits == 37 || first_digits == 34))
    {
        printf("AMEX\n");
    }
    else if ((checksum % 10 == 0) && (length_card == 16) &&
             (56 > first_digits && first_digits > 50))
    {
        printf("MASTERCARD\n");
    }
    else if ((checksum % 10 == 0) && (length_card == 16 || length_card == 13) &&
             (first_digits && first_digits == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Takes second-to-last-digit, takes every other digit, multiplies them by 2, and returns sum
int multiplied_dig_calc(long card_no)
{
    int sum = 0;
    int digits = 0;
    int sum_digits = 0;
    while (card_no >= 1)
    {
        card_no = card_no / 10;
        digits = (card_no % 10) * 2;
        sum_digits = (digits / 10) + (digits % 10);
        card_no = card_no / 10;
        sum += sum_digits;
    }
    return sum;
}

// Takes last digit, takes every other digit, and return sum
int non_multiplied_calc(long card_no)
{
    int non_multiplied_dig_sum = 0;
    while (card_no > 0)
    {
        non_multiplied_dig_sum += card_no % 10;
        card_no = card_no / 100;
    }
    return non_multiplied_dig_sum;
}

// Calculates the length of the card
int length_card_calc(long card_no)
{
    int length_card = 0;
    while (card_no > 0)
    {
        length_card++;
        card_no /= 10;
    }
    return length_card;
}

// Calculate the first digits
int first_digits_calc(long length_card, long card_no)
{
    int first_digits = 0;

    // For 13 digits
    if (length_card == 13)
    {
        first_digits = (card_no / pow(10, 12));
    }

    // For 15 digits
    else if (length_card == 15)
    {
        first_digits = (card_no / pow(10, 13));
    }

    // For 16 digits, starting with 4 (gets only the first digit)
    else if ((length_card == 16) && (card_no / 1000000000000000 == 4))
    {
        first_digits = (card_no / pow(10, 15));
    }

    // For 16 digits, starting with 5 (gets the first 2 digits)
    else if ((length_card == 16) && (card_no / 1000000000000000 == 5))
    {
        first_digits = (card_no / pow(10, 14));
    }
    return first_digits;
}
