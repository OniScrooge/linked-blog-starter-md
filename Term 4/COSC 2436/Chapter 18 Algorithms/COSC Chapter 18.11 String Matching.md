# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 18.10 Case Study - Finding a Convex Hull]]

Next - [[COSC Chapter 18.11.1 The Boyer-Moore Algorithm]]
# Content

## Key Point

This section presents the [[brute force]], Boyer-Moore, and Knuth-Morris-Pratt algorithms for string matching.

String matching is to find a match for a substring in a string. The string is commonly known as the _text_ and the substring is called a _pattern_. String matching is a common task in computer programming. The `string` class has the `find(pattern)` [[function]] to search for a pattern. A lot of [[research]] has been done to find efficient algorithms for string matching. This section presents three algorithms: the [[brute force]] algorithm, the Boyer-Moore algorithm, and the Knuth-Morris-Pratt algorithm.

The [[brute force]] algorithm is simply to compare the pattern with every possible substring in the text. Assume the length of text and pattern are `n` and `m`, respectively. The algorithm is given in **Listing 18.6**.

## Listing 18.6 Brute-Force String Matching Algorithm

```cpp
for i from 0 to n – m  
{ 
  test if pattern matches text[i .. i + m] 
} 
```

Here `text[i .. j]` represents a substring in text from index i to index j. Below is an animation for the [[brute force]] algorithm:

## Brute-Force String Matching Animation
![[Pasted image 20241022133649.png]]
![[Pasted image 20241022133702.png]]

**LiveExample 18.9** gives an implementation for the brute-force algorithm.

## **LiveExample 18.9 StringMatch.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

// Test if pattern matches text starting at index i
bool isMatched(int i, string text, string pattern)
{
  for (unsigned k = 0; k < pattern.length(); k++)
  {
    if (pattern[k] != text[i + k]) 
      return false;
  }

  return true;
}

// Return the index of the first match. -1 otherwise.
int match(string text, string pattern) 
{
  for (unsigned i = 0; i < text.length() - pattern.length() + 1; i++) 
  {
    if (isMatched(i, text, pattern))
      return i;
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
command>cl StringMatch.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>StringMatch 
Enter a string text: aaaaaaaaaab
Enter a string pattern: aaab
matched at index 7

command>
```

The `match(text, pattern)` [[function]] (lines 18-27) tests whether `pattern` matches a substring in `text`. The `isMatched(i, text, pattern)` [[function]] (lines 6-15) tests whether `pattern` matches `text[i, i + m]` starting at index `i`.

Clearly, the algorithm takes O(nm) time, since testing whether `pattern` matches `text[i, i + m]` takes O(m) time.

## Self-Check

### Give examples that the [[brute force]] algorithm takes nm times and n times of comparisons respectively.

Text AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB and pattern AAAAAAAAB would result in $n*m$ times of comparisons. If text and pattern have no common characters, it would takes _n_ times of comparisons.

# References
