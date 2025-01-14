# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.4 Problem Solving Using Recursion]]

Next - [[COSC Chapter 17.6 Towers of Hanoi]]
# Content
## Key Point
Sometimes you can find a solution to the original problem by defining a [[recursive function]] to a problem similar to the original problem. This new [[function]] is called a [[recursive helper function]]. The original problem can be solved by invoking the [[recursive helper function]].

The preceding recursive `isPalindrome` [[function]] is not efficient, because it creates a new string for every recursive call. To avoid creating new strings, you can use the `low` and `high` indices to indicate the range of the substring. These two indices must be passed to the [[recursive function]]. Since the original [[function]] is `isPalindrome(const string& s)`, you have to create a new [[recursive helper function]] `isPalindrome(const string& s, int low, int high)` to accept additional information on the string, as shown in **LiveExample 17.4**.

#### **LiveExample 17.4 RecursivePalindromeUsingHelperFunction.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int low, int high)
{
  if (high <= low) // Base case
    return true;
  else if (s[low] != s[high]) // Base case
    return false;
  else
    return isPalindrome(s, low + 1, high - 1);
}

bool isPalindrome(const string& s)
{
  return isPalindrome(s, 0, s.size() - 1);
}

int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  if (isPalindrome(s))
    cout << s << " is a palindrome" << endl;
  else
    cout << s << " is not a palindrome" << endl;

  return 0;
}
```
```
command>cl RecursivePalindromeUsingHelperFunction.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>RecursivePalindromeUsingHelperFunction 
Enter a string: abccba
abccba is a palindrome

command>
```

Two overloaded `isPalindrome` functions are defined. The [[function]] `isPalindrome(const string& s)` (line 15) checks whether a string is a palindrome, and the second [[function]] `isPalindrome(const string& s, int low, int high)` (line 5) checks whether a substring `s(low..high)` is a palindrome. The first [[function]] passes the string `s` with `low = 0` and `high = s.size() – 1` to the second [[function]]. The second [[function]] can be invoked recursively to check a palindrome in an ever-shrinking substring. It is a common design technique in recursive programming to define a second [[function]] that receives additional parameters. Such a [[function]] is known as a _[[recursive helper function]]_.

Helper functions are very useful to design recursive solutions for problems involving strings and arrays. The sections that follow present two more examples.

## 17.5.1 Selection Sort

Selection sort was introduced in **Section 7.10**, “Sorting Arrays.” Now we introduce a recursive selection sort for characters in a string. A variation of selection sort works as follows. It finds the largest element in the list and places it last. It then finds the largest element remaining and places it next to last, and so on until the list contains only a single element. The problem can be divided into two subproblems:
- Find the largest element in the list and swap it with the last element.
- Ignore the last element and sort the remaining smaller list recursively.

The [[base case]] is that the list contains only one element.

**LiveExample 17.5** gives the recursive sort [[function]].

## **LiveExample 17.5 RecursiveSelectionSort.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

void sort(string& s)
{
  sort(s, s.size() - 1);
}

void sort(string& s, int high)
{
  if (high > 0)
  {
    // Find the largest element and its index
    int indexOfMax = 0;
    char max = s[0];
    for (int i = 1; i <= high; i++)
    {
      if (s[i] > max)
      {
        max = s[i];
        indexOfMax = i;
      }
    }

    // Swap the largest with the last element in the list
    s[indexOfMax] = s[high];
    s[high] = max;

    // Sort the remaining list
    sort(s, high - 1);
  }
}

int main()
{
  cout << "Enter a string: ";
  string s;
  getline(cin, s);

  sort(s);

  cout << "The sorted string is " << s << endl;

  return 0;
}
```
```
command>cl RecursiveSelectionSort.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>RecursiveSelectionSort 
Enter a string: abccba
The sorted string is aabbcc

command>
```

Two overloaded `sort` functions are defined in lines 5-33. The [[function]] `sort(string& s)` sorts characters in `s[0..s.size() - 1]` and the second [[function]] `sort(string& s, int high)` sorts characters in `s[0..high]`. The helper [[function]] can be invoked recursively to sort an ever-shrinking substring.

## 17.5.2 Binary Search

Binary search was introduced in **Section 7.9.2**, “The Binary Search Approach.” For binary search to work, the elements in the array must already be ordered. The binary search first compares the key with the element in the middle of the array. Consider the following cases:
- `Case 1`: If the key is less than the middle element, recursively search the key in the first half of the array.
- `Case 2`: If the key is equal to the middle element, the search ends with a match.
- `Case 3`: If the key is greater than the middle element, recursively search the key in the second half of the array.

Case 1 and Case 3 reduce the search to a smaller list. Case 2 is a [[base case]] when there is a match. Another [[base case]] is that the search is exhausted without a match. **LiveExample 17.6** gives a clear, simple solution for the binary search problem using recursion.

## **LiveExample 17.6 RecursiveBinarySearch.cpp**
```cpp
#include <iostream>
using namespace std;

int binarySearch(const int list[], int key, int low, int high)
{
  if (low > high)  // The list has been exhausted without a match
    return -low - 1; // key not found, return the insertion point

  int mid = (low + high) / 2;
  if (key < list[mid])
    return binarySearch(list, key, low, mid - 1);
  else if (key == list[mid])
    return mid;
  else
    return binarySearch(list, key, mid + 1, high);
}

int binarySearch(const int list[], int key, int size)
{
  int low = 0;
  int high = size - 1;
  return binarySearch(list, key, low, high);
}

int main()
{
  int list[] = {2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79};
  int i = binarySearch(list, 2, 13); // Returns 0
  int j = binarySearch(list, 11, 13); // Returns 4
  int k = binarySearch(list, 12, 13); // Returns –1

  cout << "binarySearch(list, 2, 13) returns " << i << endl;
  cout << "binarySearch(list, 11, 13) returns " << j << endl;
  cout << "binarySearch(list, 12, 13) returns " << k << endl;

  return 0;
}
```
```
command>cl RecursiveBinarySearch.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>RecursiveBinarySearch 
binarySearch(list, 2, 13) returns 0
binarySearch(list, 11, 13) returns 4
binarySearch(list, 12, 13) returns -6

command>
```

The `binarySearch` [[function]] in line 18 finds a key in the whole list. The helper `binarySearch` [[function]] in line 4 finds a key in the list with index from `low` to `high`.

The `binarySearch` [[function]] in line 18 passes the initial array with `low = 0` and `high = size - 1` to the helper `binarySearch` [[function]]. The helper [[function]] is invoked recursively to find the key in an ever-shrinking subarray.
## Self-Check
### Show the call stack for `isPalindrome("abcba")` using the functions defined in __LiveExamples 17.3 and 17.4__, respectively.
Omitted.
### Show the call stack for `selectionSort("abcba")` using the [[function]] defined in __LiveExample 17.5__.
Omitted.
### What is a [[recursive helper function]]?
An overloaded [[function]] with additional parameters.
# References
