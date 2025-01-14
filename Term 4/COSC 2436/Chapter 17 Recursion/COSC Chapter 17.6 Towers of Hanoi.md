# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.5 Recursive Helper Functions]]

Next - [[COSC Chapter 17.7 Eight Queens]]
# Content
## Key Point
The classic Tower of Hanoi problem can be solved easily using recursion, but it is difficult to solve otherwise.

The Tower of Hanoi problem is a classic recursion example. It can be solved easily using recursion but is difficult to solve otherwise.

The problem involves moving a specified number of disks of distinct sizes from one tower to another while observing the following rules:
- There are _n_ disks labeled 1, 2, 3, . . ., _n_, and three towers labeled A, B, and C.
- No disk can be on top of a smaller disk at any time.
- All the disks are initially placed on tower A.
- Only one disk can be moved at a time, and it must be the top disk on the tower.

The objective is to move all the disks from A to B with the assistance of C. For example, if you have three disks, the steps to move all of the disks from A to B are shown in **Figure 17.4**.

In the case of three disks, you can find the solution manually. For a larger number of disks, however—even for four—the problem is quite complex. Fortunately, the problem has an inherently recursive nature, which leads to a straightforward recursive solution.

The [[base case]] for the problem is `n = 1`. If `n == 1`, you could simply move the disk from A to B. When `n > 1`, you could split the original problem into three subproblems and solve them sequentially:
1. Move the first `n - 1` disks recursively from A to C recursively with the assistance of tower B, as shown in Step 1 in **​Figure 17.5**​.
2. Move disk `n` from A to B, as shown in Step 2 in **Figure 17.6**.
3. Move `n - 1` disks recursively from C to B recursively with the assistance of tower A, as shown in Step 3 in **​Figure 17.5**​.

>[!note] Figure 17.5
>![[ch17fig06a.png]]

The following [[function]] moves _n_ disks from the `fromTower` to the `toTower` with the assistance of the `auxTower`:

```cpp
void moveDisks(int n, char fromTower, char toTower, char auxTower) 
```

The algorithm for the [[function]] can be described as follows:

```cpp
if (n == 1) // Stopping condition 
  Move disk 1 from the fromTower to the toTower; 
else 
{ 
  moveDisks(n - 1, fromTower, auxTower, toTower); 
  Move disk n from the fromTower to the toTower; 
  moveDisks(n - 1, auxTower, toTower, fromTower); 
} 
```

**LiveExample 17.7** prompts the user to enter the number of disks and invokes the [[recursive function]] `moveDisks` to display the solution for moving the disks.

## **LiveExample 17.7 TowerOfHanoi.cpp**
```cpp
#include <iostream>
using namespace std;

// The function for finding the solution to move n disks
// from fromTower to toTower with auxTower 
void moveDisks(int n, char fromTower,
    char toTower, char auxTower)
{
  if (n == 1) // Stopping condition
    cout << "Move disk " << n << " from " <<
      fromTower << " to " << toTower << endl;
  else
  {
    moveDisks(n - 1, fromTower, auxTower, toTower);
    cout << "Move disk " << n << " from " <<
      fromTower << " to " << toTower << endl;
    moveDisks(n - 1, auxTower, toTower, fromTower);
  }
}

int main()
{
  // Read number of disks, n
  cout << "Enter number of disks: ";
  int n;
  cin >> n;

  // Find the solution recursively
  cout << "The moves are: " << endl;
  moveDisks(n, 'A', 'B', 'C');

  return 0;
}
```
```
command>cl TowerOfHanoi.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TowerOfHanoi 
Enter number of disks: 3
The moves are: 
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
Move disk 3 from A to B
Move disk 1 from C to A
Move disk 2 from C to B
Move disk 1 from A to B

command>
```

This problem is inherently recursive. Using recursion makes it possible to find a natural, simple solution. It would be difficult to solve the problem without using recursion.

Consider tracing the program for `n = 3`. The successive recursive calls are shown in **​Figure 17.6**​. As you can see, writing the program is easier than tracing the recursive calls. The system uses stacks to trace the calls behind the scenes. To some extent, recursion provides a level of abstraction that hides iterations and other details from the user.

>[!note] Figure 17.6
>![[Pasted image 20241105193208.png]]

## Self-Check
### How many times is the moveDisks [[function]] in __LiveExample 17.7__ invoked for `moveDisks(5, 'A', 'B', 'C')`?

The moveDisks [[function]] is called $2^{n - 1}$ times for n number of the disks. So, for five disks, it is $2^{5 - 1}$
# References
