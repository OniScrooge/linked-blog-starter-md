# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.1 Introduction]]

Next - [[COSC Chapter 18.3 Examples of Determining Big O]]
# Content

## Key Point

The Big _O_ notation obtains a [[function]] for measuring algorithm time complexity based on the input size. You can ignore multiplicative constants and nondominating terms in the [[function]].

Suppose two algorithms perform the same task, such as search (linear search vs. binary search). Which one is better? To answer this question, you might implement these algorithms and run the programs to get execution time. But there are two problems with this approach:
- First, many tasks run concurrently on a computer. The execution time of a particular program depends on the system load. 
- Second, the execution time depends on specific input. Consider, for example, linear search and binary search. If an element to be searched happens to be the first in the list, linear search will find the element quicker than binary search.

It is very difficult to compare algorithms by measuring their execution time. To overcome these problems, a theoretical approach was developed to analyze algorithms independent of computers and specific input. This approach approximates the effect of a change on the size of the input. In this way, you can see how fast an algorithm’s execution time increases as the input size increases, so you can compare two algorithms by examining their [[growth rates]].

Consider linear search. The linear search algorithm compares the key with the elements in the array sequentially until the key is found or the array is exhausted. If the key is not in the array, it requires _n_ comparisons for an array of size _n_. If the key is in the array, it requires _n/2_ comparisons on average. The algorithm’s execution time is proportional to the size of the array. If you double the size of the array, you will expect the number of comparisons to double. The algorithm grows at a linear rate. The growth rate has an order of magnitude of _n_. Computer scientists use the Big O notation to represent the “order of magnitude.” Using this notation, the complexity of the linear search algorithm is _O_(_n_), pronounced as “_order of n_.” The time complexity (a.k.a. running time) of an algorithm is the amount of the time taken by the algorithm to run measured using the big O notation.

>[!Note]
>The time complexity (a.k.a. running time) of an algorithm is the amount of the time taken by the algorithm to run measured using the big O notation.

For the same input size, an algorithm’s execution time may vary, depending on the input. An input that results in the shortest execution time is called the [[best-case input]], and an input that results in the longest execution time is the [[worst-case input]]. Best- and worst-case analyses are to analyze the algorithms for their best- and [[worst-case input]]. Best- and worst-case analyses are not representative, but worst-case analysis is very useful. You can be assured that the algorithm will never be slower than the worst case. An [[average-case analysis]] attempts to determine the average amount of time among all possible inputs of the same size. [[Average-case analysis]] is ideal, but difficult to perform, because for many problems it is hard to determine the relative probabilities and distributions of various input instances. Worst-case analysis is easier to perform, so the analysis is generally conducted for the worst case.

The linear search algorithm requires _n_ comparisons in the worst case and n/2 comparisons in the average case if you are nearly always looking for something known to be in the list. Using the Big _O_ notation, both cases require _O_(_n_) time. The multiplicative constant (1/2) can be omitted. Algorithm analysis is focused on growth rate. The multiplicative constants have no impact on [[growth rates]]. The growth rate for n/2 or 100_n_ is the same as for _n_, as illustrated in **Table 18.1**. Therefore, $O(n)=O(n/2)=O(100n)$.

>[!info] Table 18.1
>![[Pasted image 20241022102323.png]]

Consider the algorithm for finding the maximum number in an array of _n_ elements. To find the maximum number if _n_ is 2, it takes one comparison; if _n_ is 3, two comparisons. In general, it takes n−1 comparisons to find the maximum number in a list of _n_ elements. Algorithm analysis is for large input size. If the input size is small, there is no significance in estimating an algorithm’s efficiency. As _n_ grows larger, the _n_ part in the expression n−1 dominates the complexity. The Big _O_ notation allows you to ignore the nondominating part (e.g., −1 in the expression n−1) and highlight the important part (e.g., _n_ in the expression n−1). Therefore, the complexity of this algorithm is _O_(_n_).

The Big _O_ notation estimates the execution time of an algorithm in relation to the input size. If the time is not related to the input size, the algorithm is said to take [[constant time]] with the notation _O_(_1_). For example, a [[function]] that retrieves an element at a given index in an array takes [[constant time]], because the time does not grow as the size of the array increases.

The following mathematical summations are often useful in algorithm analysis:
![[Pasted image 20241022102727.png]]

>[!Note]
>Time complexity is a measure of execution time using the Big O notation. Similarly, you can also measure space complexity using the Big O notation. Space complexity measures the amount of memory space used by an algorithm. The space complexity for most algorithms presented in this book is _O(n),_ that is, they exhibit linear growth rate to the input size. For example, the space complexity for linear search is _O(n)_.

>[!Note]
>We presented the [[Big-O notation]] in laymen’s terms. **Appendix I** gives a precise mathematical definition for the [[Big-O notation]] as well as the Big-Omega and Big-Theta notations.

## Self-Check

### Why is a constant factor ignored in the Big O notation? Why is a nondominating term ignored in the Big O notation?

The constant factor is ignored in big O notation, because it has no impact on the growth rate of the time complexity [[function]]. A nondominating term is ignored in Big O notation, because as the input size grows, the dominating term grows much faster than the nondominating term.

### What is the order of each of the following functions?

(a) (n2 + 1)2 / n
(b) (n2 + log2n)2 / n
(c) n3 + 100n2 + n
(d) 2n + 100n2 + 45n 
(e) n2n + n22n                    

#### Answer

(a) (n2 + 1)2/n = O(n3)
(b) (n2 + log2n)2 / n = O(n3)
(c) n3 + 100n2 + n = O(n3)
(d) 2n + 100n2 + 45n = O(2n)
(e) n2n + n22n = O(n22n)

# References
