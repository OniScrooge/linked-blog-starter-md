# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.8 Finding the Closest Pair of Points using Divide-and-Conquer]]

Next - [[COSC Chapter 18.10 Case Study - Finding a Convex Hull]]
# Content

## Key Note
This section solves the Eight Queens problem using the [[backtracking]] approach.

The Eight Queens problem, introduced in **Section 17.7**, is to find a solution to place a queen in each row on a chessboard such that no two queens can attack each other. The problem was solved using recursion. In this section, we will introduce a common algorithm design technique called [[backtracking]] for solving this problem. 

>[!note] Algorithm Design Note
>There are many possible candidates. How do you find a solution? The [[backtracking]] approach searches for a candidate solution incrementally, abandoning that option as soon as it determines that the candidate cannot possibly be a valid solution, and then looks for a new candidate. 

We use a one-dimensional array to represent a chessboard.
```cpp
int queens[8]; 
```

Assign `j` to `queens[i]` to denote that a queen is placed in row `i` and column `j`. Assign `-1` to `queens[i]` to denote that row i has no queen placed yet.

The **search** starts from the first row with _k_ = 0, where _k_ is the index of the current row being considered. The algorithm checks whether a queen can be possibly placed in the _j_th column in the row for _j_ = 0, 1, ..., 7, in this order. The search is implemented as follows:
- If successful, it continues to search for a placement for a queen in the next row. If the current row is the last row, a solution is found.
- If not successful, it backtracks to the previous row and continues to search for a new placement in the next column in the previous row.
- If the algorithm backtracks to the first row and cannot find a new placement for a queen in this row, no solution can be found.

Here is an animation to show how the algorithm works
## Eight Queen Solution
```cpp
#include <iostream>
using namespace std;

const int NUMBER_OF_QUEENS = 8; // Constant: eight queens
// queens are placed at (i, queens[i])
// -1 indicates that no queen is currently placed in the ith row
// Initially, place a queen at (0, 0) in the 0th row
int queens[NUMBER_OF_QUEENS] = {-1, -1, -1, -1, -1, -1, -1, -1};

// Check whether a queen can be placed at row i and column j 
bool isValid(int row, int column)
{
  for (int i = 1; i <= row; i++)
    if (queens[row - i] == column       // Check column
      || queens[row - i] == column - i  // Check upper left diagonal
      || queens[row - i] == column + i) // Check upper right diagonal
      return false; // There is a conflict
  return true; // No conflict
}

// Display the chessboard with eight queens 
void printResult()
{
  cout << "\n---------------------------------\n";
  for (int row = 0; row < NUMBER_OF_QUEENS; row++)
  {
    for (int column = 0; column < NUMBER_OF_QUEENS; column++)
      printf(column == queens[row] ? "| Q " : "|   ");
    cout << "|\n---------------------------------\n";
  }
}

// Find a position to place a queen in row k
int findPosition(int k) 
{
  int start = queens[k] + 1; // Search for a new placement

  for (int j = start; j < NUMBER_OF_QUEENS; j++)
  {
    if (isValid(k, j))
      return j; // (k, j) is the place to put the queen now
  }

  return -1;
}

// Search for a solution 
bool search() 
{
  // k - 1 indicates the number of queens placed so far
  // We are looking for a position in the kth row to place a queen
  int k = 0;
  while (k >= 0 && k < NUMBER_OF_QUEENS)
  {
    // Find a position to place a queen in the kth row
    int j = findPosition(k);
    if (j < 0) 
    {
      queens[k] = -1;
      k--; // back track to the previous row
    } 
    else 
    {
      queens[k] = j;
      k++;
    }
  }
    
  if (k == -1)
    return false; // No solution
  else
    return true; // A solution is found
}

int main()
{
  search(); // Start search from row 0. Note row indices are 0 to 7
  printResult(); // Display result

  return 0;
}
```
```
command>cl EightQueenBacktracking.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>EightQueenBacktracking 

---------------------------------
| Q |   |   |   |   |   |   |   |
---------------------------------
|   |   |   |   | Q |   |   |   |
---------------------------------
|   |   |   |   |   |   |   | Q |
---------------------------------
|   |   |   |   |   | Q |   |   |
---------------------------------
|   |   | Q |   |   |   |   |   |
---------------------------------
|   |   |   |   |   |   | Q |   |
---------------------------------
|   | Q |   |   |   |   |   |   |
---------------------------------
|   |   |   | Q |   |   |   |   |
---------------------------------

command>
```

The program invokes `search()` (line 77) to search for a solution. Initially, no queens are placed in any rows (line 8). The search now starts from the first row with `k = 0` (line 52) and finds a place for the queen (line 56). If successful, place it in the row (line 64) and consider the next row (line 65). If not successful, backtrack to the previous row (lines 59–60).

The `findPosition(k)` [[function]] searches for a possible position to place a queen in row `k` starting from `queen[k] + 1` (line 36). It checks whether a queen can be placed at `start`, `start + 1`, ..., and `7`, in this order (lines 38–42). If possible, return the column index (line 41); otherwise, return `-1` (line 44).

The `isValid(row, column)` [[function]] is called to check whether placing a queen at the specified position causes a conflict with the queens placed earlier (line 40). It ensures that no queen is placed in the same column (line 14), in the upper-left diagonal (line 15), or in the upper-right diagonal (line 16), as show​n in **Figure 18.6**.​

>[!info] Figure 18.6
>![[Pasted image 20241022131906.png]]

## Self-Check

### What is [[backtracking]]? Give an example.

![[backtracking]]

### If you generalize the Eight Queens problem to the n-Queens problem in an n-by-n chessboard, what will be the complexity of the algorithm?

O(n!)
# References
