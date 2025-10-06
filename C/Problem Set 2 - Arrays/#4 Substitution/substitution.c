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
