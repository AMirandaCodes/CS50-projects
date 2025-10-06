#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owned in cents
    int cents;
    do
    {
        cents = get_int("Change owed (in cents): ");
    }
    while (cents < 0);
    // Creates variable for no. of coins needed
    int coins = 0;

    // Calculates coins of each type and substracts their value
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);
    coins = coins + quarters;

    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);
    coins = coins + dimes;

    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);
    coins = coins + nickels;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies;
    coins = coins + pennies;

    printf("Coins used: %i \n", coins);
}

// Calculate how many quarters should be given to the customer
int calculate_quarters(int cents)
{
    return cents / 25;
}

// Calculate how many dimes you should give customer
int calculate_dimes(int cents)
{
    return cents / 10;
}

// Calculate how many nickels you should give customer
int calculate_nickels(int cents)
{
    return cents / 5;
}

// Calculate how many pennies you should give customer
int calculate_pennies(int cents)
{
    return cents;
}
