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

// Score system
// 1 = (A, E, I, L, N, O, R, S, T, U)
// 2 = (D, G)
// 3 = (B, C, M, P)
// 4 = (F, H, V, W, Y)
// 5 = (K)
// 8 = (J, X)
// 10 = (Q, Z)

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
