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
