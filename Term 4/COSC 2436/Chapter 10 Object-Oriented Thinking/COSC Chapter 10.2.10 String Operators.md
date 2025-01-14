# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.9 Inserting and replacing strings]]

Next - [[COSC Chapter 10.2.11 Converting numbers to strings using stringstream]]
# Content
C++ supports operators to simplify string operations. **Table 10.1** lists the string operators.

## Table 10.1 **String Operato​rs**

|**Operator**|**Description**|
|---|---|
|`[]`|Accesses characters using the array subscript operator.|
|`=`|Copies the contents of one string to the other.|
|`+`|Concatenates two strings into a new string.|
|`+=`|Appends the contents of one string to the other.|
|`<<`|Inserts a string to a stream|
|`>>`|Extracts characters from a stream to a string delimited by a whitespace or the null terminator character.|
|`==, !=, <, <=, >, >=`|Six relational operators for comparing strings.|

Here are the examples to use these operators:
```cpp
string s1 = "ABC"; // The = operator 
string s2 = s1; // The = operator 
  
for (unsigned i = s2.size() – 1; i >= 0; i--) 
  cout << s2[i]; // The [] operator 
  
string s3 = s1 + "DEFG"; // The + operator 
cout << s3 << endl; // s3 becomes ABCDEFG 
  
s1 += "ABC"; 
cout << s1 << endl; // s1 becomes ABCABC 
  
s1 = "ABC"; 
s2 = "ABE"; 
cout << (s1 == s2) << endl; // Displays 0 (means false) 
cout << (s1 != s2) << endl; // Displays 1 (means true) 
cout << (s1 > s2) << endl; // Displays 0 (means false) 
cout << (s1 >= s2) << endl; // Displays 0 (means false) 
cout << (s1 < s2) << endl; // Displays 1 (means true) 
cout << (s1 <= s2) << endl; // Displays 1 (means true) 
```

## Self-Check
### What are the results of the following expressions?
Suppose that s1 and s2 are given as follows:
`string s1("I have a dream");`
`string s2("Computer Programming");`

Assume that each expression is independent.
(1) s1[0]
(2) s1 = s2
(3) s1 = "C++ " + s2 
(4) s2 += "C++ " 
(5) s1 > s2 
(6) s1 >= s2 
(7) s1 < s2
(8) s1 <= s2
(9) s1 == s2
(10) s1 != s2

#### Answer
(1) I
(2) s1 becomes "Computing Programming"
(3) s1 becomes "C++ Computer Programming"
(4) Computer ProgrammingC++
(5) true
(6) true
(7) false
(8) false
(9) false
(10) true
# References
