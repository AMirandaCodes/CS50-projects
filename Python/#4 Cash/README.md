# Problem 4: Cash

## Project brief
This program calculates the **minimum number of coins** required to give a user their change.  
It is written in Python and replicates the functionality of the *Cash* problem from CS50’s C version.  

The program must:
- Be implemented in a file called **cash.py**.
- Prompt the user for the amount of change owed (in dollars).
- Validate that the input is a non-negative number.
- Compute the smallest number of coins using U.S. denominations: quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
- Output only the number of coins (integer).

## Approach
This problem practices:
- Handling **floating-point input** safely.
- Converting dollars to **integer cents** to avoid rounding errors.
- Using **loops** and **integer division** for coin calculation.
- Managing **input validation** with a `while` loop.

The logic:
1. Prompt repeatedly until the user enters a non-negative float.  
2. Convert dollars to cents using `round()`.  
3. Subtract the highest possible denomination repeatedly until all change is given.  
4. Output the total number of coins used.

---

## My solution

### Description
The program:
- Uses `get_float()` to prompt for the change owed.
- Converts the input from dollars to cents to avoid precision issues.
- Iterates over each coin value in descending order.
- Uses integer division and modulo to count the minimum number of coins.


### How to use it
1. Ensure the **CS50 Python library** is installed: `pip install cs50`
2. Navigate to the corresponding folder.
3. Run the program: `python cash.py`
4. Enter a non-negative dollar amount (e.g., 0.99 or 1.25).

#### Code snippet
```python
from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

# Converts dollars to cents (for no rounding errors)
change = round(change * 100)

coins = 0
coin_list = [25, 10, 5, 1]

for coin in coin_list:
    # How many of this coin (integer division)
    coins += change // coin
    # Remaining change
    change %= coin

print(coins)
```
