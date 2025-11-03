# Problem 3: Mario (more)

## Project brief
This program recreates two side-by-side half-pyramids using hashes (`#`), inspired by *Super Mario Bros*.  
It is implemented in **Python** and prompts the user to enter a height between **1 and 8**, inclusive.  
If the user provides invalid input, they are re-prompted until a valid height is entered.

The program must:
- Be implemented in a file called **mario.py** inside a folder called `sentimental-mario-more`.
- Prompt the user for a height between 1 and 8 (inclusive).
- Generate two mirrored half-pyramids separated by two spaces.

## Approach
This problem practices:
- Input validation with loops and conditions.
- Generating structured output using nested loops.
- Controlling alignment through string multiplication and the `end` parameter in `print()`.

---

## My solution

### Description
The program:
1. Prompts the user repeatedly for a valid integer between 1 and 8.  
2. Prints the double half-pyramid with correct spacing and alignment.  
3. Ensures no trailing spaces on each line.

### How to use it
1. Ensure the **CS50 Python library** is installed.
2. Navigate to the correspoding folder.
3. Run the program: `python mario.py`
4. Enter a height (1–8) when prompted.

#### Code snippet
```python
from cs50 import get_int

# Loops forever until height given is within range
while True:
    height = get_int('Height: ')
    if height in range(1, 9):
        break

# Prints spaces and blocks
for i in range(height):
    print(' ' * (height - i - 1), end='')
    print('#' * (i + 1), end='')

    # Gap of 2 spaces
    print(' ' * 2, end='')

    # Blocks on right-hand side
    print('#' * (i + 1))
```
