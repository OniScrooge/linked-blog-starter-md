# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.11 Converting numbers to strings using stringstream]]

Next - [[COSC Chapter 10.2.13 Case Study - Replacing Strings]]
# Content
Often you need to extract the words from a string. Assume that the words are separated by whitespaces. You can use the `stringstream`​ ​class discussed in the preceding section to accomplish this task. **LiveExample** **10.1** gives an example that extracts the words from a string and displays the words in separate lines.

## **LiveExample 10.1 ExtractWords.cpp**
```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
  string text("Programming is fun");
  stringstream ss(text);

  cout << "The words in the text are " << endl;
  string word;
  while (!ss.eof())
  {
    ss >> word;
    cout << word << endl;
  } 

  return 0;
}
```
```
command>cl ExtractWords.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ExtractWords 
The words in the text are 
Programming
is
fun

command>
```

The program creates a `stringstream` object for the text string (line 9) and this object can be used just like an input stream for reading data from the console. It sends data from the string stream to a string object `word` (line 15). The `eof()` function in the `stringstream` class returns true when all items in string stream are read (line 13).
## Self-Check
### How do you read a word from a `stringstream`? How do you test the end of a `stringstream`?
The words in a stringstream are separated by whitespace characters. To read a word from a stringstream, use the >> operator. To test the end of a stringstream, invoke the eof() function from the stringstream.
# References
