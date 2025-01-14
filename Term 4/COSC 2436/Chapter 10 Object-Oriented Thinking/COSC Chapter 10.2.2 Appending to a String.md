# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.1 Constructing a String]]

Next - [[COSC Chapter 10.2.3 Assigning a string]]
# Content
You can use several overloaded functions to add new contents to a string, as shown in **Figure 10.1**.

## Figure 10.1
![[Pasted image 20241207150458.png]]

For example:
```cpp
string s1("Welcome"); 
s1.append(" to C++"); // Appends " to C++" to s1 
cout << s1 << endl; // s1 now becomes Welcome to C++ 
 
string s2("Welcome"); 
s2.append(" to C and C++", 0, 5); // Appends " to C" to s2 
cout << s2 << endl; // s2 now becomes Welcome to C 
 
string s3("Welcome"); 
s3.append(" to C and C++", 5); // Appends " to C" to s3 
cout << s3 << endl; // s3 now becomes Welcome to C 
 
string s4("Welcome"); 
s4.append(4, 'G'); // Appends "GGGG" to s4 
cout << s4 << endl; // s4 now becomes WelcomeGGGG 
```

## Self-Check
### What are the results of the following expressions?
Suppose that s1 and s2 are two strings, given as follows:

string s1("I have a dream");
string s2("Computer Programming");

Assume that each expression is independent.

(1) s1.append(s2)
(2) s1.append(s2, 9, 7)
(3) s1.append("NEW", 3) 
(4) s1.append(3, 'N') 

#### Answer
(1) I have a dreamComputer Programming 	
(2) I have a dreamProgram      
(3) I have a dreamNEW              
(4) I have a dreamNNN
# References
