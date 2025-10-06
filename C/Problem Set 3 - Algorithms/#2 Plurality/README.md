# Problem 2: Plurality

## Project brief
This exercise implements a program to run a **plurality election** (also known as *first-past-the-post* or *winner take all*).  
Each voter casts one vote for their chosen candidate, and the candidate(s) with the most votes win(s).

The program must:
- Accept **candidate names as command-line arguments** (up to 9).  
- Prompt the user for the number of voters.  
- Allow each voter to type in a candidate’s name.  
- Handle votes case-insensitively.  
- Ignore invalid votes and print `"Invalid vote."`.  
- Tally votes correctly.  
- Print the name(s) of the candidate(s) with the most votes (supporting ties).  

# Approach
This problem focuses on **arrays, structs, string comparison, loops, and tallying votes**.  
The skills practiced include:
- Defining and using **structs** to store candidate data (`name` and `votes`).  
- Handling **command-line arguments** to initialise candidate information.  
- Implementing a `vote` function to update counts if a valid candidate is found.  
- Implementing a `print_winner` function to determine the highest number of votes and print all winners.  
- Using **string comparison** (`strcasecmp`) to allow case-insensitive matching.  
- Iterating over arrays to process votes and find results.  

---

## My solution

### Description
The program:
- Stores candidate names and initialises their vote counts.  
- Prompts the user for the total number of voters.  
- Loops through all voters, prompting each for a vote.  
- Increments the vote count if the candidate is valid, otherwise prints `"Invalid vote."`.  
- Determines the highest number of votes and prints the winner(s).  

### How to use it
1. Make sure you have the CS50 library (and other referenced libraries) installed.  
2. Navigate to the corresponding folder.  
3. Compile with: `make plurality`
4. Run the program with candidate names as arguments, for example: `./plurality Alice Bob Charlie`
5. Enter the number of voters when prompted.
6. Type each voter’s chosen candidate when asked.
7. The program will print the winner(s).

#### Code snippet
```c
// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int highest = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest)
        {
            highest = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

```
