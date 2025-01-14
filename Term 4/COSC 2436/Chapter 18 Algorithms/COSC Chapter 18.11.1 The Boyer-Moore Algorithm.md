# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.11 String Matching]]

Next - [[COSC Chapter 18.11.2 The Knuth-Morris-Pratt Algorithm]]
# Content

The [[brute force]] algorithm searches for a match of the pattern in the text by examining all alignments. This is not necessary. The Boyer-Moore algorithm finds a matching by comparing the pattern with a substring in the text from right to left. If a character in the text does not match the one in the pattern and this character is not in the remaining part of the pattern, you can slide the pattern all the way passing this character. This can be best illustrated using the following animation.

## Boyer-Moore String Matching Animation
![[Pasted image 20241022134034.png]]
![[Pasted image 20241022134052.png]]

The Boyer-Moore algorithm is given in **Listing 18.7**.

## Listing 18.7 Boyer-Moore String Matching Algorithm

```
i = m – 1;
while i <= n – 1  Compare pattern with text[i – (m – 1) .. i]   from right to left one by one, as shown in Figure 18.11. 
If they all match, done. Otherwise, let text[k] be the first one  that does not match the corresponding character in pattern.   Consider two cases:  Case 1: If text[k] is not in the remaining pattern, slide the pattern   passing text[k], as shown in Figure 18.12. Set i = k + m;  Case 2: If text[k] is in pattern, find the last character, say   pattern[j] in pattern that matches text[k] and slide the pattern   right to align pattern[j] with text[k], as shown in Figure 18.13.   Set i = k + m – j - 1.
```

>[!info] Figure 18.11
>![[Pasted image 20241022134158.png]]

>[!info] Figure 18.12
>![[Pasted image 20241022134221.png]]
>![[Pasted image 20241022134232.png]]

>[!info] Figure 18.13
>![[Pasted image 20241022134256.png]]
>![[Pasted image 20241022134307.png]]

**LiveExample 18.10** gives an implementation for the Boyer-Moore algorithm.

## **LiveExample 18.10 StringMatchBoyerMoore.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

// Return the index of the last element in pattern[0 .. j] 
// that matches ch. -1 otherwise.
int findLastIndex(char ch, int j, string pattern) 
{
  for (int k = j; k >= 0; k--) 
  {
    if (ch == pattern[k]) 
      return k;
  }

  return -1;
}

// Return the index of the first match. -1 otherwise.
int match(string text, string pattern)
{
  int i = pattern.length() - 1;
  while (i < text.length()) 
  {
    int k = i;
    int j = pattern.length() - 1;
    while (j >= 0) {
      if (text[k] == pattern[j]) 
      {
        k--; j--;
      }
      else {
        break;
      }
    }

    if (j < 0)
      return i - pattern.length() + 1; // A match found

    int index = findLastIndex(text[k], j - 1, pattern);
    if (index >= 0) // text[k] is in the remaining part of the pattern
      i = k + pattern.length() - 1 - index;
    else // text[k] is not in the remaining part of the pattern
      i = k + pattern.length();
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
command>cl StringMatchBoyerMoore.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>StringMatchBoyerMoore 
Enter a string text: aaaaaaaaaab
Enter a string pattern: aaab
matched at index 7

command>
```

The `match(text, pattern)` [[function]] (lines 19-47) tests whether `pattern` matches a substring in `text. i` indicates the last index of a substring. It starts with `i = pattern.length() – 1` (line 21) and compares `text[i]` with `pattern[j]`, `text[i-1]` with `pattern[j-1]`, and so on backward (lines 26-34). If `j < 0`, a match is found (lines 36-37). Otherwise, find the index of the last matching element for `text[k]` in `pattern[0 .. j-1]` using the `findLastIndex` [[function]]. If `index >= 0`, set `k + m – 1 – index` (line 41), where `m` is `pattern.length()`. Otherwise, set `k + m` to `i` (line 43).

In the worst case, the Boyer-Moore algorithm takes _O(nm)_ time. An example for the worst case is shown in **Figure 18.14**.

>[!info] Figure 18.14
>![[Pasted image 20241022134419.png]]

However, on the average time, the Boyer-Moore algorithm is efficient because the algorithm is often able to skip a large portion of text. There are several variations of the Boyer-Moore algorithm. We presented a simplified version in this section.

## Self-Check

### Give examples that the Boyer-Moore algorithm takes nm times and n times of comparisons respectively.

Text AAAAAAAAAAAAAAAA and pattern BAAAAAAAAAAAAA would result in $n*m$ times of comparisons. If text and pattern have no common characters, it would takes _n_ times of comparisons.


# References
