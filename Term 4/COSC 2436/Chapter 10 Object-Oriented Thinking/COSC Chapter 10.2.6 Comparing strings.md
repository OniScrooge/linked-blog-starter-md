# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.5 Functions length, size, capacity, and c_str]]

Next - [[COSC Chapter 10.2.7 Obtaining substrings]]
# Content
Often, in a program, you need to compare the contents of two strings. You can use the `compare` function. This function returns an `int` value greater than `0`, `0`, or less than `0` if this string is greater than, equal to, or less than the other string, as shown in **Figure 10.5**.

## Figure 10.5
![[Pasted image 20241207151337.png]]

For example:
```cpp
string s1("Welcome"); 
string s2("Welcomg"); 
cout << s1.compare(s2) << endl; // Returns -1 
cout << s2.compare(s1) << endl; // Returns 1 
cout << s1.compare("Welcome") << endl; // Returns 0 
```

## Self-Check
Suppose that s1 and s2 are two strings, given as follows:
`string s1("I have a dream");`
`string s2("Computer Programming");`

Assume that each expression is independent.
(1) s1.compare(s2) 
(2) s1.compare(0, 10, s2)

#### Answer
(1)  1              
(2)  1
# References
