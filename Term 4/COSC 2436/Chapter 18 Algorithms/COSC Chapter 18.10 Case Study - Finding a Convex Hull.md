# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.9 Solving the Eight Queens Problem using Backtracking]]

Next - [[COSC Chapter 18.11 String Matching]]
# Content

## Key Point

This section presents efficient geometric algorithms for finding a [[convex hull]] for a set of points.

Given a set of points, a [[convex hull]] is a smallest convex polygon that encloses all these points, as shown in **​Figure 18.7a**​. A polygon is convex if every line connecting two vertices is inside the polygon. For example, the vertices v0, v1, v2, v3, v4, and v5 in **​Figure 18.7a**​ form a convex polygon, but not in **​Figure 18.7b**​, because the line that connects v3 and v1 is not inside the polygon.

>[!info] Figure 18.7
>![[Pasted image 20241022132727.png]]

[[Convex hull]] has many applications in game programming, pattern recognition, and image processing. Before we introduce the algorithms, it is helpful to get acquainted with the concept using an interactive tool shown in **Figure 18.8**. The tool allows you to add/remove points and displays the [[convex hull]] dynamically.

## Figure 18.8 [[Convex Hull]] Animation
![[Pasted image 20241022132758.png]]

Many algorithms have been developed to find a [[convex hull]]. This section introduces two popular algorithms: gift-wrapping and Graham’s algorithms.

## 18.10.1 Gift-Wrapping Algorithm

An intuitive approach, called the _gift-wrapping algorithm_, is given in **Listing 18.4**.

__Listing 18.4 [[Convex Hull]] Gift-Wrapping Algorithm__

Step 1: Given a set of points S, let the points in S be labeled s0, s1, ..., sk. Select the rightmost lowest point h0 in the set S. As shown in **Figure 18.9a**, h0 is such a point. Add h0 to the [[convex hull]] H. H is a set initially being empty. Let t0 be h0.

Step 2: Let t1 be s0.
1. For every point s in S
2. if s is on the right side of the direct line from t0 to t1 then
3. let t1 be s.

(After Step 2, no points lie on the right side of the direct line from t0 to t1, as shown in **Figure 18.9b**.)

Step 3: If t1 is h0 (see **Figure 18.9d**), the points in H form a [[convex hull]] for S. Otherwise, add t1 to H, let t0 be t1, and go to Step 2 (see **Figure 18.9c**).

>[!info] Figure 18.9
>![[Pasted image 20241022132855.png]]
>![[Pasted image 20241022132905.png]]
>![[Pasted image 20241022132917.png]]
>![[Pasted image 20241022132927.png]]

a) h0 is the rightmost lowest point in S. (b) Step 2 finds point t1. (c) A [[convex hull]] is expanded repeatedly. (d) A [[convex hull]] is found when t1 becomes h0.

The [[convex hull]] is expanded incrementally. The correctness is supported by the fact that no points lie on the right side of the direct line from t0 to t1 after Step 2. This ensures that every line segment with two points in S falls inside the polygon.

Finding the rightmost lowest point in Step 1 can be done in _O_(_n_) time. Whether a point is on the left side of a line, right side, or on the line can be decided in _O_(1) time (see **Programming Exercise 3.29**). Thus, it takes _O_(_n_) time to find a new point t1 in Step 2. Step 2 is repeated h times, where h is the size of the [[convex hull]]. Therefore, the algorithm takes _O_(_hn_) time. In the worst case, h is n. The implementation of this algorithm is left as an exercise (see **Programming Exercise 18.11**).

## Listing 18.5 [[Convex Hull]] Graham's Algorithm

A more efficient algorithm was developed by Ronald Graham in 1972.

Step 1: Given a set of points S, select the rightmost lowest point p0 in the set S. As shown in **​Figure 18.10a**​, p0 is such a point.

Step 2: Sort the points in S angularly along the x-axis with p0 as the center, as shown in **​Figure 18.10b**​. If there is a tie and two points have the same angle, discard the one that is closest to p0. The points in S are now sorted as p0, p1, p2, ..., pn-1.

Step 3: Push p0, p1, and p2 into a stack H.

Step 4:
```cpp
i = 3; 
while (i < n) 
{ 
  Let t1 and t2 be the top first and second element in stack H; 
  if (pi is on the left side of the direct line from t2 to t1) 
  { 
    Push pi to H; 
    i++; // Consider the next point in S. 
  } 
  else 
    Pop the top element off the stack H. 
} 
```

Step 5: The points in H form a [[convex hull]].

>[!info] Figure 18.10
>![[Pasted image 20241022133304.png]]
>![[Pasted image 20241022133312.png]]
>![[Pasted image 20241022133322.png]]
>![[Pasted image 20241022133331.png]]

(a) p0 is the rightmost lowest point in S. (b) Points are sorted by the angles. (c and d) A [[convex hull]] is discovered incrementally.

The [[convex hull]] is discovered incrementally. Initially, p0, p1, and p2 form a [[convex hull]]. Consider p3. p3 is outside of the current [[convex hull]] since points are sorted in increasing order of their angles. If p3 is strictly on the left side of the line from p1 to p2 (see **​Figure 18.10c**​), push p3 into H. Now p0, p1, p2, and p3 form a [[convex hull]]. If p3 is on the right side of the line from p1 to p2 (see **​Figure 18.10d**​), pop p2 out of H and push p3 into H. Now p0, p1, and p3 form a [[convex hull]] and p2 is inside of this [[convex hull]]. You can prove by induction that all the points in H in Step 5 form a [[convex hull]] for all the points in the input set S.

Finding the rightmost lowest point in Step 1 can be done in _O_(_n_) time. The angles can be computed using trigonometry functions. However, you can sort the points without actually computing their angles. Observe that p2 would make a greater angle than p1 if and only if p2 lies on the left side of the line from p0 to p1. Whether a point is on the left side of a line can be decided in _O_(1) time as shown in **Programming Exercise 3.29**. Sorting in Step 2 can be done in _O_(_n_ log _n_) time using the merge-sort or heap-sort algorithm to be introduced in **Chapter 19**. Step 4 can be done in _O_(_n_) time. Therefore, the algorithm takes _O_(_n_ log _n_) time.

The implementation of this algorithm is left as an exercise (see **Programming Exercise 18.13**).

# References
