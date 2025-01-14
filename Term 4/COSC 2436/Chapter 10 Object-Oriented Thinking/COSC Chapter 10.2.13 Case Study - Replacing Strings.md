# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.12 Splitting strings]]

Next - [[COSC Chapter 10.3 Passing objects to functions]]
# Content
In this case study, you will write the following function that replaces the occurrence of a substring `oldSubStr` with a new substring `newSubStr` in the string `s`.

```cpp
bool replaceString(string& s, const string& oldSubStr, 
  const string& newSubStr) 
```

The function returns `true` if string `s` is changed, and otherwise, it returns `false`.

**LiveExample 10.2** gives the program.

## **LiveExample 10.2 ReplaceString.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

// Replace oldSubStr in s with newSubStr
bool replaceString(string& s, const string& oldSubStr, 
  const string& newSubStr);

int main()
{
  // Prompt the user to enter s, oldSubStr, and newSubStr
  cout << "Enter string s, oldSubStr, and newSubStr: ";
  string s, oldSubStr, newSubStr;
  cin >> s >> oldSubStr >> newSubStr;

  bool isReplaced = replaceString(s, oldSubStr, newSubStr);

  if (isReplaced)
    cout << "The replaced string is " << s << endl;
  else
    cout << "No matches" << endl;

  return 0;
}

bool replaceString(string& s, const string& oldSubStr, 
  const string& newSubStr)
{
  bool isReplaced = false;
  int currentPosition = 0;
  while (currentPosition < s.length())
  {
    int position = s.find(oldSubStr, currentPosition);
    if (position == string::npos) // Mo more matches
      return isReplaced; 
    else
    {
      s.replace(position, oldSubStr.length(), newSubStr);
      currentPosition = position + newSubStr.length();
      isReplaced = true; // At least one match
    }
  } 

  return isReplaced;
}
```
```
command>cl ReplaceString.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ReplaceString 
Enter string s, oldSubStr, and newSubStr: abcdabab ab AAA
The replaced string is AAAcdAAAAAA

command>
```

The program prompts the user to enter a string, an old substring, and a new substring (line 14). The program invokes the `replaceString` function to replace all the occurrence of the old substring with the new substring (line 16) and displays a message indicating whether the string has been replaced (lines 18–21).

The `replaceString` function searches for `oldSubSt`r in string `s` starting from `currentPosition` starting from `0` (line 30). The `find` function in the string class is used to find a substring in a string (line 33). It returns `string::npos` if it is not found. In this case, the search ends and the function returns `isReplaced` (line 35). `isReplaced` is a​ ​`bool`​ ​variable and initially set to `false` (line 29). Whenever a match for a substring is found, it is set to `true` (line 40).

The function repeatedly finds a substring and replaces it with a new substring using the replace function (line 38) and resets the current search position (line 39) to look for a new match in the rest of the string. Advanced readers may use regular expressions to search, replace, and split strings in **Appendix H**.

## Self-Check
### If the `replaceString` function is returned from line 44 in __LiveExample 10.2__, is the returned value always false?
No. it may be true or false.
# References
