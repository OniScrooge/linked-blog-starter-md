# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.3 Bubble Sort]]

Next - [[COSC Chapter 19.5 Quick Sort]]
# Content
## Key Point

The **[[merge sort]]** algorithm can be described recursively as follows: The algorithm divides the array into two halves and applies a [[merge sort]] on each half recursively. After the two halves are sorted, merge them.

The algorithm for a [[merge sort]] is given in **Listing 19.3**.

## **Listing 19.3 [[Merge Sort]] Algorithm**
```cpp
void mergeSort(int list[], int arraySize)
{
	if (arraySize > 1)
	{
		mergeSort on list[0 ... arraySize / 2];
		mergeSort on list[arraySize / 2 + 1 ... arraySize];
		merge list[0 ... arraySize / 2] with
			list[arraySize / 2 + 1 ... arraySize];
	}
}
```

**Figure 19.4** illustrates a [[merge sort]] of an array of eight elements (2 9 5 4 8 1 6 7). The original array is split into (2 9 5 4) and (8 1 6 7). Apply a [[merge sort]] on these two subarrays recursively to split (2 9 5 4) into (2 9) and (5 4) and (8 1 6 7) into (8 1) and (6 7). This process continues until the subarray contains only one element. For example, array (2 9) is split into the subarrays (2) and (9). Since array (2) contains a single element, it cannot be further split. Now merge (2) with (9) into a new sorted array (2 9); merge (5) with (4) into a new sorted array (4 5). Merge (2 9) with (4 5) into a new sorted array (2 4 5 9), and finally merge (2 4 5 9) with (1 6 7 8) into a new sorted array (1 2 4 5 6 7 8 9).

>[!note] Figure 19.4
>![[19fig04.png]]

The recursive call continues dividing the array into subarrays until each subarray contains only one element. The algorithm then merges these small subarrays into larger sorted subarrays until one sorted array results.

The merge sort algorithm is implemented in **LiveExample 19.3**.

## **LiveExample 19.3 MergeSort.cpp**
```cpp
#include <iostream>
using namespace std;

// Function prototype
void arraycopy(int source[], int sourceStartIndex,
  int target[], int targetStartIndex, int length);

void merge(int list1[], int list1Size,
  int list2[], int list2Size, int temp[]);

// The function for sorting the numbers 
void mergeSort(int list[], int arraySize)
{
  if (arraySize > 1)
  {
    // Merge sort the first half
    int* firstHalf = new int[arraySize / 2];
    arraycopy(list, 0, firstHalf, 0, arraySize / 2);
    mergeSort(firstHalf, arraySize / 2);

    // Merge sort the second half
    int secondHalfLength = arraySize - arraySize / 2;
    int* secondHalf = new int[secondHalfLength];
    arraycopy(list, arraySize / 2, secondHalf, 0, secondHalfLength);
    mergeSort(secondHalf, secondHalfLength);

    // Merge firstHalf with secondHalf
    merge(firstHalf, arraySize / 2, secondHalf, secondHalfLength,
      list);

    delete [] firstHalf;
    delete [] secondHalf;
  }
}

void merge(int list1[], int list1Size,
  int list2[], int list2Size, int temp[])
{
  int current1 = 0; // Current index in list1
  int current2 = 0; // Current index in list2
  int current3 = 0; // Current index in temp

  while (current1 < list1Size && current2 < list2Size)
  {
    if (list1[current1] < list2[current2])
      temp[current3++] = list1[current1++];
    else
      temp[current3++] = list2[current2++];
  }

  while (current1 < list1Size)
    temp[current3++] = list1[current1++];

  while (current2 < list2Size)
    temp[current3++] = list2[current2++];
}

void arraycopy(int source[], int sourceStartIndex,
  int target[], int targetStartIndex, int length)
{
  for (int i = 0; i < length; i++)
  {
    target[i + targetStartIndex] = source[i + sourceStartIndex];
  }
}

int main()
{
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  mergeSort(list, SIZE);
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";

  return 0;
}  
```
```
command>cl MergeSort.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>MergeSort 
1 1 2 3 3 3 4 7 9 

command>
```

The `mergeSort` function (lines 12–34) creates a new array `firstHalf`, which is a copy of the first half of `list` (line 18). The algorithm invokes `mergeSort` recursively on `firstHalf` (line 19). The length of the `firstHalf` is `arraySize / 2` and that of the `secondHalf` is `arraySize - arraySize / 2`. The new array `secondHalf` was created to contain the second part of the original array `list`. The algorithm invokes `mergeSort` recursively on `secondHalf` (line 25). After `firstHalf` and `secondHalf` are sorted, they are merged to `list` (lines 28–29). So, array `list` is now sorted.

The `merge` function (lines 36–56) merges two sorted arrays. This function merges arrays `list1` and `list2` into a new array `temp`. So, the size of `temp` should be `list1Size + list2Size`. `current1` and `current2` point to the current element to be considered in `list1` and `list2` (lines 39–41). The function repeatedly compares the current elements from `list1` and `list2` and moves the smaller one to `temp`. If the smaller one is in `list1`, `current1` is increased by `1` (line 46). If the smaller one is in `list2`, `current2` is increased by `1` (line 48). Finally, all the elements in one of the lists are moved to `temp`. If there are still unmoved elements in `list1`, copy them to `temp` (lines 51–52). If there are still unmoved elements in `list2`, copy them to `temp` (lines 54–55).

The `mergeSort` function creates two temporary arrays (lines 17 and 23) during the dividing process, copies the first half and the second half of the array into the temporary arrays (lines 18 and 24), sorts the temporary arrays (lines 19 and 25), and then merges them into the original array (lines 28-29), as shown in **Figure 19.5a**. You can rewrite the code to recursively sort the first half of the array and the second half of the array without creating new temporary arrays, and then merge the two arrays into a temporary array and copy its contents to the original array, as shown in **Figure 23.6b**. This is left for you to do in **Programming Exercise 19.20**.

>[!note] Figure 19.5
>![[Pasted image 20241107105528.png]]
>![[Pasted image 20241107105542.png]]

Let _T_(_n_) denote the time required for sorting an array of _n_ elements using merge sort. Without loss of generality, assume _n_ is a power of 2. The merge sort algorithm copies the array into two subarrays, sorts them using the same algorithm recursively, and then merges the subarrays. The time to copy `list` to `firstHalf` and `secondHalf` is _n_ and the time to merge two sorted subarrays is _n_ − 1. So,

$$T(n)=T(n2)+T(n2)+n+n−1$$

The first T(n2) is the time for sorting the first half of the array and the second T(n2) is the time for sorting the second half. It can be shown that

$$T(n)=2T(n2)+2n−1=O(n log n)$$

The complexity of merge sort is _O_(_n_ log _n_). This algorithm is better than selection sort, insertion sort, and bubble sort.

## Self-Check
### Describe how a merge sort works. What is the time complexity for a merge sort?
The time complexity for a merge sort is $O(n)$.
The worst time complexity for a merge sort is $O(nlogn)$.
The average time complexity for a merge sort is $O(nlogn)$.
### Use Figure 19.4 as an example to show how to apply a merge sort on
Omitted.
### What is the time complexity for a merge sort?

$O(nlogn)$
# References
