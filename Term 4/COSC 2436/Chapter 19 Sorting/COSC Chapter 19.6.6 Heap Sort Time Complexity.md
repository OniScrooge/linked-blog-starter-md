# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.6.5 Sorting Using the Heap Class]]

Next - [[COSC Chapter 19.7 Bucket Sort and Radix Sort]]
# Content
Let us turn our attention to analyzing the time complexity for the [[heap sort]]. Let _h_ denote the [height for a heap](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/f2c4ef63-c7a2-459a-8ae7-031c52d1d56d/pages/urn:pearson:entity:2177136f-df37-4c64-98ca-1c20b8aa7eb6?source=dashboard#) of _n_ elements. The height of a nonempty tree is the length of the path from the root node to its furthest leaf. The _height_ of a tree that contains a single node is ∅`.` Conventionally, the height of an empty tree is −1. Since a heap is a [[complete binary tree]], the first level has 1 (20) node, the second level has 2 (21) nodes, the _k_th level has 2k−1 nodes, the _h_ level has 2h−1 nodes, and the last (_h_+_1_)th level has at least 1 and at most 2h nodes. Therefore,
$$1+2+…+2h−1ᐸn≤1+2…+2h−1+2h$$
That is,
$$2h−1ᐸn≤2h+1−12hᐸn+1≤2h+1hᐸlog(n+1)≤h+1$$
Thus, $h  ᐸ log (n + 1)$   and $h ≥ log  (n + 1) -1$. Therefore, $log  (n + 1) -1 ≤ h ᐸ log  (n + 1)$. Hence, the height of a heap is $O(logn)$. More precisely, you can prove that $h = [logn]$ for a non-empty tree.

Since the `add` [[function]] traces a path from a leaf to a root, it takes at most _h_ steps to add a new element to the heap. Thus, the total time for constructing an initial heap is _O_(_n_ log _n_) for an array of _n_ elements. Since the `remove` [[function]] traces a path from a root to a leaf, it takes at most _h_ steps to rebuild a heap after removing the root from the heap. Since the `remove` [[function]] is invoked _n_ times, the total time for producing a sorted array from a heap is _O_(_n_ log _n_).

Both merge sorts and heap sorts require _O_(_n_ log _n_) time. A [[merge sort]] requires a temporary array for merging two subarrays; a [[heap sort]] does not need additional array space. Therefore, a [[heap sort]] is more space efficient than a [[merge sort]].
## Self-Check
### What is the time complexity of inserting a new element into a heap and what is the time complexity of deleting an element from a heap?
$O(logn)$ for both insertion and deletion.
### What is the height of an empty heap? What is the height of a heap with only one element? What is the height of a non-empty heap? What is the height of a heap with 16, 17, and 512 elements? If the height of a heap is 5, what is the maximum number of nodes in the heap?
The height of an empty heap is -1 be definition. The height of a heap with only one element is 0. The height of a non-empty heap is the length of a longest path from the root to a leaf. The height of heap with 16 elements is 4. The height of heap with 17 elements is 4. The height of heap with 512 elements is 9. The maximum number of nodes in a heap of height 5 is 63.
# References
