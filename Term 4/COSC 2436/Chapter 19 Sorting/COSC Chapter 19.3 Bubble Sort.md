# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.2 Insertion Sort]]

Next - [[COSC Chapter 19.4 Merge Sort]]
# Content
## Key Point

A [[bubble sort]] sorts the array in multiple passes. Each pass successively swaps the neighboring elements if the elements are not in order.

The [[bubble sort]] algorithm makes several passes through the array. On each pass, successive neighboring pairs are compared. If a pair is in decreasing order, its values are swapped; otherwise, the values remain unchanged. The technique is called a [[bubble sort]] or _sinking​ sort_, ​because​ the smaller values gradually “bubble” their way to the top and the larger values sink to the bottom. After the first pass, the last element becomes the largest in the array. After the second pass, the second-to-last element becomes the second largest in the array. This process is continued until all elements are sorted.

The algorithm for a bubble sort is described in **Listing 19.1**.

## **Listing 19.1 Bubble Sort Algorithm**
```cpp
1 for (int k = 1; k < arraySize; k++) 
2 { 
3   // Perform the kth pass 
4   for (int i = 0; i < arraySize - k; i++) 
5   { 
6     if (list[i] > list[i + 1]) 
7       swap list[i] with list[i + 1]; 
8   } 
9 } 
 
```

Note that if no swap takes place in a pass, there is no need to perform the next pass, because all the elements are already sorted. You can use this property to improve the algorithm in **Listing 19.1** as in **Listing 19.2**.

## **Listing 19.2 Improved Bubble Sort Algorithm**
```cpp
1  bool needNextPass = true; 
2  for (int k = 1; k < arraySize && needNextPass; k++) 
3  { 
4    // Array may be sorted and next pass not needed 
5    needNextPass = false; 
6    // Perform the kth pass 
7    for (int i = 0; i < arraySize - k; i++) 
8    { 
9      if (list[i] > list[i + 1]) 
10      { 
11        swap list[i] with list[i + 1]; 
12        needNextPass = true; // Next pass still needed 
13      } 
14    } 
15  } 
 
```

The algorithm can be implemented in **LiveExample 19.2**.

#### **LiveExample 19.2 BubbleSort.cpp**
```cpp
#include <iostream>
using namespace std;

// The function for sorting the numbers 
void bubbleSort(int list[], int arraySize)
{
  bool needNextPass = true;

  for (int k = 1; k < arraySize && needNextPass; k++)
  {
    // Array may be sorted and next pass not needed
    needNextPass = false;
    for (int i = 0; i < arraySize - k; i++)
    {
      if (list[i] > list[i + 1])
      {
        // Swap list[i] with list[i + 1]
        int temp = list[i];
        list[i] = list[i + 1];
        list[i + 1] = temp;

        needNextPass = true; // Next pass still needed
      }
    }
  }
}

int main()
{
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  bubbleSort(list, SIZE);
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";

  return 0;
}  
```
```
command>cl BubbleSort.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BubbleSort 
1 1 2 3 3 3 4 7 9 

command>
```

In the best-case analysis, the bubble sort algorithm needs just the first pass to find that the array is already sorted—no next pass is needed. Since the number of comparisons is n − 1 in the first pass, the best-case time for a bubble sort is _O_(_n_).

In the worst-case analysis, the bubble sort algorithm requires n−1 passes. The first pass makes n − 1 comparisons; the second pass makes n − 2 comparisons; and so on; the last pass makes 1 comparison. Thus, the total number of comparisons is:

$$(n−1)+(n−2)+… + 2 + 1$$
$$= (n − 1)n2 = n22 − n2 =O(n2)$$

Therefore, the worst-case time for a bubble sort is _O_(_n2_).

## Self-Check
### Describe how a bubble sort works. What is the time complexity for a bubble sort?

See the text. The time complexity for a bubble sort is O(n^2).

### Use Figure 19.3 as an example to show how to apply a bubble sort on

Omitted.

### If a list is already sorted, how many comparisons will the `bubbleSort()` function perform?

n - 1 times.
# References
