# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.6 Finding Greatest Common Divisors Using Euclid's Algorithm]]

Next - [[COSC Chapter 18.8 Finding the Closest Pair of Points using Divide-and-Conquer]]
# Content

## Key Point

This section presents several algorithms in the search for an efficient algorithm for finding prime numbers.

>[!abstract] Interesting...
A $150,000 award awaits the first individual or group who discovers a prime number with at least 100,000,000 decimal digits (**​https://www.eff.org/awards/coop**​).

Can you design a fast algorithm for finding prime numbers?

An integer greater than `1` is **prime** if its only positive divisor is `1` or itself. For example, `2`, `3`, `5`, and `7` are prime numbers, but `4`, `6`, `8`, and `9` are not.

How do you determine whether a number n is prime? **LiveExample 5.16** presented a brute-force algorithm for finding prime numbers. The brute-force algorithm can find prime numbers. The algorithm checks whether `2`, `3`, `4`, `5`, ..., or `n - 1` divides `n`. If not, `n` is prime. This algorithm takes _O_(_n_) time to check whether `n` is prime. Note that you need to check only whether `2`, `3`, `4`, `5`, ..., and `n/2` divides `n`. If not, `n` is prime. This algorithm is slightly improved, but it is still of _O_(_n_).

In fact, we can prove that if `n` is not a prime, `n` must have a factor that is greater than `1` and less than or equal to n−−√. Here is the proof. Since `n` is not a prime, there exist two numbers `p` and `q` such that `n` = `pq` with 1 < _p_ ≤ _q_. Note that n=n−−√n−−√. `p` must be less than or equal to n−−√. Hence, you need to check only whether `2`, `3`, `4`, `5`, ..., or n−−√ divides `n`. If not, `n` is prime. This significantly reduces the time complexity of the algorithm to O(n−−√).

Now consider the algorithm for finding all the prime numbers up to `n`. A straightforward implementation is to check whether `i` is prime for _i_ = `2`, `3`, `4`, ..., `n`. The program is given in **​​LiveExample 18.5**​​.

## **LiveExample 18.5 PrimeNumbers.cpp**
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  cout << "Find all prime numbers <= n, enter n: ";
  int n;
  cin >> n;

  const int NUMBER_PER_LINE = 10; // Display 10 per line
  int count = 0; // Count the number of prime numbers
  int number = 2; // A number to be tested for primeness

  cout << "The prime numbers are:" << endl;

  // Repeatedly find prime numbers
  while (number <= n)
  {
    // Assume the number is prime
    bool isPrime = true; // Is the current number prime?

    // Test if number is prime
    for (int divisor = 2; divisor <= sqrt(number * 1.0); divisor++)
    {
      if (number % divisor == 0)
      { // If true, number is not prime
        isPrime = false; // Set isPrime to false
        break; // Exit the for loop
      }
    }

    // Print the prime number and increase the count
    if (isPrime)
    {
      count++; // Increase the count

      if (count % NUMBER_PER_LINE == 0)
      {
        // Print the number and advance to the new line
        cout << number << endl;
      }
      else
        cout << number << " ";
    }

    // Check whether the next number is prime
    number++;
  }

  cout << "\n" << count << " number of primes <= " << n << endl;

  return 0;
}
```
```
command>cl PrimeNumbers.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>PrimeNumbers 
Find all prime numbers <= n, enter n: 1000
The prime numbers are:
2 3 5 7 11 13 17 19 23 29
31 37 41 43 47 53 59 61 67 71
73 79 83 89 97 101 103 107 109 113
127 131 137 139 149 151 157 163 167 173
179 181 191 193 197 199 211 223 227 229
233 239 241 251 257 263 269 271 277 281
283 293 307 311 313 317 331 337 347 349
353 359 367 373 379 383 389 397 401 409
419 421 431 433 439 443 449 457 461 463
467 479 487 491 499 503 509 521 523 541
547 557 563 569 571 577 587 593 599 601
607 613 617 619 631 641 643 647 653 659
661 673 677 683 691 701 709 719 727 733
739 743 751 757 761 769 773 787 797 809
811 821 823 827 829 839 853 857 859 863
877 881 883 887 907 911 919 929 937 941
947 953 967 971 977 983 991 997 
168 number of primes <= 1000

command>
```

The program is not efficient if you have to compute `sqrt(number)` for every iteration of the for loop (line 24). A good compiler should evaluate `sqrt(number)` only once ​for​ the entire `for` loop. To make sure this happens, you may explicitly replace line 24 by the following two lines:

```cpp
int squareRoot = sqrt(number); 
for (int divisor = 2; divisor <= squareRoot; divisor++) 
```

In fact, there is no need to actually compute `sqrt(number)` for every `number`. You need only look for the perfect squares such as `4`, `9`, `16`, `25`, `36`, `49`, and so on. Note that for all the numbers between `36` and `48`, their `static_cast``<``int``>``(sqrt(number))` is `6`. With this insight, you can replace the code in lines 18–31 with the following code:

```cpp
... 
int squareRoot = 1; 
// Repeatedly find prime numbers 
while (number <= n) 
{ 
  // Assume the number is prime 
  boolean isPrime = true; // Is the current number prime? 
  if (squareRoot * squareRoot < number) squareRoot++; 
  // Test whether number is prime 
  for (int divisor = 2; divisor <= squareRoot; divisor++) 
  { 
    if (number % divisor == 0) // If true, number is not prime 
    { 
      isPrime = false; // Set isPrime to false 
      break; // Exit the for loop 
    } 
  } 
... 
```

Now we turn our attention to analyzing the complexity of this program. Since it takes i√ steps in the `for` loop (lines 24–31) to check whether number _i_ is prime, the algorithm takes 2–√+3–√+4–√+...+n−−√ steps to find all the prime numbers less than or equal to _n_. Observe that:
$$\sqrt{ 2 }+\sqrt{ 3 }+\sqrt{ 4 }+\dots+\sqrt{ n }\leq n\sqrt{ n }$$

Therefore, the time complexity for this algorithm is O(nn−−√).

To determine whether _i_ is prime, the algorithm checks whether `2`, `3`, `4`, `5`, ..., and i√ divides _i_. This algorithm can be further improved. In fact, you need only to check whether the prime numbers from `2` to i√ are possible divisors for _i_.

We can prove that if _i_ is not prime, there must exist a prime number _p_ such that _i_ = _pq_ and _p_ ≤ _q_. Here is the proof. Assume that _i_ is not prime; let _p_ be the smallest factor of _i_. _p_ must be prime; otherwise, _p_ has a factor _k_ with 2 ≤ _k_ < _p_. _k_ is also a factor of _i_, which contradicts that _p_ be the smallest factor of _i_. Therefore, if _i_ is not prime, you can find a prime number from `2` to i√ that divides _i_. This leads to a more efficient algorithm for finding all prime numbers up to _n_, as shown in **LiveExample 18.6.**

## **LiveExample 18.6 EfficientPrimeNumbers.cpp**
```cpp
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
  cout << "Find all prime numbers <= n, enter n: ";
  int n;
  cin >> n;

  const int NUMBER_PER_LINE = 10; // Display 10 per line
  int count = 0; // Count the number of prime numbers
  int number = 2; // A number to be tested for primeness
  // A vector to hold prime numbers
  vector<int> primeVector;
  int squareRoot = 1; // Check whether number <= squareRoot

  cout << "The prime numbers are:" << endl;

  // Repeatedly find prime numbers
  while (number <= n)
  {
    // Assume the number is prime
    bool isPrime = true; // Is the current number prime?

    if (squareRoot * squareRoot < number) squareRoot++;

    // Test if number is prime
    for (int k = 0; k < primeVector.size()
                    && primeVector[k] <= squareRoot; k++) 
    {
      if (number % primeVector[k] == 0) // If true, not prime
      {
        isPrime = false; // Set isPrime to false
        break; // Exit the for loop
      }
    }

    // Print the prime number and increase the count
    if (isPrime) 
    {
      count++; // Increase the count
      primeVector.push_back(number); // Add a new prime to the list
      if (count % NUMBER_PER_LINE == 0) 
      {
        // Print the number and advance to the new line
        cout << number << endl;
      }
      else
        cout << number << " ";
    }

    // Check if the next number is prime
    number++;
  }

  cout << "\n" << count << " number of primes <= " << n << endl;
  return 0;
}
```
```
command>cl EfficientPrimeNumbers.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>EfficientPrimeNumbers 
Find all prime numbers <= n, enter n: 1000
The prime numbers are:
2 3 5 7 11 13 17 19 23 29
31 37 41 43 47 53 59 61 67 71
73 79 83 89 97 101 103 107 109 113
127 131 137 139 149 151 157 163 167 173
179 181 191 193 197 199 211 223 227 229
233 239 241 251 257 263 269 271 277 281
283 293 307 311 313 317 331 337 347 349
353 359 367 373 379 383 389 397 401 409
419 421 431 433 439 443 449 457 461 463
467 479 487 491 499 503 509 521 523 541
547 557 563 569 571 577 587 593 599 601
607 613 617 619 631 641 643 647 653 659
661 673 677 683 691 701 709 719 727 733
739 743 751 757 761 769 773 787 797 809
811 821 823 827 829 839 853 857 859 863
877 881 883 887 907 911 919 929 937 941
947 953 967 971 977 983 991 997 
168 number of primes <= 1000

command>
```

Let _π_(_i_) denote the number of prime numbers less than or equal to _i_. The primes under `20` are `2`, `3`, `5`, `7`, `11`, `13`, `17`, and `19.` So, _π_(2) is `1`, _π_(3) is `2`, _π_(6) is `3`, and _π_(20) is `8`. It has been proved that _π_(_i_) is approximately $\frac{i}{\log i}$ (see primes.utm.edu/howmany.shtml).

For each number `i`, the algorithm checks whether a prime number less than or equal to i√ divides _i_. The number of prime numbers less than or equal to i√ is i√log i√=2i√log i. Thus, the complexity for finding all prime numbers up to _n_ is:
$$\frac{2\sqrt{ 2 }}{\log2}+\frac{2\sqrt{ 3 }}{\log_{3}}+\frac{2\sqrt{ 4 }}{\log4}+\frac{2\sqrt{ 5 }}{\log 5}+\frac{2\sqrt{ 6 }}{\log 6}+\frac{2\sqrt{ 7 }}{\log 7}+\frac{2\sqrt{ 8 }}{\log 8}+\dots+\frac{2\sqrt{ n }}{\log n}<\frac{2n\sqrt{ n }}{\log n}$$

Therefore, the complexity of this algorithm is $O\left( \frac{n\sqrt{ n }}{\log n} \right)$.

Is there an algorithm that is better than $O\left( \frac{n\sqrt{ n }}{\log n} \right)$? Let us examine the well-known Eratosthenes algorithm for finding prime numbers. Eratosthenes (276–194 B.C.) was a Greek mathematician who devised a clever algorithm, known as the _Sieve of Eratosthenes_, for finding all prime numbers ≤_n_. His algorithm is to use an array named `primes` of _n_ Boolean values. Initially, all elements in `primes` are set `true`. Since the multiples of `2` are not prime, set `primes[2 * i]` to `false` for all 2 ≤ _i_ ≤ _n_/2, as shown in **Figure 18.3**. Since we don’t care about `primes[0]` and `primes[1]`, these values are marked × in the figure.

>[!info] Figure 18.3
>![[Pasted image 20241022123721.png]]

Since the multiples of `3` are not prime, set `primes[3 * i]` to `false` for all 3 ≤ _i_ ≤ _n_/3. Since the multiples of `5` are not prime, set `primes[5 * i]` to `false` for all 5 ≤ _i_ ≥ _n_/5. Note that you don’t need to consider the multiples of `4`, because they are also multiples of 2, which have already been considered. Similarly, multiples of `6`, `8`, and `9` need not be considered. You need only to consider the multiples of a prime number `k = 2`, `3`, `5`, `7`, `11`, ..., and set the corresponding element in `primes` to `false`. Afterward, if `primes[i]` is still true, then `i` is a prime number. As shown in **Figure 18.3,** `2`, `3`, `5`, `7`, `11`, `13`, `17`, `19`, `23` are prime numbers. **​LiveExample 18.7**​ gives the program for finding the prime numbers using the _Sieve of Eratosthenes_ algorithm.

## **LiveExample 18.7 SieveOfEratosthenes.cpp**
```cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "Find all prime numbers <= n, enter n: ";
  int n;
  cin >> n;

  bool *primes = new bool[n + 1]; // Prime number sieve

  // Initialize primes[i] to true
  for (int i = 0; i < n + 1; i++)
  {
    primes[i] = true;
  }

  for (int k = 2; k <= n / k; k++)
  {
    if (primes[k])
    {
      for (int i = k; i <= n / k; i++)
      {
        primes[k * i] = false; // k * i is not prime
      }
    }
  }

  const int NUMBER_PER_LINE = 10; // Display 10 per line
  int count = 0; // Count the number of prime numbers found so far
  // Print prime numbers
  for (int i = 2; i < n + 1; i++)
  {
    if (primes[i])
    {
      count++;
      if (count % 10 == 0)
        cout << i << endl;
      else
        cout << i << " ";
    }
  }

  cout << "\n" << count << " number of primes <= " << n << endl;

  delete [] primes;

  return 0;
}
```
```
command>cl SieveOfEratosthenes.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>SieveOfEratosthenes 
Find all prime numbers <= n, enter n: 1000
2 3 5 7 11 13 17 19 23 29
31 37 41 43 47 53 59 61 67 71
73 79 83 89 97 101 103 107 109 113
127 131 137 139 149 151 157 163 167 173
179 181 191 193 197 199 211 223 227 229
233 239 241 251 257 263 269 271 277 281
283 293 307 311 313 317 331 337 347 349
353 359 367 373 379 383 389 397 401 409
419 421 431 433 439 443 449 457 461 463
467 479 487 491 499 503 509 521 523 541
547 557 563 569 571 577 587 593 599 601
607 613 617 619 631 641 643 647 653 659
661 673 677 683 691 701 709 719 727 733
739 743 751 757 761 769 773 787 797 809
811 821 823 827 829 839 853 857 859 863
877 881 883 887 907 911 919 929 937 941
947 953 967 971 977 983 991 997 
168 number of primes <= 1000

command>
```

Note that `k <= n / k` (line 18). Otherwise, `k * i` would be greater than `n` (line 20). What is the time complexity of this algorithm?

For each prime number `k` (line 20), the algorithm sets `primes[k * i]` to `false` (line 24). This is performed `n / k – k + 1` times in the `for` loop (line 22). Thus, the complexity for finding all prime numbers up to `n` is:
$$\frac{n}{2}-2+1+\frac{n}{3}-3+1++\frac{n}{5}-5+1+\frac{n}{7}-7+1+\frac{n}{11}-11+1\dots$$
$$=O\left( \frac{n}{2}+\frac{n}{3}+\frac{n}{5}+\frac{n}{7}+\frac{n}{11}+\dots \right)<O(n\pi(n))$$
$$=O\left( n\frac{\sqrt{ n }}{\log n} \right)$$

This upper bound $O\left( \frac{n\sqrt{ n }}{\log n} \right)$ is very loose. The actual time complexity is much better than $O\left( \frac{n\sqrt{ n }}{\log n} \right)$. The Sieve of Eratosthenes algorithm is good for a small `n` such that the array `primes` can fit in the memory.

**​​Table 18.5**​ summarizes the complexity of these three algorithms for finding all prime numbers up to _n_.

## Table 18.5  **Comparisons of Prime-Number Algorithms**

|**Algorithm**|**Complexity**|**Description**|
|---|---|---|
|**LiveExample 5.16**|O(n2)|Brute-force, checking all possible divisors|
|**LiveExample18.5**|O(nn−−√)|Checking divisors up to n−−√|
|**LiveExample 18.6**|O(nn−−√log  n)|Checking prime divisors up to n−−√|
|**LiveExample 18.7**|O(nn−−√log  n)|Sieve of Eratosthenes|

## Self-Check

### Prove that if n is not prime, there must exist a prime number p such that p <= sqrt(n) and p is a factor of n.

If n is not a prime, then there exists two number n1 and n2 such that n1 * n2 = n. Assume n1 <= n2, n1 <= srqt(n). If n1 is not a prime, you can continue the same process to find the factors of n1, until a factor is a prime.

### Describe how the sieve of Eratosthenes is used to find the prime numbers.

See the text.


# References
