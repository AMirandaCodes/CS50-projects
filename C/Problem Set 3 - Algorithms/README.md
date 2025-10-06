## Module 3 – Algorithms

This module introduced fundamental algorithms for sorting and election systems, exploring both their implementation in C and their real-world applications.  
The assignments developed skills in algorithm analysis, data structures, recursion, and problem decomposition.

---

### Problem set 3
#### 1. Sort

- **Task**: Analyse three pre-compiled sorting programs (`sort1`, `sort2`, `sort3`) and determine whether each uses selection sort, bubble sort, or merge sort. Record the answers and justifications in `answers.txt`.
- **Concepts**: Algorithm identification, runtime behavior, sorting strategies (selection, bubble, merge), efficiency analysis.

#### 2. Plurality

- **Task**: Implement a program that simulates a plurality election where each voter votes for one candidate. Count votes and print the candidate(s) with the most votes.
- **Concepts**: Arrays of structs, string comparison, updating counters, handling ties, function implementation (`vote`, `print_winner`).

#### 3. Runoff

- **Task**: Create a program that simulates an instant runoff election using ranked-choice voting. Repeatedly eliminate the candidate with the fewest votes until a winner emerges or a tie occurs.
- **Concepts**: Two-dimensional arrays, recursion through elimination rounds, dynamic vote redistribution, implementing multiple functions (`vote`, `tabulate`, `print_winner`, `find_min`, `is_tie`, `eliminate`).

#### 4. Tideman

- **Task**: Implement the Tideman (ranked pairs) election method. Build a directed graph of candidate victories, lock in strongest pairs without creating cycles, and determine the election winner.
- **Concepts**: Graph theory (adjacency matrices), cycle detection, sorting pairs by strength of victory, advanced use of structs, algorithmic design.
