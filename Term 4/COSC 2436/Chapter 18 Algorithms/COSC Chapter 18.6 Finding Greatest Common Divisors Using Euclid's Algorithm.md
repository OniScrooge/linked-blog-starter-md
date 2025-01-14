# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.5 Finding Fibonacci Numbers Using Dynamic Programming]]

Next - [[COSC Chapter 18.7 Efficient Algorithms for Finding Prime Numbers]]
# Content

## Key Point

This section presents several algorithms in the search for an efficient algorithm for finding the greatest common divisor of two integers.

The greatest common divisor (GCD) of two integers is the largest number that can evenly divide both integers. **LiveExample 5.10**, GreatestCommonDivisor.cpp, presented a brute-force algorithm for finding GCD of two integers `m` and `n`.

>[!note] Algorithm Design Note
>[[Brute force]] refers to an algorithmic approach that solves a problem in the simplest or most direct or obvious way. As a result, such an algorithm can end up doing far more work to solve a given problem than a cleverer or more sophisticated algorithm might do. On the other hand, a brute-force algorithm is often easier to implement than a more sophisticated one and, because of this simplicity, sometimes it can be more efficient.

The brute-force algorithm checks whether `k` (for `k = 2, 3, 4,` and so on) is a common divisor for  `n1` and `n2`, until `k` is greater than `n1` or `n2`. The algorithm can be described as follows:

```cpp
    int gcd(int m, int n) 
    { 
      int gcd = 1; 
      for (int k = 2; k <= m && k <= n; k++) 
      { 
        if (m % k == 0 && n % k == 0) 
          gcd = k; 
      } 
      return gcd; 
    } 
```

Assuming _m_ ≥ _n_, the complexity of this algorithm is obviously _O_(_n_).

Is there a better algorithm for finding the GCD? Rather than searching a possible divisor from `1` up, it is more efficient to search from `n` down. Once a divisor is found, the divisor is the GCD. Therefore, you can improve the algorithm using the following loop:

```cpp
    for (int k = n; k >= 1; k--)  
    { 
      if (m % k == 0 && n % k == 0)  
      { 
        gcd = k;  
        break;  
      } 
    } 
```

This algorithm is better than the preceding one, but its worst-case time complexity is still _O_(_n_).

A divisor for a number `n` cannot be greater than `n / 2,` so you can further improve the algorithm using the following loop:

```cpp
    for (int k = n / 2; k >= 1; k--) { 
      if (m % k == 0 && n % k == 0) { 
        gcd = k; 
        break; 
      } 
    } 
```

However, this algorithm is incorrect, because `n` can be a divisor for `m`. This case must be considered. The correct algorithm is shown in **LiveExample 18.3**.

## **LiveExample 18.3 GCD.cpp**
```cpp
#include <iostream>
using namespace std;

// Return the gcd of two integers 
int gcd(int m, int n)
{
  int gcd = 1;

  if (m % n == 0) return n;

  for (int k = n / 2; k >= 1; k--) 
  {
    if (m % k == 0 && n % k == 0) 
    {
      gcd = k;
      break;
    }
  }

  return gcd;
}

int main()
{
  // Prompt the user to enter two integers
  cout << "Enter first integer: ";
  int n1;
  cin >> n1;

  cout << "Enter second integer: ";
  int n2;
  cin >> n2;

  cout << "The greatest common divisor for " << n1 <<
    " and " << n2 << " is " << gcd(n1, n2) << endl;

  return 0;
}
```
```
command>cl GCD.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>GCD 
Enter first integer: 45
Enter second integer: 75
The greatest common divisor for 45 and 75 is 15

command>
```

Assuming _m_ ≥ _n_, the `for` loop is executed at most _n_/2 times, which cuts the time by half from the previous algorithm. The time complexity of this algorithm is still _O_(_n_)**,** but practically, it is much faster than the algorithm in **LiveExample 5.10**.

>[!Note]
>The [[Big-O notation]] provides a good theoretical estimate of algorithm efficiency. However, two algorithms of the same time complexity are not necessarily equally efficient. As shown in the preceding example, both algorithms in **LiveExample 5.10** and **LiveExample 18.3** have the same complexity, but in practice the one in **LiveExample 18.3** is obviously better.

A more efficient algorithm for finding the GCD was discovered by Euclid around 300 B.C. This is one of the oldest known algorithms. It can be defined recursively as follows:

Let `gcd(m, n)` denote the GCD for integers `m` and `n`:
- If `m % n` is `0`, `gcd(m, n)` is `n`.
- Otherwise, `gcd(m, n)` is `gcd(n, m % n)`.

It is not difficult to prove the correctness of this algorithm. Suppose `m % n = r`. Thus, `m = qn + r`, where `q` is the quotient of `m / n`. Any number that divides `m` and `n` must also divide `r`. Therefore, `gcd(m, n)` is the same as `gcd(n, r)`, where `r = m % n`. The algorithm can be implemented as shown in **LiveExample 18.4**.

## **LiveExample 18.4 GCDEuclid.cpp**
```cpp
#include <iostream>
using namespace std;

// Return the gcd of two integers 
int gcd(int m, int n)
{
  if (m % n == 0)
    return n;
  else
    return gcd(n, m % n);
}

int main()
{
  // Prompt the user to enter two integers
  cout << "Enter first integer: ";
  int n1;
  cin >> n1;

  cout << "Enter second integer: ";
  int n2;
  cin >> n2;

  cout << "The greatest common divisor for " << n1 <<
    " and " << n2 << " is " << gcd(n1, n2) << endl;

  return 0;
}
```
```
command>cl GCDEuclid.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>GCDEuclid 
Enter first integer: 45
Enter second integer: 75
The greatest common divisor for 45 and 75 is 15

command>
```

In the **best case** when `m % n` is `0`, the algorithm takes just one step to find the GCD. It is difficult to analyze the average case. However, we can prove that the worst-case time complexity is _O_(log _n_).

Assuming _m_ ≥ _n_, we can show that `m % n < m / 2`, as follows:

If `n <= m / 2`, `m % n < m / 2`, since the remainder of _m_ divided by _n_ is always less than _n_.

If `n > m / 2`, `m % n = m – n < m / 2`. Therefore, `m % n < m / 2`.

Euclid’s algorithm recursively invokes the `gcd` [[function]]. It first calls `gcd(m, n)`, then calls `gcd(n, m % n)`, and `gcd(m % n, n % (m % n))`, and so on, as follows:

```cpp
  gcd(m, n) 
= gcd(n, m % n) 
= gcd(m % n, n % (m % n)) 
= ... 
```

Since `m % n < m / 2` and `n % (m % n) < n / 2`, the argument passed to the `gcd` [[function]] is reduced by half after every two iterations. After invoking `gcd` two times, the second parameter is less than _n_/2. After invoking `gcd` four times, the second parameter is less than _n_/4. After invoking `gcd` six times, the second parameter is less than n23 . Let _k_ be the number of times the `gcd` [[function]] is invoked. After invoking `gcd` _k_ times, the second parameter is less than n2(k/2), which is greater than or equal to 1. That is:
$$\frac{n}{2^{k/2}}\geq 1\to n \geq 2^{k/2} \to \log n \geq \frac{k}{2} \to k \leq 2 \log n$$

Therefore, _k_ ≤ 2 log _n_, so the time complexity of the `gcd` [[function]] is _O_(log _n_).

The worst case occurs when the two numbers result in the most divisions. It turns out that two successive Fibonacci numbers will result in the most divisions. Recall that the Fibonacci series begins with 0 and 1, and each subsequent number is the sum of the preceding two numbers in the series, such as:

$$0,1,1,2,3,5,8,13,21,34,55,89$$

The series can be recursively defined as:
```cpp
fib(0) = 0; 
fib(1) = 1; 
fib(index) = fib(index - 2) + fib(index - 1); index >= 2 
```

For two successive Fibonacci numbers `fib(index)` and `fib(index -1)`:
```cpp
gcd(fib(index), fib(index - 1)) 
= gcd(fib(index - 1), fib(index - 2)) 
= gcd(fib(index - 2), fib(index - 3)) 
= gcd(fib(index - 3), fib(index - 4)) 
= ... 
= gcd(fib(2), fib(1)) 
= 1 
```

For example:
```cpp
gcd(21, 13) 
= gcd(13, 8) 
= gcd(8, 5) 
= gcd(5, 3) 
= gcd(3, 2) 
= gcd(2, 1) 
= 1 
```

Therefore, the number of times the `gcd` [[function]] is invoked is the same as the index. We can prove that index ≤ 1.44 log _n_, where _n_ = fib(index − 1). This is a tighter bound than index ≤ 2 log _n_.

**Table 18.4** summarizes the complexity of three algorithms for finding the GCD.

## Table 18.4 **Comparisons of GCD Algorithms**

|**Algorithm**|**Complexity**|**Description**|
|---|---|---|
|**LiveExample 5.10**|_O_(_n_)|Brute-force, checking all possible divisors|
|**LiveExample 18.3**|_O_(_n_)|Checking half of all possible divisors|
|**LiveExample 18.4**|_O_(log _n_)|Euclid’s algorithm|

## Self-Check

### Prove that the following algorithm for finding the GCD of the two integers m and n is incorrect.

```cpp
int gcd = 1;
for (int k = min(sqrt(n), sqrt(m)); k >= 1; k--) 
{
  if (m % k == 0 && n % k == 0)
  {
    gcd = k;
    break;
  }
}
```

To prove this is wrong, all you need is to give a counter example to show the algorithm does not work. Try n = 64 and m = 48. The algorithm will produce the gcd 8, but the actual gcd is 16.


# References
