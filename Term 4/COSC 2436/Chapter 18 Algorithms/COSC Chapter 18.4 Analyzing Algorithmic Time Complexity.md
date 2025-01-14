# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.3 Examples of Determining Big O]]

Next - [[COSC Chapter 18.5 Finding Fibonacci Numbers Using Dynamic Programming]]
# Content

## Key Point

This section analyzes the complexity of several well-known algorithms: binary search, selection sort, and Towers of Hanoi.

## 18.4.1 Analyzing Binary Search
![[Pasted image 20241022105534.png]]
![[Pasted image 20241022105555.png]]
![[Pasted image 20241022105605.png]]

The binary search algorithm presented in **LiveExample 7.9** BinarySearch.cpp, searches for a key in a sorted array. Each iteration in the algorithm contains a fixed number of operations, denoted by _c_. Let _T_(_n_) denote the time complexity for a binary search on a list of _n_ elements. Without loss of generality, assume _n_ is a power of 2 and _k_ = log _n_. Since a binary search eliminates half of the input after two comparisons:
$$T(n)=T\left( \frac{n}{2} \right)+c=T\left( \frac{n}{2^2} \right)+c+c=T\left( \frac{n}{2^k} \right)+kc$$
$$=T(1)+c * \log * n=1+(\log n)*c$$
$$=O(\log n)$$
## 18.4.2 Analyzing Selection Sort
![[Pasted image 20241022110321.png]]
![[Pasted image 20241022110502.png]]
![[Pasted image 20241022110516.png]]
![[Pasted image 20241022110528.png]]
![[Pasted image 20241022110704.png]]
![[Pasted image 20241022110719.png]]
![[Pasted image 20241022110733.png]]
![[Pasted image 20241022110742.png]]
![[Pasted image 20241022110751.png]]
![[Pasted image 20241022110759.png]]

The selection sort algorithm presented in **LiveExample 7.10**, SelectionSort.cpp, finds the smallest element in the list and swaps it with the first element. It then finds the smallest element remaining and swaps it with the first element in the remaining list, and so on, until the remaining list contains only one element left to be sorted. The number of comparisons is _n_ – 1 for the first iteration, _n_ – 2 for the second iteration, and so on. Let _T_(_n_) denote the complexity for selection sort and _c_ denote the total number of other operations such as assignments and additional comparisons in each iteration. Thus:
$$T(n)=(n-1)+c+(n-2)+c+\dots+2+c+1+c$$
$$=\frac{(n-1)(n-1+1)}{2}+c(n-1)=\frac{n^2}{2}-\frac{n}{2}+cn-c$$
$$=O(n^2)$$
Therefore, the complexity of the selection sort algorithm is $O(n^2)$

## 18.4.3 Analyzing the Towers of Hanoi Problem
![[Pasted image 20241022111458.png]]

The Towers of Hanoi problem presented in **LiveExample** **17.7**, TowersOfHanoi.cpp, recursively moves _n_ disks from tower A to tower B with the assistance of tower C as follows:
1. Moves the first _n_ − 1 disks from A to C with the assistance of tower B.
2. Moves disk _n_ from A to B.
3. Moves _n_ − 1 disks from C to B with the assistance of tower A.

The complexity of this algorithm is measured by the number of moves. Let _T_(_n_) denote the number of moves for the algorithm to move _n_ disks from tower A to tower B. Thus _T_(1) is 1:
$$T(n)=T(n-1)+1+T(n-1)$$
$$=2T(n-1)+1$$
$$=2(2T(n-2)+1)+1$$
$$=2(2(2T(n-3)+1)+1)+1$$
$$2^{n-1}T(1)+2^{n-2}+\dots+2+1$$
$$2^{n-1}+2^{n-2}+\dots+2+1=(2^n-1)=O(2^n)$$

An algorithm with O (2n) time complexity is called an [[exponential algorithm]]. As the input size increases, the time for the [[exponential algorithm]] grows exponentially. Exponential algorithms are not practical for large input size. Suppose the disk is moved at a rate of 1 per second. It would take 232/ (365 * 24 * 60 * 60) = 136 years to move 32 disks and 264/ (365 * 24 * 60 * 60) = 585 billion years to move 64 disks.

## 18.4.4 Common Recurrence Relations

_Recurrence relations_ are a useful tool for analyzing algorithm complexity. As shown in the preceding examples, the complexity for binary search, selection sort, and the Towers of Hanoi is T(n)=T(n2)+c,T(n)=T(n−1)+O(n), and T(n)=2T(n−1)+O(1), respectively. **Table 18.2** summarizes the common recurrence relations.

### Table 18.2 **Common Recurrence Functions**

|   |   |   |
|---|---|---|
|**Recurrence Relation**|**Result**|**Example**|
|T(n)=T(n/2)+O(1)|T(n)=O(log n)|Binary search, Euclid’s GCD (§**18.6**)|
|T(n)=T(n−1)+O(1)|T(n)=O(n)|Linear search|
|T(n)=2T(n/2)+O(1)|T(n)=O(n)|Checkpoint Question 18.8.3|
|T(n)=2T(n/2)+O(n)|T(n)=O(n log n)|Merge sort (**Chapter 19**)|
|T(n)=T(n−1)+O(n)|T(n)=O(n2)|Selection sort|
|T(n)=2T(n−1)+O(1)|T(n)=O(2n)|Towers of Hanoi|
|T(n)=T(n−1)+T(n−2)+O(1)|T(n)=O(2n)|Recursive Fibonacci algorithm|

## 18.4.5 Comparing Common Growth Functions

The preceding sections analyzed the complexity of several algorithms. **Table 18.3** lists some common growth functions and shows how [[growth rates]] change as the input size doubles from n=25 to n=50.

### Table 18.3 **​Change of [[Growth Rates]]​**

|**[[Function]]**|**Name**|**_n_ = 25**|**_n_ = 50**|**_f_(50) / _f_(25)**|
|---|---|---|---|---|
|_O_(1)|[[Constant time]]|1|1|1|
|_O_(log _n_)|[[Logarithmic time]]|4.64|5.64|1.21|
|_O_(_n_)|Linear time|25|50|2|
|_O_(_n_ log _n_)|Log-linear time|116|282|2.43|
|O(n2)|[[Quadratic time]]|625|2,500|4|
|O(n3)|Cubic time|15,625|125,000|8|
|O(2n)|Exponential time|3.36×107|1.27×1015|3.35×107|

These functions are ordered as follows, as illustrated in **​Figure 18.1**​.
$$O(1)<O(logn)<O(n)<O(nlogn)<O(n2)<O(n3)<O(2n)$$
![[Pasted image 20241022112844.png]]

## Self-Check

### Put the following growth functions in order: 5n3/4032, 44logn, 10nlogn, 500, 2n2, 2n/45, 3n

500,44logn,3n,10nlogn 2n2,5n3/4032,2n/45

### Estimate the time complexity for adding two n by m matrices, and for multiplying an n by m matrix by an m by k matrix.

Adding two matrices: O(nm). Multiplying two matrices: O(nmk)

### Describe an algorithm for finding the occurrence of the max element in an array. Analyze the complexity of the algorithm.

The algorithm can be designed as follows: Maintain two variables, max and count. max stores the current max number, and count stores its occurrences. Initially, assign the first number to max and 1 to count. Compare each subsequent number with max. If the number is greater than max, assign it to max and reset count to 1. If the number is equal to max, increment count by 1. Since each element in the array is examined only once, the complexity of the algorithm is O(n).

### Describe an algorithm for removing duplicates from an array. Analyze the complexity of the algorithm.

The algorithm can be designed as follows: For each element in the input array, store it to a new array if it is new. If the number is already in the array, ignore it. The time for checking whether an element is already in the new array is O(n), so the complexity of the algorithm is O(n^2).

### Analyze the following sorting algorithm:

```cpp
for (int i = 0; i < list.length - 1; i++)
{
  if (list[i] > list[i + 1]) 
  {
    swap list[i] with list[i + 1];
    i = -1;
  }
}
```

#### Answer

This is similar to bubble sort. Whenever a swap is made, it goes back to the beginning of the loop. In the worst case, there will be O(n^2) of swaps. For each swap, O(n) number of comparisons may be made in the worst case. So, the total is O(n^3) in the worst case.

### Analyze the complexity for computing a polynomial f(x) of degree n for a given x value using a brute-force approach and the Horner's approach, respectively. A brute-force approach is to compute each term in the polynomial and add them together. The Horner's approach was introduced in Section 6.7.  
f(x) = anxn + an-1xn-1 + an-2xn-2 + ... + a1x1 + a0

#### Answer

A brute-force for approach to evaluate a polynomial f(x) of degree n will take n+(n-1)+…+2+1=O(n^2) time. The Horner's [[function]] takes O(n) time.

# References
