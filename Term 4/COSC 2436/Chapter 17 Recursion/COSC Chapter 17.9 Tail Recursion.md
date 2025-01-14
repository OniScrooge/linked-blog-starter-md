# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.8 Recursion vs Iteration]]

Next - [[COSC Summary Chapter 17]]
# Content
## Key Point

A [[tail recursive]] [[function]] is efficient for reducing stack space.

A [[recursive function]] is said to be [[tail recursive]] if there are no pending operations to be performed on return from a recursive call, as illustrated in **Figure 17.9a**. However, [[function]] `B` in **Figure 17.9b** is not [[tail recursive]] because there are pending operations after a [[function]] call is returned.

>[!note] Figure 17.9
>![[Pasted image 20241105194311.png]]

For example, the recursive `isPalindrome` [[function]] (lines 5–13) in **LiveExample 17.4** is [[tail recursive]] because there are no pending operations after recursively invoking `isPalindrome` in line 12. However, the recursive `factorial` [[function]] (lines 21–27) in **LiveExample 17.1** is not [[tail recursive]], because there is a pending operation, namely multiplication, to be performed on return from each recursive call.

Tail recursion is desirable, because the [[function]] ends when the last recursive call ends. So there is no need to store the intermediate calls in the stack. Modern compilers optimize tail recursion to reduce stack space.

A nontail-[[recursive function]] can often be converted to a tail-[[recursive function]] by using auxiliary parameters. These parameters are used to contain the result. The idea is to incorporate the pending operations into the auxiliary parameters in such a way that the recursive call no longer has a pending operation. You may define a new auxiliary [[recursive function]] with the auxiliary parameters. This [[function]] may overload the original [[function]] with the same name but a different signature. For example, the `factorial` [[function]] in **LiveExample 17.1** can be written in a tail-recursive way in **CodeAnimation 17.2**. This animation shows why tail-recursive functions are efficient by highlighting the use of the call stacks.

## **LiveExample 17.9 ComputeFactorialTailRecursion.cpp**
```cpp
#include <iostream>
using namespace std;

// Return the factorial for a specified index
long long factorial(int);

// Auxiliary tail-recursive function for factorial
long long factorial(int n, long long result);

int main()
{
  // Prompt the user to enter an integer
  cout << "Please enter a non-negative integer: ";
  int n;
  cin >> n;

  // Display factorial
  cout << "Factorial of " << n << " is " << factorial(n);

  return 0;
}

// Return the factorial for a specified number 
long long factorial(int n) 
{
  return factorial(n, 1); // Call auxiliary function
}

// Auxiliary tail-recursive function for factorial
long long factorial(int n, long long result) 
{
  if (n == 0) 
    return result;
  else
    return factorial(n - 1, n * result); // Recursive call
} // You can view the Code Animation for this program from
// https://liangcpp.pearsoncmg.com/codeanimation/ComputeFactorialTailRecursion.html
```
```
command>cl ComputeFactorialTailRecursion.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ComputeFactorialTailRecursion 
Please enter a non-negative integer: 9
Factorial of 9 is 362880

command>
```

The first `factorial` [[function]] simply invokes the second auxiliary [[function]] (line 26). The second [[function]] contains an auxiliary parameter `result` that stores the result for factorial of `n`. This [[function]] is invoked recursively in line 35. There is no pending operation after a call is returned. The final result is returned in line 33, which is also the return value from invoking `factorial(n, 1)` in line 26.
## Self-Check
### Identify tail-recursive functions in this chapter.
The `isPalindrome` [[function]] in __LiveExample 17.4__, sort [[function]] in __LiveExample 7.5__, and `binarySearch` [[function]] in __LiveExample 17.6__ are tail-recursive.
### Rewrite the fib [[function]] in __LiveExample 17.2__ using tail recursion.
```cpp
/** Return the Fibonacci number for the specified index */
int fib(int index) 
{
  return fib(index, 1, 0);
}

/** Auxiliary tail-recursive function for fib */
int fib(int index, int next, int result)
{
  if (index == 0) 
    return result;
  else
    return fib(index - 1, next + result, next);
}
```
# References
