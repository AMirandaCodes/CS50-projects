# Problem 2: Mario (less)

## Project brief
This exercise implements a **Python program** that recreates a **half-pyramid** of hashes (`#`) aligned to the bottom-left corner of the terminal.  
It mirrors the C version of the same problem from CS50 but is written using Python syntax and logic.

The program must:
- Be implemented in a file called **mario.py** inside a folder called `sentimental-mario-less`.
- Prompt the user (with `get_int`) for the height of the pyramid.
- Accept only a positive integer between **1 and 8**, inclusive.
- Re-prompt the user if the input is invalid.
- Print the pyramid using `#` for bricks and spaces for alignment.

## Approach
This problem focuses on **loops, conditionals, and string manipulation** in Python.  
The skills practiced include:
- Input validation using `while True` loops.
- Numeric input handling with the `cs50` library’s `get_int()` function.
- String repetition using multiplication (`' ' * n`, `'#' * n`).
- Printing formatted output with control over newlines using `end=''`.

---

## My solution

### Description
The program:
- Continuously prompts the user for a height until a valid integer (1–8) is provided.
- For each row, prints the appropriate number of spaces followed by hashes to form the pyramid.

### How to use it
1. Make sure the **CS50 Python library** is installed.
2. Navigate to the corresponding folder.
3. Run the program with: `python mario.py`
4. Enter a number between 1 and 8 when prompted.

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
    print('#' * (i + 1))
```
