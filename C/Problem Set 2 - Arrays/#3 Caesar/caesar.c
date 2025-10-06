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
