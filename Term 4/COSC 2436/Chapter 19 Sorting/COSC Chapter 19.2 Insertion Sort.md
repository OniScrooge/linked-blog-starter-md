# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.1 Introduction]]

Next - [[COSC Chapter 19.3 Bubble Sort]]
# Content
## Key Point

The insertion-sort algorithm sorts a list of values by repeatedly inserting a new element into a sorted sublist until the whole list is sorted.

The algorithm can be described as follows:

```cpp
    for (int i = 1; i < listSize; i++) 
    { 
      insert list[i] into a sorted sublist list[0..i-1] so that 
      list[0..i] is sorted. 
    } 
```

To insert `list[i]`  into `list[0..i-1]`, save `list[i]` into a temporary variable, say `currentElement`. Move `list[i-1]` to `list[i]` if `list[i-1] > currentElement`, move `list[i-2]` to `list[i-1]` if `list[i-2] > currentElement`, and so on, until `list[i-k] <= currentElement` or `k > i` (we pass the first element of the sorted list). Assign `currentElement` to `list[i-k+1]`. For example, to insert `4` into {`2`, `5`, `9`} in Step 4 in **Figure 19.2**, move `list[2]` (`9`) to `list[3]` since `9 > 4`, and move `list[1]` (`5`) to `list[2]` since `5 > 4`. Finally, move `currentElement` (`4`) to `list[1]`.

>[!note] Figure 19.2
>![[Pasted image 20241107103324.png]]
>![[Pasted image 20241107103338.png]]
>![[Pasted image 20241107103352.png]]
>![[Pasted image 20241107103400.png]]

The algorithm can be expanded and implemented as in **LiveExample 19.1**.

## **LiveExample 19.1 InsertionSort.cpp**
```cpp
#include <iostream>
using namespace std;

void insertionSort(int list[], int listSize) 
{
  for (int i = 1; i < listSize; i++) 
  {
    // Insert list[i] into a sorted sublist list[0..i-1] so that
    //  list[0..i] is sorted. 
    int currentElement = list[i];
    int k;
    for (k = i - 1; k >= 0 && list[k] > currentElement; k--) 
    {
      list[k + 1] = list[k];
    }

    // Insert the current element into list[k+1]
    list[k + 1] = currentElement;
  }
}

int main()
{
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  insertionSort(list, SIZE);
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";

  return 0;
}  
```
```
command>cl InsertionSort.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>InsertionSort 
1 1 2 3 3 3 4 7 9 

command>
```

The `insertionSort` function sorts any array of `int` elements. The function is implemented with a nested `for` loop. The outer loop (with the loop control variable `i`) (line 6) is iterated in order to obtain a sorted sublist, which ranges from `list[0]` to `list[i]`. The inner loop (with the loop control variable `k`) inserts `list[i]` into the sublist from `list[0]` to `list[i-1]`.

To better understand this function, trace it with the following statements:

```cpp
int list[] = {1, 9, 4.5, 6.6, 5.7, -4.5}; 
insertionSort(list, 6);  
```

The insertion sort algorithm presented here sorts a list of elements by repeatedly inserting a new element into a sorted partial array until the whole array is sorted. At the _k_th iteration, to insert an element into an array of size _k_, it may take _k_ comparisons to find the insertion position, and _k_ moves to insert the element. Let _T_(_n_) denote the complexity for insertion sort and _c_ denote the total number of other operations such as assignments and additional comparisons in each iteration. Thus,

$$T(n)=(2+c)+(2×2+c)+…+(2×(n−1)+c)$$
$$=2(1+2+…+n−1)+c(n−1)$$
$$=2(n − 1)n2+cn−c=n2−n+cn−c$$
$$=O(n2)$$

Therefore, the complexity of the insertion sort algorithm is _O_(_n_2). Hence, the selection sort and insertion sort are of the same time complexity.

# Self-Check
### Describe how an insertion sort works. What is the time complexity for an insertion sort?

See the text. The time complexity for an insertion sort is O(n^2).

### Use Figure 19.1 as an example to show how to apply an insertion sort on {45, 11, 50, 59, 60, 2, 4, 7, 10}.

Omitted.

### If a list is already sorted, how many comparisons will the `insertionSort()` function perform?

n - 1 times.
# References
