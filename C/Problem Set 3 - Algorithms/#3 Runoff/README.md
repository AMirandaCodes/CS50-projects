# Problem 3: Runoff  

## Project brief  
This exercise implements a **ranked-choice voting system** (also known as **instant runoff voting**). Unlike a simple plurality vote (where the candidate with the most votes wins), ranked-choice voting allows voters to rank candidates in order of preference.  

The program simulates the runoff election process:  
- Each voter ranks the candidates.  
- If a candidate has a **majority (>50%) of first-choice votes**, they win.  
- If no candidate has a majority, the **candidate(s) with the fewest votes are eliminated**.  
- Voters who ranked the eliminated candidate first will instead contribute their vote to their next preferred candidate.  
- The process repeats until a candidate wins or all remaining candidates are tied.  

The program must:  
- Accept candidate names as **command-line arguments**.  
- Prompt for the number of voters and their ranked choices.  
- Reject invalid votes.  
- Simulate the runoff election until a winner is found or a tie is declared.  

## Approach  
This problem focuses on **structs, arrays (1D & 2D), loops, conditionals, and simulation of an iterative algorithm**.  

The skills practiced include:  
- Defining and using `struct` to represent candidates.  
- Tracking preferences with a **2D array** (`preferences[i][j]`).  
- Validating input against candidate names.  
- Implementing the election process with functions for:  
  - Recording votes (`vote`).  
  - Counting votes (`tabulate`).  
  - Checking for majority winner (`print_winner`).  
  - Finding minimum votes (`find_min`).  
  - Checking ties (`is_tie`).  
  - Eliminating candidates (`eliminate`).  
- Resetting and updating votes dynamically across multiple rounds.  

---

## My solution  

### Description  
The program:  
- Accepts candidate names as command-line arguments.  
- Records each voter’s ranked preferences.  
- Repeatedly tabulates votes, eliminating candidates with the fewest votes until one has a majority or a tie occurs.  
- Prints the winner (or all tied candidates).  

### How to use it  
1. Ensure you have the CS50 library (and other required libraries) installed.  
2. Navigate to the corresponding folder.  
3. Compile the program: `make runoff`
4. Run the program with candidate names as arguments: `./runoff Alice Bob Charlie`
5. Enter the number of voters when prompted, then each voter’s ranked preferences.
6. The program will output the winner (or declare a tie).

#### Code snippet
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
```
_(Full implementation in `runoff.c`)_
