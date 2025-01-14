# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.11.1 The Boyer-Moore Algorithm]]

Next - [[COSC Chapter Summary 18]]
# Content

## Key Insight

The Knuth-Morris-Pratt (KMP) algorithm is efficient. It achieves `O(m + n)` in the worst case. It is optimal because every character in the text and in the pattern must be checked at least once in the worst case. In the [[brute force]] or the Boyer-Moore algorithm, once a mismatch is found, the algorithm restarts to search for the next possible match by shifting the pattern one position to the right for the [[brute force]] algorithm and possibly multiple positions to the right for the Boyer-Moore algorithm. In doing so, the successful match of characters prior to the mismatch is ignored. The KMP algorithm takes consideration of the successful matches to find the maximum number of positions to shift in the pattern before continuing next search.

To find the maximum number of positions to shift in the pattern, we first define a _failure [[function]]_ `fail(k)` as the length of the longest prefix of pattern that is a suffix of `pattern[0 .. k]`. The failure [[function]] can be precomputed for a given pattern. The failure [[function]] is actually an array with m elements. Suppose the pattern is `ABCABCDABC`. The failure functions for this pattern are shown in **Figure 18.15**:

>[!info] Figure 18.15
>![[Pasted image 20241022134627.png]]

For example, `fail[5]` is `3`, because `ABC` is the longest prefix that is suffix for `ABCABC`. `fail[7]` is `1`, because `A` is the longest prefix that is suffix for `ABCABCDA`. When comparing the text and the pattern, once a mismatch is found at index `k` in the pattern, you can shift the pattern to align the pattern at index `fail[k-1]` with the text, as shown in **Figure 18.16**.

>[!info] Figure 18.16
>![[Pasted image 20241022134728.png]]
>![[Pasted image 20241022134740.png]]

The KMP algorithm is given in **Listing 18.8.** 

## Listing 18.8 KMP String Matching Algorithm

1. Step 1: First we precompute the failure functions. Now start with `i = 0` and `k = 0`.
2. Step 2: Compare `text[i]` with `pattern[k]`. Consider two cases:
    1. Case 1 `text[i]` is equal to `pattern[k]`: if `k` is `m-1`, a matching is found and return `i – m + 1`. Otherwise, increase `i` and `k` by `1`.
    2. Case 2 `text[i]` is not equal to `pattern[k]`: if `k > 0`, shift the longest prefix that matches the suffix in `pattern[k - 1]` so that the last character in the prefix is aligned with `text[i – 1]` by setting `k = fail[k - 1]`, else increase `i` by `1`.
3. Step 3: If `i < n`, repeat Step `2`.

Now let us turn the attention to computing the failure functions. This can be done by comparing pattern with itself as follows:
1. Step 1: The failure [[function]] is an array with m elements. Initially, set all the elements to `0`. We start with `i = 1` and `k = 0`.
2. Step 2: Compare `pattern[i]` with `pattern[k]`. Consider two cases:
    1. Case 1 `pattern[i]` == `pattern[k]`: `fail[i] = k + 1`. Increase `i` and `k` by `1`.
    2. Case 2 `pattern[i]` != `pattern[k]`: if `k > 0`, set `k = fail[k - 1]`, else increase `i` by `1`.
3. Step 3: If `i < m`, repeat Step 2. Note that k indicates the length of the longest prefix in `pattern[0..i-1]` if `pattern[i] == pattern[k]`.

This is a sophisticated algorithm. The following animation shows how the KMP algorithm works.

## KMP String Matching Animation
![[Pasted image 20241022134938.png]]
![[Pasted image 20241022134952.png]]

## KMP Failure [[Function]] Animation
![[Pasted image 20241022135031.png]]
![[Pasted image 20241022135054.png]]

## **LiveExample 18.11**
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Compute failure function
vector<int> getFailure(string pattern) 
{
  vector<int> fail(pattern.length());
  int i = 1;
  int k = 0;
  while (i < pattern.length()) 
  {
    if (pattern[i] == pattern[k])
    {
      fail[i] = k + 1;
      i++;
      k++;
    }
    else if (k > 0) 
      k = fail[k - 1];
    else
      i++;
  }

  return fail;
}

// Return the index of the first match. -1 otherwise.
int match(string text, string pattern) 
{
  vector<int> fail = getFailure(pattern);
  int i = 0; // Index on text
  int k = 0; // Index on pattern
  while (i < text.length()) 
  {
    if (text[i] == pattern[k])
    {
      if (k == pattern.length() - 1)
      {
        return i - pattern.length() + 1; // pattern matched
      }
      i++; // Compare the next pair of characters
      k++;
    }
    else
    {
      if (k > 0) 
        k = fail[k - 1]; // Matching prefix position
      else 
        i++; // No prefix
    }
  }

  return -1;
}

int main() 
{
  cout << "Enter a string text: ";
  string text;
  getline(cin, text);
  cout << "Enter a string pattern: ";
  string pattern;
  getline(cin, pattern);

  int index = match(text, pattern);
  if (index >= 0)
    cout << "matched at index " << index << endl;
  else
    cout << "unmatched" <<endl;
}
```
```
command>cl StringMatchKMP.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>StringMatchKMP 
Enter a string text: aaaaaaaaaab
Enter a string pattern: aaab
matched at index 7

command>
```

The `match(text, pattern)` [[function]] (lines 30-56) tests whether `pattern` matches a substring in `text`. `i` indicates the current position in the text, which always moves forward. `k` indicates the current position in the pattern. If `text[i]` == `pattern[k]` (line 37), both `i` and `k` are incremented by `1` (lines 43-44). Otherwise, if `k > 0`, set `fail(k – 1)` to `k` so to slide the pattern to align `pattern[k]` with `text[i]` (line 49), else increase `i` by `1` (line 51). 

The `getFailure(pattern)` [[function]] (lines 7-27) compares `pattern` with `pattern` to obtain the length of the maximum prefix `fail[k]`, which is the suffix in `pattern[0..k]`. It initializes the array `fail` to zeros (line 9) and set `i` and `k` to `1` and `0`, respectively (lines 10-11). i indicates the current position in the first pattern, which always moves forward. ﻿`k` indicates the current maximum length of a possible prefix that is also a suffix in `pattern[0..i]`. If `pattern[i]` == `pattern[k]`, set `fail[i]` to `k + 1` (line 16) and increase both `i` and `k` by `1` (lines 17-18). Otherwise, if `k > 0`, set `k` to `fail[k – 1]` to slide the second pattern to align `pattern[i]` in the first pattern with `pattern[k]` in the second pattern (line 21), else increase `i` by `1` (line 23). 

To analyze the running time, consider three cases: 
1. Case 1: `text[i]` is equal to `pattern[k]`. `i` is moved forward one position.
2. Case 2: `text[i]` is not equal to `pattern[k]` and `k` is `0`. `i` is moved forward one position.
3. Case 3: `text[i]` is not equal to `pattern[k]` and `k > 0`. The pattern is moved at least one position forward.

In any case, either `i` is moved forward one position on the text or the pattern is shifted at least one position to the right. Therefore, the number of iterations in the while loop for the match [[function]] is at most `2n`. Similarly, the number of the iterations in the `getFailure` [[function]] is at most 2m. Therefore the running time of the KMP algorithm is $﻿O(n+m)$.

## Self-Check

### Compute the failure functions for the pattern ABCBABCBDA.

`[0, 0, 0, 0, 1, 2, 3, 4, 0, 1]`

# References
