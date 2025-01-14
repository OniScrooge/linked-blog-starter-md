# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.2 Appending to a String]]

Next - [[COSC Chapter 10.2.4 Functions at, clear, erase, empty, back, and front]]
# Content
You can use several overloaded functions to assign new contents to a string, as shown in **Figure 10.2**.

## Figure 10.2
![[Pasted image 20241207150657.png]]

For example:
```cpp
string s1("Welcome"); 
s1.assign("Dallas"); // Assigns "Dallas" to s1 
cout << s1 << endl; // s1 now becomes Dallas 
 
string s2("Welcome"); 
s2.assign("Dallas, Texas", 0, 5); // Assigns "Dalla" to s2 
cout << s2 << endl; // s2 now becomes Dalla 
 
string s3("Welcome"); 
s3.assign("Dallas, Texas", 5); // Assigns "Dalla" to s3 
cout << s3 << endl; // s3 now becomes Dalla 
 
string s4("Welcome"); 
s4.assign(4, 'G'); // Assigns "GGGG" to s4 
cout << s4 << endl; // s4 now becomes GGGG 
```

>[!Note]
The `assign(char[], n)` and `assign(str, index)` behaves differently. The former assigns the first `n` characters in the array to the calling string and the latter assigns the substring from the specified `index` in `str` to the calling string.

## Self-Check
### What are the results of the following expressions?
Suppose that s1 and s2 are two strings, given as follows:
`string s1("I have a dream");`
`string s2("Computer Programming");`

Assume that each expression is independent.

(1) s1.assign(3, 'N') 
(2) s1.assign(s2, 9, 7) 
(3) s1.assign("NEWNEW", 3)
(4) s1.assign(3, 'N')

#### Answer
(1) NNN              
(2) Program              
(3) NEW              
(4) NNN
# References
