# Problem 2: Readability

## Project brief
This exercise implements a program that determines the approximate U.S. grade level required to understand a given piece of text. The program uses the **Coleman-Liau index**, a readability test based on the average number of letters and sentences per 100 words.  

The program must:
- Prompt the user for a block of text.
- Count the number of letters, words, and sentences in the text.
- Calculate the Coleman-Liau index: `index = 0.0588 * L - 0.296 * S - 15.8`

  where:
  - **L** = average number of letters per 100 words  
  - **S** = average number of sentences per 100 words
  - Output the corresponding grade level:
  - `"Before Grade 1"` if the result is less than 1.
  - `"Grade X"` if the result is between 1 and 15.
  - `"Grade 16+"` if the result is 16 or higher.

---

# Approach
This problem combines **string parsing, character classification, and arithmetic formulas**.  
The skills practiced include:
- Iterating over strings to count letters (`isalpha`), words (spaces + 1), and sentences (punctuation marks like `.`, `!`, `?`).  
- Using helper functions to keep code modular:
  - `countletters` to count alphabetic characters.
  - `countwords` to count words based on spaces.
  - `countsentences` to detect sentence-ending punctuation.
  - `indexcalculation` to apply the Coleman-Liau formula.
- Applying floating-point arithmetic and rounding with `round()`.
- Handling different output cases with conditionals.

---

## My solution

### Description
The program:
1. Prompts the user to input a block of text.  
2. Counts letters, words, and sentences.  
3. Computes averages per 100 words.  
4. Applies the Coleman-Liau formula to determine readability.  
5. Prints the grade level in the correct format.  

### How to use it
1. Make sure you have the CS50 library (and other libraries needed) installed.  
2. Navigate to the corresponding folder.
3. Compile with: `make readability`
4. Run the program: `./readability`
5. Input a text passage when prompted.

#### Code snippet
```c
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countletters(string text);
int countwords(string text);
int countsentences(string text);
float indexcalculation(float letters, float sentences);

int main(void)
{
    // Take the text
    string text = get_string("Text: \n");

    int letters = countletters(text);
    int sentences = countsentences(text);
    int words = countwords(text);

    // Calculate (L) average number of letters per 100 words
    float average_letters = (float) letters / words * 100;
    // Calculate (S) average number of sentences per 100 words
    float average_sentences = (float) sentences / words * 100;

    int index = indexcalculation(average_letters, average_sentences);

    // Print result
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (1 < index && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

// Count letters
int countletters(string text)
{
    int lettercount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            lettercount += 1;
        }
    }
    return lettercount;
}

// Count spaces and words (assuming words = spaces + 1)
int countwords(string text)
{
    int spacecount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            spacecount += 1;
        }
    }
    int wordcount = spacecount + 1;
    return wordcount;
}

// Count sentences
int countsentences(string text)
{
    int sentencecount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentencecount += 1;
        }
    }
    return sentencecount;
}

// Calculate readability using formula
float indexcalculation(float letters, float sentences)
{
    float index = 0.0588 * letters - 0.296 * sentences - 15.8;
    return round(index);
}
```
