# Problem 4: Substitution

## Project brief
This exercise implements a **substitution cipher**, where each letter of the alphabet is replaced with a corresponding letter from a given key. The program encrypts a message using a 26-character substitution key provided as a command-line argument. Case is preserved, and non-alphabetical characters remain unchanged.

The program must:
- Accept exactly **one command-line argument**, the key.  
- Validate that the key:
  - Contains exactly 26 characters.  
  - Contains only alphabetic characters.  
  - Contains each letter of the alphabet exactly once (case-insensitive).  
- Print an error message and return `1` if the key is invalid or the wrong number of arguments is provided.  
- Prompt the user for plaintext.  
- Output the corresponding ciphertext using the substitution key.  
- Preserve case (uppercase stays uppercase, lowercase stays lowercase).  
- Leave non-alphabetic characters unchanged.  

# Approach
This problem focuses on **command-line arguments, input validation, character mapping, and case handling**.  
The skills practiced include:
- Parsing command-line arguments (`argv`, `argc`).  
- Validating user input against multiple constraints.  
- Using arrays and boolean tracking (`seen[]`) to detect duplicates.  
- Applying substitution logic by mapping characters A–Z (or a–z) to indices 0–25.  
- Preserving case using `toupper` and `tolower`.  
- Traversing and manipulating strings in C with loops.  

## My solution

### Description
The program:
- Accepts a key as a command-line argument.  
- Ensures the key is valid (26 unique letters, alphabetic only).  
- Prompts the user for plaintext.  
- Substitutes each alphabetical character using the key.  
- Outputs the ciphertext while leaving other characters unchanged.  

### How to use it
1. Make sure you have the CS50 library (and other referenced libraries) installed.  
2. Navigate to the corresponding folder.  
3. Compile with: *make substitution*  
4. Run the program with a valid key: *./substitution NQXPOMAFTRHLZGECYJIUWSKDVB*  
5. Enter plaintext when prompted.  

#### Example
```bash
$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext: Hello, World!
ciphertext: Ehbbq, Qzmbo!

$ ./substitution
Usage: ./substitution key

$ ./substitution ABCDEFG
Key must contain 26 characters
```

#### Code snippet
```c
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_only_alphabetical(string key);
bool are_different_letters(string key);
string makesubstitution(string plaintext, string key);

int main(int argc, string argv[])
{
    // If 1 or more than 2 arguments, prints usage instructions
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Defining argv[2] as the key
    string key = argv[1];

    // Checks key is alphabetical only. Prints usage instructions if not.
    if (is_only_alphabetical(key) == false)
    {
        printf("Key must be all letters\n");
        return 1;
    }

    // Checks all letters in key are different. Prints error message if not.
    if (are_different_letters(key) == false)
    {
        printf("All letters must be different\n");
        return 1;
    }

    // Checks key is exactly 26 characters (case insensitive)
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // Print ciphertext
    string ciphertext = makesubstitution(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Checks key is alphabeitcal only
bool is_only_alphabetical(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}

bool are_different_letters(string key)
{
    bool seen[26] = {false};
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }
    return true;
}

// Substitute each character with the corresponding one from the key
string makesubstitution(string plaintext, string key)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                // Maps A–Z to 0–25
                int index = plaintext[i] - 'A';
                // Subtitutes with key
                plaintext[i] = toupper(key[index]);
            }
            if (islower(plaintext[i]))
            {
                // Maps a-z to 0-25
                int index = plaintext[i] - 'a';
                // Substitutes with key
                plaintext[i] = tolower(key[index]);
            }
        }
    }
    return plaintext;
}

```
