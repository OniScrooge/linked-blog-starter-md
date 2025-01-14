This section defines a generic sort function.

**LiveExample 7.11**, SelectionSort.h, gives a function to sort an array of double values. Here is a copy of the function:

```cpp
    void selectionSort(double list[], int listSize)
    {
      for (int i = 0; i < listSize; i++) 
      { 
        // Find the minimum in the list[i..listSize-1] 
        double currentMin = list[i]; 
        int currentMinIndex = i; 
        for (int j = i + 1; j < listSize; j++) 
       { 
         if (currentMin > list[j]) 
         { 
           currentMin = list[j]; 
           currentMinIndex = j; 
         } 
       } 
       // Swap list[i] with list[currentMinIndex] if necessary 
       if (currentMinIndex != i) 
       { 
         list[currentMinIndex] = list[i]; 
         list[i] = currentMin; 
       } 
     } 
   } 
```

It is easy to modify this function to write new overloaded functions for sorting an array of `int` values, `char` values, `string` values, and so on. All you need to do is to replace the word `double` by `int`, `char`, or `string` in two places (lines 1 and 6).

**​**​Instead of writing several overloaded sort functions, you can define just one template function that works for any type. **LiveExample 12.3** defines a generic function for sorting an arr​ay of elements.

**LiveExample 12.3 GenericSort.cpp**
```C++
#include <iostream>
#include <string>
using namespace std;

template<typename T>
void sort(T list[], int listSize) 
{
  for (int i = 0; i < listSize; i++) 
  {
    // Find the minimum in the list[i..listSize-1]
    T currentMin = list[i];
    int currentMinIndex = i;

    for (int j = i + 1; j < listSize; j++) 
    {
      if (FILL_CODE_OR_CLICK_ANSWER) 
      {
        currentMin = list[j];
        currentMinIndex = j;
      }
    }

    // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMinIndex != i) 
    {
      list[currentMinIndex] = list[i];
      list[i] = currentMin;
    }
  }
}

template<typename T>
void printArray(const T list[], int listSize)
{
  for (int i = 0; i < listSize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

int main()
{
  int list1[] = {3, 5, 1, 0, 2, 8, 7};
  sort(list1, 7);
  printArray(list1, 7);

  double list2[] = {3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7};
  sort(list2, 7);
  printArray(list2, 7);

  string list3[] = {"Atlanta", "Denver", "Chicago", "Dallas"};
  sort(list3, 4);
  printArray(list3, 4);

  return 0;
}
```

```
command>cl GenericSort.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>GenericSort 
0 1 2 3 5 7 8 
0.4 0.5 1.4 1.8 2.5 3.5 4.7 
Atlanta Chicago Dallas Denver 

command>
```

Two template functions are defined in this program. The template function `sort` (lines 5–30) uses the type parameter `T` to specify the element type in an array. This function is identical to the `selectionSort` function except that the parameter `double` is replaced by a generic type `T`.

The template function `printArray` (lines 32–40) uses the type parameter `T` to specify the element type in an array. This function displays all the elements in the array to the console.

The `main` function invokes the `sort` function to sort an array of `int`, `double`, and `string` values (lines 45, 49, 53) and invokes the `printArray` function to display these arrays (lines 46, 50, 54).

>[!Tip]
When you define a generic function, it is better to start with a nongeneric function, debug and test it, and then convert it to a generic function.

## Self-Check

>[!faq]- Suppose you define the swap function as follows:
>swap(v1, d2) is wrong because v1 and d2 are of different types.  
>swap(1, 2) is wrong, because 1 and 2 are values, the variables are required to invoke the swap function.
```C++
template<typename T>
void swap(T& var1, T& var2)
{
  T temp = var1;
  var1 = var2;
  var2 = temp;
}

What is wrong in the following code?

int main()
{
  int v1 = 1;
  int v2 = 2;
  swap(v1, v2);

  double d1 = 1;
  double d2 = 2;
  swap(d1, d2);

  swap(v1, d2);
  swap(1, 2);

  return 0;
}
```
