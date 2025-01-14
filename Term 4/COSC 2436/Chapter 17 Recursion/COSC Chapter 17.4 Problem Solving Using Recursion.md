# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.3 Fibonacci Numbers]]

Next - [[COSC Chapter 17.5 Recursive Helper Functions]]
# Content
## Key Point

If you think recursively, you can solve many problems using recursion.

The preceding sections presented two classic recursion examples. All recursive functions have the following characteristics:
- The [[function]] is implemented using an `if-else` or a `switch` statement that leads to different cases.
- One or more base cases (the simplest case) are used to stop recursion.
- Every recursive call reduces the original problem, bringing it increasingly closer to a [[base case]] until it becomes that case.

In general, to solve a problem using recursion, you break it into subproblems. If a subproblem resembles the original problem, you can apply the same approach to solve the subproblem recursively. This subproblem is almost the same as the original problem in nature with a smaller size.

Recursion is everywhere. It is fun to _think recursively_. Consider drinking coffee. You may describe the procedure recursively as follows:
```cpp
void drinkCoffee(Cup& cup) 
{ 
  if (!cup.isEmpty()) 
  { 
    cup.takeOneSip(); // Take one sip 
    drinkCoffee(cup); 
  } 
} 
```

Assume `cup` is an object for a cup of coffee with the instance functions `isEmpty()` and `takeOneSip()`. You can break the problem into two subproblems: one is to drink one sip of coffee and the other is to drink the rest of the coffee in the cup. The second problem is the same as the original problem but smaller in size. The [[base case]] for the problem is when `cup` is empty.

Let us consider a simple problem of printing a message for `n` times. You can break the problem into two subproblems: one is to print the message one time and the other is to print the message `n - 1` times. The second problem is the same as the original problem with a smaller size. The [[base case]] for the problem is `n == 0`. You can solve this problem using recursion as follows:

```cpp
void nPrintln(const string& message, int times) 
{ 
  if (times >= 1) 
  { 
    cout << message << endl; 
    nPrintln(message, times - 1); 
  } // The base case is times == 0 
} 
```
Note that the `fib` [[function]] in **LiveExample 17.2** returns a value to its caller, but the `nPrintln` [[function]] is `void` and does not return a value to its caller.

Many of the problems presented in the early chapters can be solved using recursion if you _think recursively_. Consider the palindrome problem in **Listing 5.14**, TestPalindrome.cpp. Recall that a string is a palindrome if it reads the same from the left and from the right. For example, mom and dad are palindromes, but uncle and aunt are not. The problem to check whether a string is a palindrome can be divided into two subproblems:
- Check whether the first character and the last character of the string are equal.
- Ignore these two end characters and check whether the rest of the substring is a palindrome.

The second subproblem is the same as the original problem with a smaller size. There are two base cases: (1) the two end characters are not same; (2) the string size is `0` or `1`. In case 1, the string is not a palindrome; and in case 2, the string is a palindrome. The [[recursive function]] for this problem can be implemented in **LiveExample 17.3**.

## **LiveExample 17.3 RecursivePalindrome.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s)
{
  if (s.size() <= 1) // Base case
    return true;
  else if (s[0] != s[s.size() - 1]) // Base case
    return false;
  else
    return isPalindrome(s.substr(1, s.size() - 2));
}

int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  if (isPalindrome(s))
    cout << s << " is a palindrome" << endl;
  else
    cout << s << " is not a palindrome" << endl;

  return 0;
}
```
```
command>cl RecursivePalindrome.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>RecursivePalindrome 
Enter a string: abccba
abccba is a palindrome

command>
```

The `isPalindrome` [[function]] checks whether the size of the string is less than or equal to `1` (line 7). If so, the string is a palindrome. The [[function]] checks whether the first and the last elements of the string are the same (line 9). If not, the string is not a palindrome. Otherwise, obtain a substring of `s` using `s.substr(1, s.size() - 2)` and recursively invoke `isPalindrome` with the new string (line 12).
## Self-Check
### Show the output of the following two programs:
#### (a)
```cpp
#include <iostream>
using namespace std;

void f(int n) 
{
  if (n > 0) 
  {
    cout << n << " ";
    f(n - 1);
  }
}  
    
int main() 
{
  f(5);

  return 0;
}
```
#### (b)
``` cpp
#include <iostream>
using namespace std;

void f(int n) 
{
  if (n > 0) 
  {
    f(n - 1);
    cout << n << " ";
  }
}  
    
int main() 
{
  f(5);

  return 0;
}
```
#### Answer
(a) The output is 5 4 3 2 1  
(b) The output is 1 2 3 4 5
### What is wrong in the following [[function]]?
```cpp
#include <iostream>
using namespace std;

void f(double n) 
{
  if (n != 0) 
  {
    cout << n;
    f(n / 10);
  }
}
 
int main() 
{
  f(1234567);

  return 0;
}
```
#### Answer
n is double. There is no guarantee that n != 0 will be eventually false.
# References
