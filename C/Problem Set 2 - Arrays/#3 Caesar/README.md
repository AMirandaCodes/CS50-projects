# Problem 3: Caesar

## Project brief
This exercise implements **Caesar’s cipher**, one of the earliest encryption techniques. The program encrypts text by shifting each alphabetical character by a fixed number of positions (the key). Case is preserved, and non-alphabetical characters remain unchanged.

The program must:
- Accept exactly **one command-line argument** (the key, a non-negative integer).  
- Validate that the key contains only digits.  
- Print a usage message and exit with status `1` if:  
  - No argument is provided.  
  - More than one argument is provided.  
  - The key is not a valid number.  
- Prompt the user for plaintext.  
- Output the corresponding ciphertext, where each letter is shifted by the key.  
- Preserve case (uppercase stays uppercase, lowercase stays lowercase).  
- Ignore non-alphabetical characters (they remain unchanged).

# Approach
This problem focuses on **command-line arguments, input validation, string manipulation, and modular arithmetic**.  
The skills practiced include:
- Parsing command-line arguments (`argv`, `argc`).  
- Checking that input is numeric (`isdigit`).  
- Converting string input into an integer (`atoi`).  
- Using modular arithmetic (`% 26`) to handle alphabet wrapping.  
- Preserving uppercase and lowercase letters using `isupper` and `islower`.  
- Traversing strings with loops and manipulating characters.  

## My solution

### Description
The program:
- Accepts the key as a command-line argument.  
- Ensures the key is valid and positive.  
- Prompts the user for plaintext.  
- Applies Caesar’s cipher to generate ciphertext.  
- Prints the encrypted message while leaving non-letter characters unchanged.  

### How to use it
1. Make sure you have the CS50 library (and other referenced libraries) installed.  
2. Navigate to the corresponding folder.  
3. Compile with: *make caesar*  
4. Run the program with a key: *./caesar*  
5. Enter plaintext when prompted.  

#### Code snippet
```c
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
string createciphertext(string plaintext, int key);

int main(int argc, string argv[])
{
    // One, or more than 2 command-line arguments prints usage message
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check all characters of argv[1] is a digit (if not, print usage message)
    string key_str = argv[1];
    bool is_key_just_digits = only_digits(key_str);
    if (is_key_just_digits == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from string to integer
    int key = atoi(key_str);

    // Checks if key is positive (no upper limit)
    if (key <= 0)
    {
        printf("Needs to be positive\n");
        return 1;
    }

    // Prompts user for plaintext
    string plaintext = get_string("plaintext: ");

    // Rotates each character of plaintext
    string ciphertext = createciphertext(plaintext, key);

    // Prints the c (ciphertext)
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Checks the key is only digits
bool only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotates each character of plaintext if it's a letter (keeping letter casing)
string createciphertext(string plaintext, int key)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // (plaintext [i]) - 'A' converts ASCII to alphabetical index. The + 'A' converts result
            // back to ASCII
            if (isupper(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
    return plaintext;
}
```
