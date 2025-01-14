# Summary

# Learning Objectives

# Related
Prev - [[COSC 13.2 Text Input and Output]]

Next - [[COSC 13.2.2 Reading Data from a file]]
# Content

## Writing Data to a File

The `ofstream` class can be used to write primitive data-type values, arrays, strings, and objects to a text file. **CodeAnimation 13.1** demonstrates how to write data. The program creates an instance of `ofstream` and writes two lines to the file **scores.txt**. Each line consists of first name (a string), middle name initial (a character), last name (a string), and score (an integer). 

**CodeAnimation 13.1 TextFileOutput.cp**
```CPP
  1  #include <iostream>
  2  #include <fstream>
  3  using namespace std;
  4  
  5  int main()
  6  {
  7    ofstream output;
  8  
  9    // Create a file
 10    output.open("scores.txt");
 11  
 12    // Write two lines
 13    output << "John" << " " << "T" << " " << "Smith" 
 14      << " " << 90 << endl;
 15    output << "Eric" << " " << "K" << " " << "Jones" 
 16      << " " << 85 << endl;
 17  
 18    output.close();
 19  
 20    cout << "Done" << endl;
 21  
 22    return 0;
 23  }
```

**LiveExample 13.1 TextFileOutput.cpp**
```CPP
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream output;

  // Create and open a file named scores.txt
  output.open("scores.txt");

  // Write two lines
  output << "John" << " " << "T" << " " << "Smith" 
    << " " << 90 << endl;
  output << "Eric" << " " << "K" << " " << "Jones" 
    << " " << 85 << endl;

  output.close(); // Important! Close output

  cout << "Done" << endl;

  return 0; // You can view the code animation from
} // https://liangcpp.pearsoncmg.com/codeanimation/TextFileOutput.html
```
```
command>cl TextFileOutput.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TextFileOutput 
Done

command>
```

Since the `ofstream` class is defined in the `fstream` header file, line 2 includes this header file.

Line 7 creates an object, `output`, from the `ofstream` class using its no-arg constructor.

Line 10 opens a file named scores.txt for the `output` object. If the file does not exist, a new file is created. If the file already exists, its contents are destroyed without warning.

You can write data to the `output` object using the stream insertion operator (`<<`) in the same way that you send data to the `cout` object. Lines 13–16 write strings and numeric values to `output`, as shown in **Figure 13.1**.

![[Pasted image 20241006210107.png]]

The `close()` function (line 18) must be used to close the stream for the object. If this function is not invoked, the data may not be saved properly in the file.

You may open an output stream using the following constructor:

```cpp
ofstream output("scores.txt"); 
```

This statement is equivalent to

```cpp
ofstream output; 
output.open("scores.txt"); 
```

>[!warning] Caution

If a file already exists, its contents will be destroyed without warning.

>[!Tip]
When the program writes data to a file, it first stores the data temporarily to a buffer in the memory. When the buffer is full, the data are automatically saved to the file on the disk. Once you close the file, all the data left in the buffer are saved to the file on the disk. Therefore, you must close the file to ensure that all data are saved to the file.

>[!warning] Caution
The directory separator for Windows is a backslash (`\`). The backslash is a special escape character and should be written as `\\` in a string literal (see **Table 4.5**). For example,

```cpp
output.open("c:\\example\\scores.txt"); 
```

>[!Note]
An [[absolute file name]] is platform dependent. It is better to use a _[[relative file name]]_ without drive letters. If you use an IDE to run C++, the directory of the [[relative file name]] can be specified in the IDE. For example, the default directory for data files is the same directory with the source code in Visual C++.

## Self-Check

### How do you declare and open a file for output?

Use `ofstream` class to create an object for text output, then use the open function to open the file.

# References