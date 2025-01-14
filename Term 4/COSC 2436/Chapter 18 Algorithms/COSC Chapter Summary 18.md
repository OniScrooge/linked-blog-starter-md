# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.11.2 The Knuth-Morris-Pratt Algorithm]]

Next - 
# Content

## Key Terms
1. **[[average-case analysis]]**
2. **[[backtracking]] approach**
3. **[[best-case input]]**
4. [[Big-O notation]]
5. **[[brute force]]**
6. **[[constant time]]**
7. **[[convex hull]]**
8. **[[divide-and-conquer]] approach**
9. **[[dynamic programming]] approach**
10. **[[exponential algorithm]]**
11. **[[growth rates]]**
12. **[[logarithmic time]]**
13. **[[quadratic time]]**
14. **[[worst-case input]]**

## Chapter Summary
1. The Big _O_ notation is a theoretical approach for analyzing the performance of an algorithm. It estimates how fast an algorithm’s execution time increases as the input size increases. So, you can compare two algorithms by examining their _[[growth rates]]_.
2. An input that results in the shortest execution time is called the _best-case_ input, and an input that results in the longest execution time is called the _worst-case_ input.
3. Best case and worst case are not representative, but worst-case analysis is very useful. You can be sure that the algorithm will never be slower than the worst case.
4. An [[average-case analysis]] attempts to determine the average amount of time among all possible inputs of the same size.
5. [[Average-case analysis]] is ideal, but difficult to perform, because for many problems it is hard to determine the relative probabilities and distributions of various input instances.
6. If the time is not related to the input size, the algorithm is said to take _[[constant time]]_ with the notation O(1).
7. Linear search takes _O_(_n_) time. An algorithm with the _O_(_n_) time complexity is called a _linear algorithm_.
8. Binary search takes _O_(log _n_) time. An algorithm with the _O_(log _n_) time complexity is called a _[[logarithmic algorithm]]_.
9. The worst-time complexity for selection sort is _O_(_n_2).
10. An algorithm with the _O_(_n_2) time complexity is called a _[[quadratic algorithm]]_.
11. The time complexity for the Towers of Hanoi problem is _O_(2_n_)
12. An algorithm with the _O_(2_n_) time complexity is called an _[[exponential algorithm]]_.
13. A Fibonacci number at a given index can be found in _O_(_n_) time.
14. Euclid’s GCD algorithm takes _O_(log _n_) time.
15. All prime numbers less than or equal to _n_ can be found inO(nn√logn)  time.
16. The closest pair can be found in _O_(_n_ log _n_) time using the _[[divide-and-conquer]] approach_.
17. The [[divide-and-conquer]] approach divides the problem into subproblems, solves the subproblems, then combines the solutions of the subproblems to obtain the solution for the entire problem. Unlike the [[dynamic programming]] approach, the subproblems in the [[divide-and-conquer]] approach don’t overlap. A subproblem is like the original problem with a smaller size, so you can apply recursion to solve the problem.
18. The Eight Queens problem can be solved using [[backtracking]].
19. The [[backtracking]] approach searches for a candidate solution incrementally, abandoning that option as soon as it determines that the candidate cannot possibly be a valid solution, and then looks for a new candidate.
20. A _[[convex hull]]_ for a set of points can be found in _O_(_n_2) time using the gift-wrapping algorithm and in _O_(_n_ log _n_) time using the Graham’s algorithm.
21. The [[brute force]] and Boyer-Moore string matching algorithms take O(nm) time and the KMP string matching algorithm takes O(n + m) time.


# References
