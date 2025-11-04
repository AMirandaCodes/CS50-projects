# Problem 6: Readability

## Project brief
This program determines the **reading grade level** of a given text using the **Coleman–Liau index**, implemented in Python.  
It replicates the logic of the *Readability* problem from CS50’s C version.

The program must:
- Be implemented in a file called **readability.py**.
- Prompt the user for a block of text.
- Count the number of **letters**, **words**, and **sentences**.
- Calculate the grade level using the **Coleman–Liau formula**.
- Output the result as:
  - `Grade X` for grade levels 1–15  
  - `Grade 16+` for levels ≥ 16  
  - `Before Grade 1` for levels < 1  

## Approach
This problem focuses on **text processing**, **string iteration**, and **mathematical computation** in Python.  
The key skills practiced include:
- Counting characters and words using string methods.
- Applying conditional logic and arithmetic formulas.
- Using formatted output and control flow in Python.

**Coleman–Liau formula:**
`index = 0.0588 * L - 0.296 * S - 15.8`
where:
- **L** = average number of letters per 100 words  
- **S** = average number of sentences per 100 words  

The program counts:
- **Letters** → alphabetic characters (A–Z, a–z).  
- **Words** → separated by spaces.  
- **Sentences** → end with `.`, `!`, or `?`.

---

## My solution

### Description
The program:
- Prompts the user for input text using `get_string()`.
- Counts **letters**, **words**, and **sentences**.
- Calculates **L** and **S** averages.
- Applies the **Coleman–Liau formula**.
- Prints the corresponding grade level message.

### How to use it
1. Ensure the **CS50 Python library** is installed: `pip install cs50`
2. Navigate to the corresponding folder.
3. Run the program: `python readability.py`
4. Type or paste the text when prompted.

#### Code snippet
```python
from cs50 import get_string

text = get_string("Text: ")

# Count number of letters and sentences
letters = sum(1 for character in text if character.isalpha())
sentences = text.count(".") + text.count("?") + text.count("!")

# Calculate averages per 100 words
words = len(text.split())
L = (letters / words) * 100
S = (sentences / words) * 100

# Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8

# Print result
if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
```
