# Problem 4: Tideman

## Project brief
This exercise implements the **Tideman voting method** (also known as ranked pairs), a **ranked-choice voting system** that guarantees the election of the **Condorcet winner** if one exists.  

Unlike plurality voting (where the candidate with the most first-choice votes wins), the Tideman method accounts for voters’ **ranked preferences** and avoids paradoxes where a majority prefers one candidate over the declared winner.  

The program must:  
- Accept a list of **candidates as command-line arguments**.  
- Allow each voter to **rank all candidates in order of preference**.  
- Record preferences as pairwise victories between candidates.  
- **Sort pairs** by strength of victory (margin of preference).  
- **Lock pairs** into a directed graph, ensuring no cycles are created.  
- Declare the winner as the **source of the graph** (a candidate with no edges pointing toward them).  

# Approach
This problem focuses on **structs, arrays, sorting algorithms, recursion, and graph theory**.  

The skills practiced include:  
- Handling **command-line arguments** (candidate names).  
- Using **2D arrays** to store preferences and locked results (adjacency matrices).  
- Implementing and manipulating a **struct array** (`pair`) for head-to-head matchups.  
- Sorting pairs by **strength of victory**.  
- Avoiding **graph cycles** when locking in results.  
- Traversing the graph to find the **winner**.  

---

## My solution

### Description
The program:  
1. Accepts candidate names as command-line arguments.  
2. Prompts each voter to rank all candidates.  
3. Records preferences in a global 2D array.  
4. Builds a list of pairs (winner–loser matchups) and sorts them by margin of victory.  
5. Locks pairs into a graph, skipping any that would create a cycle.  
6. Prints the winner (the candidate with no incoming edges).  

### How to use it
1. Make sure you have the **CS50 library** (and other referenced libraries) installed.  
2. Navigate to the corresponding folder.  
3. Compile with: `make tideman`
4. Run the program with candidate names: `./tideman Alice Bob Charlie`
5. Enter the number of voters when prompted, then rank the candidates in order.
6. The program will determine and print the election’s winner.

#### Code snippet
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Initialise locked graph to false
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
}
```
