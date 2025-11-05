# Problem 7: DNA

## Project brief
This exercise implements a Python program that identifies to whom a DNA sequence belongs, based on Short Tandem Repeats (STRs).  
It replicates the functionality of the “DNA” problem from CS50’s C version, using Python’s file handling and dictionary features.

The program must:
- Be implemented in a file called **dna.py**.
- Take **two command-line arguments**:
  1. A CSV file containing individuals’ STR counts.
  2. A text file containing a DNA sequence.
- Compare the longest runs of each STR in the DNA sequence to those in the database.
- Print the person’s name if there is a match, or `"No match"` otherwise.

## Approach
This problem focuses on **file reading**, **data parsing**, and **pattern matching** in Python.  
The skills practiced include:
- Reading and parsing CSV files with `csv.DictReader`.
- Reading plain text files with `open()` and `.read()`.
- Using dictionaries to store STR counts.
- Implementing a search function (`longest_match`) to find consecutive STR repetitions.
- Comparing computed STR counts against database records.

---

## My solution

### Description
The program:
1. Validates that exactly two command-line arguments are provided.  
2. Reads the database CSV into memory as a list of dictionaries.  
3. Reads the DNA sequence text file into memory.  
4. For each STR in the database, computes the **longest consecutive run** in the DNA sequence.  
5. Compares the STR counts to each person’s data to find a match.  
6. Outputs the corresponding name or `"No match"`.

### How to use it
1. Ensure Python 3 is installed.  
2. Place the database (`data.csv`) and sequence (`sequence.txt`) files in the same folder as `dna.py`.  
3. Run the program from the terminal: `python dna.py data.csv sequence.txt`

#### Code snippet
```python
import csv
import sys

def main():

    # Check for correct command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file
    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        str_names = reader.fieldnames[1:]
        for row in reader:
            rows.append(row)

    # Read DNA sequence file
    with open(sys.argv[2]) as f:
        dna_sequence = f.read().strip()

    # Compute longest run of each STR
    counts = {str_seq: longest_match(dna_sequence, str_seq) for str_seq in str_names}

    # Check database for matching profiles
    for person in rows:
        if all(int(person[s]) == counts[s] for s in str_names):
            print(person["name"])
            sys.exit(0)

    print("No match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    sub_len = len(subsequence)
    seq_len = len(sequence)

    for i in range(seq_len):
        count = 0
        while True:
            start = i + count * sub_len
            end = start + sub_len
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)

    return longest_run

main()

```
  
