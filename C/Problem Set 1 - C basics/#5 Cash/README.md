# Problem 5: Cash

## Project brief
This exercise simulates a cash register that calculates the minimum number of coins needed to give change. The program prompts the user for an amount of change (in cents) and returns the smallest number of U.S. coins (quarters, dimes, nickels, and pennies) required to make up that amount.

# Approach
This problem introduces greedy algorithms, where the largest possible coin is always used first. The skills practiced include:
- Validating user input with get_int (must be a non-negative integer).
- Using integer division to determine how many coins of each type can be used.
- Breaking the task into modular helper functions (calculate_quarters, calculate_dimes, etc.) to keep the code clean and readable.
- Updating the remaining cents after each calculation until all change is dispensed.

## My solution

### Description
The program:
- Prompts the user for an amount of change owed in cents.
- Validates input and re-prompts until a non-negative integer is provided.
- Calculates how many quarters, dimes, nickels, and pennies are needed.
- Outputs the total number of coins used.

### How to use it
1. Make sure you have the CS50 library (and other referenced libraries) installed.
2. Navigate to the corresponding folder.
3. Compile with: *make cash*
4. Run the program: *./cash*
5. Enter the amount of change owed in cents.

#### Code snippet
```c
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
```
