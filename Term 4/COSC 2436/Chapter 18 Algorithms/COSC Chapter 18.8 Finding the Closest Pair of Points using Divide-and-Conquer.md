# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.7 Efficient Algorithms for Finding Prime Numbers]]

Next - [[COSC Chapter 18.9 Solving the Eight Queens Problem using Backtracking]]
# Content

## Key Point

This section presents efficient algorithms for finding the closest pair of points using [[divide-and-conquer]].

>[!note] Pedagogical Note
>Starting from this section, we present interesting and challenging problems. It is time that you begin to study advanced algorithms to become a proficient programmer. We recommend that you study the algorithms and implement them in the exercises.

Given a set of points, the closest-pair problem is to find the two points that are nearest to each other. As shown in **​Figure 18.4**​, a line is drawn to connect the two nearest points in the closest-pair animation.

## Figure 18.4 Closest Pair Animation
![[Pasted image 20241022124756.png]]

**Section 8.6**, Case Study: Finding a Closest Pair, presented a brute-force algorithm for finding the closest pair of points. The algorithm computes the distances between all pairs of points and finds the one with the minimum distance. Clearly, the algorithm takes $O(n2)$ time. Can we design a more efficient algorithm? We can use an approach called [[divide-and-conquer]] to solve this problem efficiently in $O(nlogn)$ time.

>[!note] Algorithm Design Note
>The [[divide-and-conquer]] approach divides the problem into subproblems, solves the subproblems, then combines the solutions of the subproblems to obtain the solution for the entire problem. Unlike the [[dynamic programming]] approach, the subproblems in the [[divide-and-conquer]] approach don’t overlap. A subproblem is like the original problem with a smaller size, so you can apply recursion to solve the problem. In fact, all the solutions for recursive problems follow the [[divide-and-conquer]] approach.

^2e25ce

**Listing 18.1** describes how to solve the closest-pair problem using the [[divide-and-conquer]] approach.

## Listing 18.1 Algorithm for Finding the Closest Pair

#### Step 1:
Sort the points in increasing order of _x_-coordinates. For the points with the same _x_-coordinates, sort on _y_-coordinates. This results in a sorted list _S_ of points.

#### Step 2:
Divide _S_ into two subsets, _S1_ and _S2_, of equal size using the midpoint in the sorted list. Let the midpoint be in _S1_. Recursively find the closest pair in _S1_ and _S2_. Let _d1_ and _d2_ denote the distance of the closest pairs in the two subsets, respectively.

#### Step 3:
Find the closest pair between a point in _S1_ and a point in _S2_ and denote their distance as _d3_. The closest pair is the one with the distance min(_d1,d2,d3_).

Selection sort takes _O_(_n2_) time. In **Chapter 19** we will introduce merge sort and heap sort. These sorting algorithms take _O_(_n_ log _n_) time. Step 1 can be done in _O_(_n_ log _n_) time.

Step 3 can be done in _O_(_n_) time. Let _d_ = min(_d1, d2_). We already know that the closest-pair distance cannot be larger than _d_. For a point in _S1_ and a point in _S2_ to form the closest pair in _S_, the left point must be in `stripL` and the right point in `stripR` as illustrated in **​Figure 18.5a**​.

![[Pasted image 20241022125834.png]]
![[Pasted image 20241022125848.png]]
![[Pasted image 20241022125858.png]]

For a point _p_ in `stripL`, you need only to consider a right point within the _d_ × 2_d_ rectangle, as shown in **Figure 18.5b**. Any right point outside the rectangle cannot form the closest pair with _p_. Since the closest-pair distance in _S_​2​ is greater than or equal to _d_, there can be at most six points in the rectangle. Thus, for each point in `stripL`, at most six points in `stripR` need to be considered.

For each point _p_ in `stripL`, how do you locate the points in the corresponding _d_ × 2_d_ rectangle area in `stripR`? This can be done efficiently if the points in `stripL` and `stripR` are sorted in increasing order of their _y_-coordinates. Let `pointsOrderedOnY` be the list of the points sorted in increasing order of _y_-coordinates. `pointsOrderedOnY` can be obtained beforehand in the algorithm. `stripL` and `stripR` can be obtained from `pointsOrderedOnY` in Step 3 as shown in **Listing 18.2**.

## **Listing 18.2 Algorithm for Obtaining stripL and stripR**
```python
for each point p in pointsOrderedOnY
	if (p is in S1 and mid.x - p.x <= d)
		append p to stripL;
	else if (p is in S2 and p.x - mid.x <= d)
		append p to stripR;
```

Let the points in `stripL` and `stripR` be {_p_0, _p_1, ..., _pk_} and {_q_0, _q_1, ..., _qt_}, as shown in **Figure 18.5c**. The closest pair between a point in `stripL` and a point in `stripR` can be found using the algorithm described in **Listing 18.3**.

## **Listing 18.3 Algorithm for Finding the Closest Pair in Step 3**
![[Pasted image 20241022130400.png]]

The points in `stripL` are considered from _p_0, _p_1, ..., _pk_ in this order. For a point `p` in `stripL`, skip the points in `stripR` that are below `p.y – d` (lines 5–6). Once a point is skipped, it will no longer be considered. The `while` loop (lines 9–17) checks whether `(p, q[r1])` is a possible closest pair. There are at most six such `q[r1]` pairs, so the complexity for finding the closest pair in Step 3 is _O_(_n_).

Let _T_(_n_) denote the time complexity for this algorithm. Thus:
$$T(n)=2T\left( \frac{n}{2} \right)+O(n)=O(n\log n)$$

Therefore, the closest pair of points can be found in _O_(_n_ log _n_) time. The complete implementation of this algorithm is left as an exercise (see **Programming Exercise 18.11**).

## Self-Check

### What is the [[divide-and-conquer]] approach? Give an example. What is the difference between [[divide-and-conquer]] and [[dynamic programming]]?

![[COSC Chapter 18.8 Finding the Closest Pair of Points using Divide-and-Conquer#^2e25ce]]

### Can you design an algorithm for finding the minimum element in a list using [[divide-and-conquer]]? What is the complexity of this algorithm?

Yes. Finding the minimum in the first half and the second half of the list and return the minimum of these two. So, the time complexity is O(n) = 2 * O(n/2) + O(1) = O(n).



# References
