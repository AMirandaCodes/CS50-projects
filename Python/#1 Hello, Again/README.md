# Problem 1: Hello, Again

## Project brief
This exercise implements a simple Python program that greets the user by name.  
It replicates the functionality of the classic “Hello” problem from CS50’s C version but uses Python syntax and conventions.

The program must:
- Be implemented in a file called **hello.py** inside a folder called `sentimental-hello`.
- Prompt the user for their name.
- Print a personalised greeting in the format: `Hello, so-and-so`, where *so-and-so* is the provided name.

## Approach
This problem focuses on user input and formatted output in Python.  
The skills practiced include:
- Importing and using functions from external libraries (`cs50`).
- Capturing user input as a string.
- Using **f-strings** for string interpolation.
- Applying Python’s indentation and syntax conventions.

---

## My solution

### Description
The program:
- Prompts the user for their name using `get_string()`.
- Prints a greeting message using an **f-string** for clean formatting.

### How to use it
1. Make sure the **CS50 Python library** is installed.
2. Navigate to the corresponding folder.
3. Run the program with: `python hello.py`
4. Enter your name when prompted.

#### Code snippet
```python
from cs50 import get_string

name = get_string("What is your name? ")
print(f"Hello, {name}")
```
