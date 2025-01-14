# Summary

# Learning Objectives

# Related

# Content

## Key Point

The `getline` function can be used to read a string that includes whitespace characters and the `get/put` function can be used to read and write a single character. 

There is a problem in reading data using the stream extraction operator (`>>`). Data are delimited by whitespace. What happens if the whitespace characters a​re part of a string? In **Section 4.8.4**, “Reading Strings,” ​you learned how to use the `getline` function to read a string with whitespace. You can use the same function to read strings from a file. Recall that the syntax for the `getline` function is

```cpp
getline(ifstream& input, int string& s, char delimitChar) 
```

The function stops reading characters when the delimiter character or end-of-file mark is encountered. If the delimiter is encountered, it is read but not stored in the array. The third argument `delimitChar` has a default value (`'\n'`). The `getline` function is defined in the `iostream` header file.

Suppose a file named **state.txt** is created that contains the state names delimited by the pound (#) symbol. The following diagram shows the contents in the file:
![[Pasted image 20241006211838.png]]

**LiveExample 13.6** gives a program that reads the states from the file.
```C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  // Open a file
  ifstream input("state.txt");

  if (input.fail())
  {
    cout << "File does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  // Read data
  string city;

  while (!input.eof()) // Continue if not end of file
  {
    getline(input, city, '#'); // Read a city with delimiter #
    cout << city << endl;
  }

  input.close();

  cout << "Done" << endl;

  return 0;
}
```

```
command>cl ReadCity.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ReadCity 
New York
New Mexico
Texas
Indiana
Done

command>
```

Invoking `getline(input, state, '#')` (line 23) reads characters to the array `state` until it encounters the # character or the end-of-file.

Two other useful functions are `get` and `put`. You can invoke the `get` function on an input object to read a character and invoke the `put` function on an output object to write a character.

The `get` function has two versions:

```cpp
char get() // Return a char 
ifstream* get(char& ch) // Read a character to ch 
```

The first version returns a character from the input. The second version passes a character reference argument, reads a character from the input, and stores it in `ch`. This function also returns the reference to the input object being used.

The header for the `put` function is

```cpp
void put(char ch) 
```

It writes the specified character to the output object.

**LiveExample 13.7** gives an example of using these two functions. The program prompts the user to enter a file and copies it to a new file.
```C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  // Enter a source file
  cout << "Enter a source file name: ";
  string inputFilename;
  cin >> inputFilename;

  // Enter a target file
  cout << "Enter a target file name: ";
  string outputFilename;
  cin >> outputFilename;

  // Create input and output streams
  ifstream input(inputFilename.c_str());
  ofstream output(outputFilename.c_str());

  if (input.fail())
  {
    cout << inputFilename << " does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  char ch = FILL_CODE_OR_CLICK_ANSWER // Read a character
  while (!input.eof()) // Continue if not end of file
  {
    FILL_CODE_OR_CLICK_ANSWER // Write a character
    ch = input.get(); // Read next character
  }

  input.close();
  output.close();

  cout << "\nCopy Done" << endl;

  return 0;
}
```

```
command>cl CopyFile.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>CopyFile 
Enter a source file name: c:\example\CopyFile.cpp 
Enter a target file name: c:\example\temp.txt 
Copy Done

command>
```


mpts the user to enter a file and copies it to a new file.

#### **LiveExample 13.7 CopyFile.cpp**

The program prompts the user to enter a source file name in line 11 and a target file name in line 16. An input object for `inputFilename` is created in line 19 and an output object for `outputFilename` in line 20.

Lines 22–27 check whether the input file exists. Lines 30–34 read characters repeatedly one at a time using the `get` function and write the character to the output file using the `put` function.

Suppose lines 29–34 are replaced by the following code:

```cpp
while (!input.eof()) // Continue if not end of file 
{ 
  output.put(input.get()); 
} 
```

What will happen? If you run the program with this new code, you will see that the new file is one byte larger than the original one. The new file contains an extra garbage character at the end. This is because when the last character is read from the input file using `input.get()`, `input.eof()` is still `false`. Afterward, the program attempts to read another character; `input.eof()` now becomes `true`. However, the extraneous garbage character has already been sent to the output file.

The correct code in **Listing 13.7** reads a character (line 29) and checks `eof()` (line 30). If `eof()` is `true`, the character is not put to `output`; otherwise, it is copied (line 32). This process continues until `eof()` returns `true`.

## Self-Check

### What are the differences between getline and get functions?

`getline` gets a line that ends with the newline character '\n'. get gets a character.

### What function do you use to write a character?

`put`

# References
