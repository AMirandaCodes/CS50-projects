# Problem 1: Sort

## Project brief
This exercise involved analysing three compiled programs (`sort1`, `sort2`, `sort3`) to determine which sorting algorithm each one implemented.  
The possible algorithms were:
- **Selection sort** – repeatedly selects the smallest element and swaps it into place.
- **Bubble sort** – repeatedly compares adjacent elements and swaps them if out of order.
- **Merge sort** – recursively divides the list, sorts sublists, and merges them back together.

The task was to run each program on different input files, compare their runtimes, and deduce which algorithm they used. The results were recorded in `answers.txt`.

## Approach
This problem focused on **algorithm analysis, time complexity, and experimental testing**.  
The skills practiced included:
- Running compiled programs with different datasets.
- Measuring runtime with the `time` command in the terminal.
- Comparing runtime behavior across sorted, reversed, and random lists.
- Applying theoretical knowledge of algorithm complexity (`O(n^2)` vs. `O(n log n)`).

## My solution

### Description
To identify each algorithm:
1. I ran the programs with input files of different sizes (5,000; 10,000; and 50,000 numbers).
2. I tested with three configurations of input: **sorted**, **reversed**, and **random**.
3. I measured execution times using the `time` command.
4. I compared performance patterns against expected algorithm behaviors.

- **Bubble sort** is slower with reversed or random inputs, but faster if the list is already sorted (because it can stop early).
- **Selection sort** always takes about the same time regardless of input order, but grows significantly with larger lists.
- **Merge sort** is consistently the fastest, even on large and disordered inputs.

### Results
- **`sort1` → Bubble sort**  
  - Runs much slower on reversed and random lists (up to 6.6s on 50,000 random numbers).  
  - Runs faster on already sorted lists compared to `sort3`.  

- **`sort2` → Merge sort**  
  - Always the fastest algorithm overall.  
  - Scales efficiently to 50,000 numbers with runtimes under half a second.  

- **`sort3` → Selection sort**  
  - Performance is consistent regardless of input order, but significantly slower than `sort2`.  
  - Takes ~2.9s on 50,000 numbers, which is worse than bubble sort for sorted inputs.  

### Final answers
- `sort1`: **Bubble sort**  
- `sort2`: **Merge sort**  
- `sort3`: **Selection sort**
