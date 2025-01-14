# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.6.6 Heap Sort Time Complexity]]

Next - [[COSC Chapter 19.8 External Sort]]
# Content
## Key Point

Bucket sorts and radix sorts are efficient for sorting integers.

All sort algorithms discussed so far are general sorting algorithms that work for any types of keys (e.g., integers, strings, and any comparable objects). These algorithms sort the elements by comparing their keys. The lower bound for general sorting algorithms is _O_(_n_ log _n_), so no sorting algorithms based on comparisons can perform better than _O_(_n_ log _n_). However, if the keys are small integers, you can use a [[bucket sort]] without having to compare the keys.

The [[bucket sort]] algorithm works as follows. Assume the keys are in the range from `0` to `t`. We need `t + 1` buckets labeled `0`, `1`, ..., and `t`. If an element’s key is `i`, the element is put into the bucket `i`. Each bucket holds the elements with the same key value.

![[Pasted image 20241107113617.png]]

You can use a vector to implement a bucket. Clearly, it takes O(n+t) time to sort the list and uses O(n+t)space, where _n_ is the list size.

Note that if _t_ is too large, using the [[bucket sort]] is not desirable. Instead, you can use a radix sort. The radix sort is based on the [[bucket sort]], but a radix sort uses only ten buckets.

It is worthwhile to note that a [[bucket sort]] is stable, meaning that if two elements in the original list have the same key value, their order is not changed in the sorted list. That is, if element e1 and element e2 have the same key and e1 precedes e2 in the original list, e1 still precedes e2 in the sorted list.

Assume that the keys are positive integers. The idea for the [radix sort](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/f2c4ef63-c7a2-459a-8ae7-031c52d1d56d/pages/urn:pearson:entity:f5936eb1-044a-4bc9-8092-2af5be6859bc?source=dashboard#) is to divide the keys into subgroups based on their radix positions. It applies a [[bucket sort]] repeatedly for the key values on radix positions, starting from the least-significant position.

Consider sorting the elements with the following keys:

```cpp
331, 454, 230, 34, 343, 45, 59, 453, 345, 231, 9 
 
```

Apply the [[bucket sort]] on the last radix position, and the elements are put into the buckets as follows:
![[Pasted image 20241107113641.png]]

After being removed from the buckets, the elements are in the following order:

```cpp
230, 331, 231, 343, 453, 454, 34, 45, 345, 59, 9 
 
```

Apply the [[bucket sort]] on the second-to-last radix position, and the elements are put into the buckets as follows:
![[Pasted image 20241107113657.png]]

After being removed from the buckets, the elements are in the following order:

```cpp
9, 230, 331, 231, 34, 343, 45, 345, 453, 454, 59 
 
```

(Note that `9` is `009`.)

Apply the [[bucket sort]] on the third-to-last radix position, and the elements are put into the buckets as follows:
![[Pasted image 20241107113714.png]]

After being removed from the buckets, the elements are in the following order:

```cpp
9, 34, 45, 59, 230, 231, 331, 343, 345, 453, 454 
 
```

The elements are now sorted.

In general, radix sort takes _O_(_dn_) time to sort _n_ elements with integer keys, where _d_ is the maximum number of the radix positions among all keys.

## Self-Check
### Can you sort a list of strings using a [[bucket sort]]?

[[Bucket sort]] is not suitable for sorting strings.
# References
