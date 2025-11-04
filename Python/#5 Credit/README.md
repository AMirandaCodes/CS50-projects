# Problem 5: Credit

## Project brief
This program validates **credit card numbers** and identifies whether they belong to **American Express (AMEX)**, **MasterCard**, or **Visa** using **Luhn’s algorithm**.  
It replicates the logic of the *Credit* problem from CS50’s C version, now implemented in Python.

The program must:
- Be implemented in a file called **credit.py**.
- Prompt the user for a **credit card number**.
- Determine whether the number is valid according to **Luhn’s algorithm**.
- Output exactly one of the following: `AMEX`, `MASTERCARD`, `VISA`, or `INVALID`.

## Approach
This problem focuses on **algorithmic logic**, **string manipulation**, and **conditional validation** in Python.  
The skills practiced include:
- Using **loops** to iterate through digits in reverse.
- Applying **Luhn’s checksum** to verify card validity.
- Identifying card type based on number **prefix** and **length**.
- Managing **user input** with the CS50 library.

**Luhn’s Algorithm Summary:**
1. Multiply every other digit (starting from the second-to-last) by 2.  
2. Add the digits of these products together.  
3. Add this sum to the sum of the digits that weren’t multiplied.  
4. If the total modulo 10 equals 0, the card number is valid.

**Card type identifiers:**
- **AMEX:** Starts with 34 or 37, 15 digits long.  
- **MASTERCARD:** Starts with 51–55, 16 digits long.  
- **VISA:** Starts with 4, 13 or 16 digits long.

---

## My solution

### Description
The program:
- Prompts the user for a credit card number using `get_int()`.
- Converts the input to a string for digit iteration.
- Implements **Luhn’s algorithm** to calculate a checksum.
- Determines the card type based on its length and prefix.
- Prints the card type or `INVALID` if it fails validation.

### How to use it
1. Ensure the **CS50 Python library** is installed: `pip install cs50`
2. Navigate to the corresponding folder.
3. Run the program: `python credit.py`
4. Enter a credit card number when prompted (digits only, no spaces or hyphens).

#### Code snippet
```python
from cs50 import get_int
import re

number = get_int("Number: ")

# Converts number to a string
number = str(number)

# Checksum
checksum = int(0)

# Doubles every other digit starting from the second-to-last
for i in range(len(number) - 2, -1, -2):
    m = int(number[i]) * 2
    checksum += m // 10 + m % 10  # Adds digits of product

# Adds remaining digits
for i in range(len(number) - 1, -1, -2):
    checksum += int(number[i])

# Validate number
if checksum % 10 == 0:
    if len(number) == 15 and number.startswith(("34", "37")):
        print("AMEX")

    elif len(number) == 16 and number.startswith(("51", "52", "53", "54", "55")):
        print("MASTERCARD")

    elif len(number) in (13, 16) and number.startswith(("4")):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

```
