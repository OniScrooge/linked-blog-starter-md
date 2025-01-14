# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.4 Analyzing Algorithmic Time Complexity]]

Next - [[COSC Chapter 18.6 Finding Greatest Common Divisors Using Euclid's Algorithm]]
# Content

## Key Point

This section analyzes and designs an efficient algorithm for finding Fibonacci numbers using [[dynamic programming]].

**Section 17.3**, Case Study: Fibonacci Numbers, gave a recursive [[function]] for finding the Fibonacci number, The recursive [[function]] for finding the Fibonacci number is as follows:
```cpp
// The function for finding the Fibonacci number 
long fib(long index) 
{ 
  if (index == 0) // Base case 
    return 0; 
  else if (index == 1) // Base case 
    return 1; 
  else  // Reduction and recursive calls 
    return fib(index - 1) + fib(index - 2); 
} 
```

We can now prove that the complexity of this algorithm is _O_(2_n_). For convenience, let the index be _n_. Let _T_(_n_) denote the complexity for the algorithm that finds fib(_n_) and _c_ denote the [[constant time]] for comparing the index with `0` and `1`. Thus:
$$T(n)=T(n-1)+T(n-2)+c$$
$$\leq 2T(n-1)+c$$
$$\leq 2(2T(n-2)+c)+c$$
$$=2^2T(n-2)+2c+c$$

Similar to the analysis of the Towers of Hanoi problem, we can show that _T_(_n_) is _O_(2_n_).

However, this algorithm is not efficient. Is there an efficient algorithm for finding a Fibonacci number? The trouble with the recursive `fib` [[function]] is that the [[function]] is invoked redundantly with the same arguments. For example, to compute `fib(4)`, `fib(3)` and `fib(2)` are invoked. To compute `fib(3)`, `fib(2)` and `fib(1)` are invoked. Note that `fib(2)` is redundantly invoked. We can improve it by avoiding repeated calling of the `fib` [[function]] with the same argument. Note that a new Fibonacci number is obtained by adding the preceding two numbers in the sequence. If you use the two variables `f0` and `f1` to store the two preceding numbers, the new number, `f2`, can be immediately obtained by adding `f0` with `f1`. Now you should update `f0` and `f1` by assigning `f1` to `f0` and assigning `f2` to `f1`, as shown in **Figure 18.2**.

>[!info] Figure 18.2
>![[Pasted image 20241022113737.png]]

The new [[function]] is implemented in **​LiveExample 18.2**​.

## **LiveExample 18.2 ImprovedFibonacci.cpp**
```cpp
#include <iostream>
using namespace std;

// The function for finding the Fibonacci number
int fib(int);

int main()
{
  // Prompt the user to enter an integer
  cout <<  "Enter an index for the Fibonacci number: ";
  int index;
  cin >> index;

  // Display factorial
  cout << "Fibonacci number at index " << index << " is "
    << fib(index) << endl;

  return 0;
}

// The function for finding the Fibonacci number
int fib(int n)
{
  long f0 = 0; // For fib(0)
  long f1 = 1; // For fib(1)
  long f2 = 1; // For fib(2)

  if (n == 0)
    return f0;
  else if (n == 1)
    return f1;
  else if (n == 2)
    return f2;

  for (int i = 3; i <= n; i++)
  {
    f0 = f1;
    f1 = f2;
    f2 = f0 + f1;
  }

  return f2;
}
```
```
command>cl ImprovedFibonacci.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ImprovedFibonacci 
Enter an index for the Fibonacci number: 19
Fibonacci number at index 19 is 4181

command>
```

>[!note] Algorithm Design Note
>The algorithm for computing Fibonacci numbers presented here uses an approach known as [[dynamic programming]]. [[Dynamic programming]] is the process of solving subproblems, then combining the solutions of the subproblems to obtain an overall solution. This naturally leads to a recursive solution. However, it would be inefficient to use recursion, because the subproblems overlap. The key idea behind [[dynamic programming]] is to solve each subproblem only once and store the results for subproblems for later use to avoid redundant computing of the subproblems.

^30a297

## Self-Check

### What is [[dynamic programming]]? Give an example of [[dynamic programming]].

![[COSC Chapter 18.5 Finding Fibonacci Numbers Using Dynamic Programming#^30a297]]

### Why is the recursive Fibonacci algorithm inefficient, but the non-recursive Fibonacci algorithm efficient?

The recursive Fibonacci algorithm is inefficient, because the subproblems in the recursive Fibonacci algorithm overlaps, which causes redundant work. The non- recursive Fibonacci algorithm is dynamic algorithm that avoids redundant work.


# References
