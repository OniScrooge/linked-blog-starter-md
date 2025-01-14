# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.6 Towers of Hanoi]]

Next - [[COSC Chapter 17.8 Recursion vs Iteration]]
# Content
## Key Point

The Eight Queens problem can be solved using recursion.

This section gives a recursive solution to the Eight Queens problem. The task is to place a queen in each row on a chessboard in such a way that no two queens can attack each other. You may use a two-dimensional array to represent a chessboard. However, since each row can have only one queen, it is sufficient to use a one-dimensional array to denote the position of the queen in the row. So, let us declare array `queens` as follows:

```cpp
int queens[8]; 
```

Assign `j` to `queens[i]` to denote that a queen is placed in row `i` and column `j`, as shown in **Figure 17.7**. Assign -1 to queens[i] to denote that row i has no queen placed yet.

**LiveExample 17.8** is a program that finds a solution for the Eight Queens problem.

## **LiveExample 17.8 EightQueen.cpp**
```cpp
#include <iostream>
using namespace std;

const int NUMBER_OF_QUEENS = 8; // Constant: eight queens
int queens[NUMBER_OF_QUEENS];

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

// Search to place a queen at the specified row 
bool search(int row)
{
  if (row == NUMBER_OF_QUEENS) // Stopping condition
    return true; // A solution found to place 8 queens in 8 rows

  for (int column = 0; column < NUMBER_OF_QUEENS; column++)
  {
    queens[row] = column; // Place a queen at (row, column)
    if (isValid(row, column) && search(row + 1))
      return true; // Found, thus return true to exit for loop
  }

  // No solution for a queen placed at any column of this row
  return false;
}

int main()
{
  search(0); // Start search from row 0. Note row indices are 0 to 7
  printResult(); // Display result

  return 0;
}
```
```
command>cl EightQueen.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>EightQueen 

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

The program invokes `search(0)` (line 49) to start a search for a solution at row `0`, which recursively invokes `search(1)`, `search(2)`, ..., and `search(7)` (line 39).

The recursive `search(row)` [[function]] returns `true` if all row are filled (lines 39–40). The [[function]] checks whether a queen can be placed in column `0`, `1`, `2`, ..., and `7` in a `for` loop (line 36). Place a queen in the column (line 38). If the placement is valid, recursively search for the next row by invoking `search(row + 1)` (line 39). If search is successful, return `true` (line 40) to exit the `for` loop. In this case, there is no need to look for the next column in the row. If there is no solution for a queen to be placed on any column of this row, the [[function]] returns `false` (line 44).

Suppose you invoke `search(row)` for `row` is `3`, as shown in **Figure 17.8**. The [[function]] tries to fill in a queen in column `0`, `1`, `2`, and so on in this order. For each trial, the `isValid(row, column)` [[function]] (line 39) is called to check whether placing a queen at the specified position causes a conflict with the queens placed before this row. It ensures that no queen is placed in the same column (line 11), no queen is placed in the upper left diagonal (line 12), and no queen is placed in the upper right diagonal (line 13), as shown in **Figure 17.8**. If `isValid(row, column)` returns `false`, check the next column. If `isValid(row, column)` returns `true`, recursively invoke `search(row + 1)`. If `search(row + 1)` returns `false`, check the next column on the preceding row.

>[!note] Figure 17.8
>![[Pasted image 20241105193503.png]]
## Self-Check
### Given the array "`int queens[8]`" as in __LiveExample 17.8__, write the code that assigns true to bool variable `hasAQueen` if there is a queen at the upper-left diagonal at `[row, column]`.
```cpp
hasAQueen = false;
for (int i = 1; i <= row; i++)
  if (queens[row - i] == column + i) 
  { 
    hasAQueen = true;   
    break;
  }        
}
```

### Which of the following statements is true?
1. Assigning j to queens[i] to denote that a queen is placed in row i and column j.
2. Invoking search(0) searches for a queen placement solution for the entire board.
3. Invoking search(i) searches for a queen placement solution in row i and in the process it finds the solution for all rows after i.
4. Invoking isValid(i, j) tests if there is a queen at the upper-left diagonal from (i, j), upper-right diagonal from (i, j), and at the j's column.
5. All of the above.

#### Answer
All of the above

# References
