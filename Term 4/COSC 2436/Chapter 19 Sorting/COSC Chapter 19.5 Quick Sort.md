# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.4 Merge Sort]]

Next - [[COSC Chapter 19.6 Heap Sort]]
# Content
## Key Point

_A_ **[[quick sort]]** works as follows: The algorithm selects an element, called the _pivot_, in the array. It divides the array into two parts, so that all the elements in the first part are less than or equal to the pivot and all the elements in the second part are greater than the pivot. The [[quick sort]] algorithm is then recursively applied to the first part and then the second part.

The [[quick sort]] algorithm, developed by C. A. R. Hoare in 1962, is described in **Listing 19.4**.

## **Listing 19.4 [[Quick Sort]] Algorithm**
![[Pasted image 20241107110109.png]]
Each partition places the pivot in the right place. It divides the list into two sublists as show in the following figures.

![[Pasted image 20241107110130.png]]

The selection of the pivot affects the performance of the algorithm. Ideally, the algorithm should choose the pivot that divides the two parts evenly. For simplicity, assume the first element in the array is chosen as the pivot. (**Programming Exercise 19.4** proposes an alternative strategy for selecting the pivot.)

**Figure 19.6** illustrates how to sort an array (5 2 9 3 8 4 0 1 6 7) using [[quick sort]]. Choose the first element, 5, as the pivot. The array is partitioned into two parts, as shown in **Figure 19.6b**. The highlighted pivot is placed in the right place in the array. Apply [[quick sort]] on two partial arrays (4 2 1 3 0) and then (8 9 6 7). The pivot 4 partitions (4 2 1 3 0) into just one partial array (0 2 1 3), as shown in **Figure 19.6c**. Apply [[quick sort]] on (0 2 1 3). The pivot 0 partitions it into just one partial array (2 1 3), as shown in **Figure 19.6d**. Apply [[quick sort]] on (2 1 3). The pivot 2 partitions it into (1) and (3), as shown in **Figure 19.6e**. Apply [[quick sort]] on (1). Since the array contains just one element, no further partition is needed.

>[!note] Figure 19.6
>![[Pasted image 20241107110204.png]]
>![[Pasted image 20241107110216.png]]
>![[Pasted image 20241107110229.png]]
>![[Pasted image 20241107110238.png]]

The [[quick sort]] algorithm is implemented in **LiveExample 19.4**. There are two overloaded `quickSort` functions in the class. The first [[function]] (line 5) is used to sort an array. The second is a helper [[function]] (line 6) that sorts a partial array with a specified range.

## **LiveExample 19.4 QuickSort.cpp**
```cpp
#include <iostream>
using namespace std;

// Function prototypes
void quickSort(int list[], int arraySize);
void quickSort(int list[], int first, int last);
int partition(int list[], int first, int last);

void quickSort(int list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

void quickSort(int list[], int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

// Partition the array list[first..last] 
int partition(int list[], int first, int last)
{
  int pivot = list[first]; // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low] <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high] > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      int temp = list[high];
      list[high] = list[low];
      list[low] = temp;
    }
  }

  while (high > first && list[high] >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high])
  {
    list[first] = list[high];
    list[high] = pivot;
    return high;
  }
  else
  {
    return first;
  }
}

int main()
{
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  quickSort(list, SIZE);
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";

  return 0;
}  
```
```
command>cl QuickSort.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>QuickSort 
1 1 2 3 3 3 4 7 9 

command>
```

The `partition` [[function]] (lines 25–64) partitions array `list[first..last]` using the pivot. The first element in the partial array is chosen as the pivot (line 27). Initially, `low` points to the second element in the partial array (line 28), and `high` points to the last element in the partial array (line 29).

The [[function]] searches for the first element from left forward in the array that is greater than the pivot (lines 34–35), then search for the first element from right backward in the array that is less than or equal to the pivot (lines 38–39). Swap these two elements (line 42-47). Repeat the same search and swap operations until all the elements are searched in the while loop (lines 31–48).

The [[function]] returns the new index for the pivot that divides the partial array into two parts if the pivot has been moved (line 58). Otherwise, return the original index for the pivot (line 62).

To partition an array of _n_ elements, it takes _n_ comparisons and _n_ moves in the worst-case analysis. Thus, the time required for partition is _O_(_n_).

In the **worst case**, the pivot divides the array each time into one big subarray with the other array empty. The size of the big subarray is one less than the one before divided. The algorithm requires (n − 1) + (n − 2) + … + 2 + 1 = O (n2) time.

In the **best case**, the pivot divides the array each time into two parts of about the same size. Let _T_(_n_) denote the time required for sorting an array of _n_ elements using [[quick sort]]. Thus:
![[Pasted image 20241107110353.png]]

Similar to the [[merge sort]] analysis, $T(n)=O(n log n)$.

On the average, the pivot will not divide the array into two parts of the same size or one empty part each time. Statistically, the sizes of the two parts are very close. Therefore, the average time is _O_(_n_ log _n_). The exact [[average-case analysis]] is beyond the scope of this book.

Both [[merge sort]] and [[quick sort]] employ the [[divide-and-conquer]] approach. For [[merge sort]], the bulk of the work is to merge two sublists, which takes place _after_ the sublists are sorted. For [[quick sort]], the bulk of the work is to partition the list into two sublists, which takes place _before_ the sublists are sorted. [[Merge sort]] is more efficient than [[quick sort]] in the worst case, but the two are equally efficient in the average case. [[Merge sort]] requires a temporary array for sorting two subarrays. [[Quick sort]] does not need additional array space. Thus, [[quick sort]] is more space efficient than [[merge sort]].

## Self-Check
### Describe how [[quick sort]] works. What is the time complexity for a [[quick sort]]?

See the text. The time complexity for a [[quick sort]] is O(n^2) in the worst case and O(nlogn) in the average case.

### Why is [[quick sort]] more space efficient than [[merge sort]]?

[[Quick sort]] does not need to create temporary arrays, while [[merge sort]] needs temporary arrrys.

### Use Figure 19.7 as an example to show how to apply a [[quick sort]] on {45, 11, 50, 59, 60, 2, 4, 7, 10}.

Omitted.



# References
