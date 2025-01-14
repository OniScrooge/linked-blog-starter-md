# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.2 Computing Factorials]]

Next - [[COSC Chapter 17.4 Problem Solving Using Recursion]]
# Content
## Key Point

In some cases, recursion enables you to create an intuitive, straightforward, simple solution to a problem.

The `factorial` [[function]] in the preceding section easily could be rewritten without using recursion. In some cases, however, using recursion enables you to give a natural, straightforward, simple solution to a program that would otherwise be difficult to solve. Consider the well-known Fibonacci series problem, as follows:

```cpp
The series: 0  1  1  2  3  5  8  13  21  34  55  89 . . . 
   Indices: 0  1  2  3  4  5  6  7   8   9   10  11 
```

The Fibonacci series begins with `0` and `1`, and each subsequent number is the sum of the preceding two numbers in the series. The series can be defined recursively as follows:

```cpp
fib(0) = 0; 
fib(1) = 1; 
fib(index) = fib(index - 2) + fib(index - 1); index >= 2 
```

The Fibonacci series was named for Leonardo Fibonacci, a medieval mathematician, who originated it to model the growth of the rabbit population. It can be applied in numeric optimization and in various other areas.

How do you find `fib(index)` for a given `index`? It is easy to find `fib(2)` because you know `fib(0)` and `fib(1)`. Assuming that you know `fib(index - 2)` and `fib(index - 1)`, `fib(index)` can be obtained immediately. Thus, the problem of computing `fib(index)` is reduced to computing `fib(index - 2)` and `fib(index - 1)`. When computing `fib(index - 2)` and `fib(index - 1)`, you apply the idea recursively until `index` is reduced to `0` or `1`.

The [[base case]] is `index = 0` or `index = 1`. If you call the [[function]] with `index = 0` or `index = 1`, it immediately returns the result. If you call the [[function]] with `index >= 2`, it divides the problem into two subproblems for computing `fib(index - 1)` and `fib(index - 2)` using recursive calls. The recursive algorithm for computing `fib(index)` can be simply described as follows:

```cpp
if (index == 0) 
  return 0; 
else if (index == 1) 
  return 1; 
else 
  return fib(index - 1) + fib(index - 2); 
```

**LiveExample 17.2** is a complete program that prompts the user to enter an index and computes the Fibonacci number for the index.
## **LiveExample 17.2 ComputeFibonacci.cpp**
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
int fib(int index)
{
  if (index == 0) // Base case
    return 0;
  else if (index == 1) // Base case
    return 1;
  else // Reduction and recursive calls
    return fib(index - 1) + fib(index - 2);
}
```
```
command>cl ComputeFibonacci.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ComputeFibonacci 
Enter an index for the Fibonacci number: 9
Fibonacci number at index 9 is 34

command>
```

The program does not show the considerable amount of work done behind the scenes by the computer. **Figure 17.3**, however, shows successive recursive calls for evaluating `fib(4)`. The original [[function]], `fib(4)`, makes two recursive calls, `fib(3)` and `fib(2)`, and then returns `fib(3) + fib(2)`. But in what order are these functions called? In C++, operands for the binary `+` operator may be evaluated in any order. Assume it is evaluated from the left to right. The labels in **Figure 17.3** show the order in which functions are called.

>[!note] Figure 17.3
>![[ch17fig04a.png]]
>As shown in **Figure 17.3**, there are many duplicated recursive calls. For instance, `fib(2)` is called twice, `fib(1)`  three times, and `fib(0)` twice. In general, computing `fib(index)` requires twice as many recursive calls as are needed for computing `fib(index - 1)`. As you try larger index values, the number of calls substantially increases, as shown in **Table 17.1**.

__Table 17.1 Number of Recursive Calls in `fib(index)`__

|   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|
|`index`|`2`|`3`|`4`|`10`|`20`|`30`|`40`|`50`|
|# of calls|3|5|9|177|21891|2,692,537|331,160,281|2,075,316,483|

>[!note] Pedagogical Note
>The recursive implementation of the `fib` [[function]] is very simple and straightforward, but not efficient, since it requires more time and space to run recursive functions. See **Programming Exercise 17.2** for an efficient solution using loops. The recursive `fib` [[function]] is a good example to demonstrate how to write recursive functions, though it is not practical.

## Self-Check
### How many times is the fib [[function]] in __LiveExample 17.2__ invoked for fib(6)?
- 25 times
- number of time fib is invoked in `fib(0)` = 1
- number of time fib is invoked in `fib(1)` = 1
- number of time fib is invoked in `fib(2)` = 1 + number of time fib is invoked in fib(1)+number of time fib is invoked in fib(2) =1+1+1=3
- number of time fib is invoked in `fib(3)` = 1 + number of time fib is invoked in fib(1)+number of time fib is invoked in fib(2) = 1+1+3=5
- number of time fib is invoked in `fib(4)` = 1 + number of time fib is invoked in fib(2)+number of time fib is invoked in fib(3) = 1+3+5=9
- number of time fib is invoked in `fib(5)` = 1 + number of time fib is invoked in fib(3)+number of time fib is invoked in fib(4) = 1+5+9=15
- number of time fib is invoked in `fib(6)` = 1 + number of time fib is invoked in fib(4)+number of time fib is invoked in fib(5) = 1+9+15=25
# References
