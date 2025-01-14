# Summary

# Learning Objectives

# Related
Prev - [[COSC 13.2.2 Reading Data from a file]]

Next - [[COSC 13.2.4 Testing End of File]]
# Content

## Key Point

If the file does not exist when reading a file, your program will run and produce incorrect results. Can your program check whether a file exists? Yes. You can invoke the `fail()` function immediately after invoking the `open` function. If `fail()` returns `true`, it indicates that the file does not exist.

```cpp
​​​​​​​​​​​​​​​​​​​​​​​​​​​​// Open a file​​​​​​​​​​​​​​​​​​​​​​​​​​​​ 
input.open("scores.txt"); 
 
if (input.fail()) 
{ 
  cout << "File does not exist" << endl; 
  cout << "Exit program" << endl; 
 
  return 0; 
} 
```

## Self-Check

### How do you detect whether a file exists?

After opening the file, invoking the `fail()` function. If true, it means file exists.

# References
