# Problem 1: Scrabble

## Project brief
This exercise implements a simplified version of the game **Scrabble**, where two players input words and the program computes their scores based on Scrabble’s letter values. The program then declares the winner or a tie.

The program must:
- Prompt two players for words.
- Calculate the score of each word using the Scrabble scoring system:
  - 1 point: A, E, I, L, N, O, R, S, T, U  
  - 2 points: D, G  
  - 3 points: B, C, M, P  
  - 4 points: F, H, V, W, Y  
  - 5 points: K  
  - 8 points: J, X  
  - 10 points: Q, Z
- Output whether Player 1 wins, Player 2 wins, or if it’s a tie.

# Approach
This problem focuses on **arrays, conditionals, and string manipulation**.  
The skills practiced include:
- Traversing a string with `for` loops.
- Converting characters to uppercase for consistent scoring (`toupper`).
- Comparing characters against predefined sets of letters.
- Maintaining a cumulative score for each player.
- Using conditional logic to compare final scores and determine the winner.

## My solution

### Description
The program:
- Prompts both players to input a word.  
- Computes the score for each word by summing the point values of all letters.  
- Declares which player wins or if the result is a tie.  

### How to use it
1. Make sure you have the CS50 library (and other referenced libraries) installed. 
2. Navigate to the corresponding folder.  
3. Compile with: *make scrabble*
4. Run the program: *./scrabble*
5. Enter words for Player 1 and Player 2 when prompted.

#### Code snippet
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int wordscore(string word);

int main(void)
{
    // Ask Player 1 and Player 2 for a word
    string player1_word = get_string("Player 1: \n");
    string player2_word = get_string("Player 2: \n");

    // Get scores of each player
    int score_1 = wordscore(player1_word);
    int score_2 = wordscore(player2_word);

    // Print winner
    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    if (score_1 == score_2)
    {
        printf("Tie!\n");
    }
}

// Calculates score of a word
int wordscore(string word)
{
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Makes the letter uppercase
        char l = toupper(word[i]);

        // Checks what letter it is and assigns the corresponding score
        if (l == 'A' || l == 'E' || l == 'I' || l == 'L' || l == 'N' || l == 'O' || l == 'R' ||
            l == 'S' || l == 'T' || l == 'U')
        {
            score += 1;
        }
        else if (l == 'D' || l == 'G')
        {
            score += 2;
        }
        else if (l == 'B' || l == 'C' || l == 'M' || l == 'P')
        {
            score += 3;
        }
        else if (l == 'F' || l == 'H' || l == 'V' || l == 'W' || l == 'Y')
        {
            score += 4;
        }
        else if (l == 'K')
        {
            score += 5;
        }
        else if (l == 'J' || l == 'X')
        {
            score += 8;
        }
        else if (l == 'Q' || l == 'Z')
        {
            score += 10;
        }
    }
    return score;
}

```
