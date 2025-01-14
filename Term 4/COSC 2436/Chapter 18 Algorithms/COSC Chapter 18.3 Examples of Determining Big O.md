# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.2 Measuring Algorithm Efficiency using Big-O Notation]]

Next - [[COSC Chapter 18.4 Analyzing Algorithmic Time Complexity]]
# Content

## Key Point

This section gives several examples of determining Big _​O_​.

## Example 1

Consider the time complexity for the following loop:
```cpp
for (int i = 1; i <= n; i++) 
{ 
  k = k + 5; 
} 
```

It is a [[constant time]], _c_, for executing
```cpp
k = k + 5; 
```

Since the loop is executed _n_ times, the time complexity for the loop is

T(n)=(a constant c)*n=O(n).

The theoretical analysis predicts the performance of the algorithm. To see how this algorithm performs, we run the code in**​ LiveExample 18.1**​ to obtain the execution time for _n_ = 25000000, 50000000, 100000000, and 200000000.

## **LiveExample 18.1 PerformanceTest.cpp**
```CPP
#include <iostream>
#include <ctime> // for time function
using namespace std;

void getTime(int n) 
{
  int startTime = time(0);
  double k = 0;
  for (int i = 1; i <= n; i++) 
  {
    k = k + 5;
  }
  int endTime = time(0);
  cout << "Execution time for n = " << n 
    << " is " << (endTime - startTime) << " seconds" << endl;
}

int main() 
{
  getTime(250000000);
  getTime(500000000);
  getTime(1000000000);
  getTime(2000000000);

  return 0;
}
```
```
command>cl PerformanceTest.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>PerformanceTest 
Execution time for n = 250000000 is 1 seconds
Execution time for n = 500000000 is 1 seconds
Execution time for n = 1000000000 is 3 seconds
Execution time for n = 2000000000 is 5 seconds

command>
```

Our analysis predicts a linear time complexity for this loop. As shown in the sample output, when the input size increases two times, the runtime increases roughly two times. The execution conforms to the prediction.

## Example 2

What is the time complexity for the following loop?
```cpp
for (int i = 1; i <= n; i++) 
{ 
  for (int j = 1; j <= n; j++) 
  { 
    k = k + i + j; 
  } 
} 
```

It is a [[constant time]], _c_, for executing
```cpp
k = k + i + j; 
```

The outer loop executes _n_ times. For each iteration in the outer loop, the inner loop is executed _n_ times. Thus, the time complexity for the loop is:
$$T(n)=(C)*n*n=O(n^2)$$
An algorithm with the **_O(_n_2)_** time complexity is called a [[quadratic algorithm]]. The [[quadratic algorithm]] grows quickly as the problem size increases. If you double the input size, the time for the algorithm is quadrupled. Algorithms with a nested loop are often quadratic. 

## Example 3

Consider the following loop:
```cpp
for (int i = 1; i <= n; i++) 
{ 
  for (int j = 1; j <= i; j++) 
  { 
    k = k + i + j; 
  } 
} 
```

The outer loop executes _n_ times. For _i_ = 1, 2, ..., the inner loop is executed one time, two times, and _n_ times. Thus, the time complexity for the loop is:
$$T(n)=c+2c+3c+4c+\dots+nc$$
$$=\frac{cn(n+1)}{2}$$
$$=\left( \frac{c}{n} \right)n^2+\left( \frac{c}{2} \right)n$$
$$=O(n^2)$$
## Example 4

Consider the following loop:
```cpp
for (int i = 1; i <= n; i++) 
{ 
  for (int j = 1; j <= 20; j++) 
  { 
    k = k + i + j; 
  } 
} 
```

The inner loop executes 20 times, and the outer loop _n_ times. Therefore, the time complexity for the loop is:
$$T(n)=20*c*n=O(n)$$
## Example 5

Consider the following sequences:
```cpp
for (int j = 1; j <= 10; j++) 
{ 
  k = k + 4; 
 
 
for (int i = 1; i <= n; i++) 
{ 
  for (int j = 1; j <= 20; j++) 
  { 
    k = k + i + j; 
  } 
} 
```

The first loop executes 10 times, and the second loop $20 * n$ times. Thus, the time complexity for the loop is:
$$T(n)=10*c+20*c*n=O(n)$$
## Example 6

Consider the computation of $a^n$ for an integer _n_. A simple algorithm would multiply _a_ _n_ times, as follows:
```cpp
result = 1; 
for (int i = 1; i <= n; i++) 
  result *= a; 
```

The algorithm takes _O_(_n_) time. Without loss of generality, assume _n_ $= 2^k$. You can improve the algorithm using the following scheme:
```cpp
result = a; 
for (int i = 1; i <= k; i++) 
  result = result * result; 
```

The algorithm takes _O_(log _n_) time. For an arbitrary _n_, you can revise the algorithm and prove that the complexity is still _O_(log _n_). (See **Checkpoint Question 18.3.5**.)

>[!Note]
>An algorithm with the O(log n) time complexity is called a [[logarithmic algorithm]]. The base of the log is 2, but the base does not affect a logarithmic growth rate, so it can be omitted. 

## Self-Check

### Count the number of iterations in the following loops.

(a) 
```CPP
int count = 1;
while (count < 30) 
{
  count = count * 2;
}
```

(b)
```cpp
int count = 15;
while (count < 30) 
{
  count = count * 3;
}
```

(c)
```cpp
int count = 1;
while (count < n)
{ 
  count = count * 2;
}
```

(d)
```cpp
int count = 15;
while (count < n)
{
  count = count * 3;
}    
```    

#### Answer

(A) 5  
(B) 1  
(C) The ceiling of log2n times  
(D) The ceiling of log3(n/15) times  

### How many stars are displayed in the following code if n is 10? How many if n is 20? Use the Big O notation to estimate the time complexity.

(a)
```cpp
for (int i = 0; i < n; i++) 
{
  cout << '*';
}
```

(b)
```cpp
for (int i = 0; i < n; i++) 
{
  for (int j = 0; j < n; j++) 
  {
    cout << '*';
  }
}
```

(c)
```cpp
for (int k = 0; k < n; k++) 
{
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++)
    {
      cout << '*';
    }
  }
}
```

(d)
```cpp
for (int k = 0; k < 10; k++) 
{
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++) 
    {
      cout << '*';
    }
  }
}
```

#### Answer

if n is 10: (a) 10 (b) 10^2 (c) 10^3 (d) 10*10^2  
if n is 20: (a) 20 (b) 20^2 (c) 20^3 (d) 10*20^2  
Using [[Big-O notation]]: O(n), O(n^2), O(n^3), O(n^2)

### Use the [[Big-O notation]] to estimate the time complexity of the following functions:

(a)
```cpp
void mA(int n) 
{   
  for (int i = 0; i < n; i++) 
  {
    cout << rand();
  }
}
```

(b)
```cpp
void mB(int n) 
{   
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < i; j++)
      cout << rand();
  }
}
```

(c)
```cpp
void mC(int m, int size) 
{   
  for (int i = 0; i < size; i++) 
  {
    cout << m[i];
  }

  for (int i = size - 1; i >= 0; )
  {
    cout << m[i];
    i--;
  } 
}
```

(d)
```cpp
void mD(int m[], int size) 
{   
  for (int i = 0; i < size; i++) 
  {
    for (int j = 0; j < i; j++)
      cout << m[i] * m[j];
  }
}
```

#### Answer

(a): O(n)  
(b): O(n^2)  
(c): O(n)  
(d): O(n^2)

### Design an O(n) time algorithm for computing the sum of numbers from n1 to n2 for (n1 < n2). Can you design an O(1) for performing the same task?

An O(n) time algorithm for this is
```cpp
int sum = 0;
for (int i = n1; i <=  n2; i++)
  sum += i;
```

An O(1) time algorithm for this is
```cpp
int sum = n2 * (n2 + 1) / 2 - n1 * (n1 - 1) / 2;
```

### Example 7 in Section 18.3 assumes n = 2k. Revise the algorithm for an arbitrary n and prove that the complexity is still O(logn).

```cpp
result = a;
i = 2;

while (i <=  n) 
{
  result = result * result;
  i *= 2;
}

for (int j = i / 2 + 1; j <=  n; j++)
  result = result * a;
```

Assume that 2k-1 <= n < 2k. The while loop is executed k-1 times. The for loop is executed at most 2k-2k-1=2k-1 times. So, the total complexity is O(n). Consider another implementation:

```cpp
int f(int a, int n) 
{
  if (n == 1) 
  {
    return a; 
  } 
  else 
  {
    int temp = f(a, n / 2);
    if (n % 2 == 0) 
    {
      return temp * temp;
    }
    else 
    {
      return a * temp * temp;
    }
  }  
}
```

This implementation results in O(logn) complexity.

### What is the number of iterations of this loop?
```cpp
int count = 5;
while (count < n)
{
	count += 3;
};
```

#### Answer

The ceiling of $\frac{n-5}{3}$

# References
