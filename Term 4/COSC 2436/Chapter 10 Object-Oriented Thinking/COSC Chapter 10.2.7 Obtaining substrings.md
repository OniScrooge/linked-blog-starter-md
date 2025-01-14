# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.6 Comparing strings]]

Next - [[COSC Chapter 10.2.8 Searching in a string]]
# Content
You can obtain a single character from a string using the `at`​ ​function. You can also obtain a substring from a string using the `substr`​ ​function, as shown in **Figure 10.6**.

## Figure 10.6
![[Pasted image 20241207151518.png]]

For example:
```cpp
string s1("Welcome"); 
cout << s1.substr(0, 1) << endl; // Returns W 
cout << s1.substr(3) << endl; // Returns come 
cout << s1.substr(3, 3) << endl; // Returns com 
```

## Self-Check
### What are the results of the following expressions?
Suppose that s1 is a string, given as follows:
`string s1("I have a dream");`

Assume that each expression is independent.
(1) s1.substr(4, 8)
(2) s1.substr(4)

#### Answer
(1)  ve a dre
(2)  ve a dream
# References
