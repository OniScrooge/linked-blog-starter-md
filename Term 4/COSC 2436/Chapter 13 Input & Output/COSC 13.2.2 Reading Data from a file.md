# Summary

# Learning Objectives

# Related
Prev - [[COSC 13.2.1 Writing data to a File]]

Next - [[COSC 13.2.3 Testing File Existence]]
# Content

## Key Point
The `ifstream` class can be used to read data from a text file. **CodeAnimation 13.2** demonstrates how to read data. The program creates an instance of `ifstream` and reads data from the file scores.txt, which was created in the preceding example.

## **CodeAnimation 13.2 TextFileInput.html**
```CPP
  1  #include <iostream>
  2  #include <fstream>
  3  #include <string>
  4  using namespace std;
  5  
  6  int main()
  7  {
  8    ifstream input("scores.txt");
  9  
 10    // Read data
 11    string firstName;
 12    char mi;
 13    string lastName;
 14    int score;
 15    input >> firstName >> mi >> lastName >> score;
 16    cout << firstName << " " << mi << " " << lastName << " "
 17      << score << endl;
 18  
 19    input >> firstName >> mi >> lastName >> score;
 20    cout << firstName << " " << mi << " " << lastName << " "
 21      << score << endl;
 22  
 23    input.close();
 24  
 25    cout << "Done" << endl;
 26  
 27    return 0;
 28  }
```

## **LiveExample 13.2 TextFileInput.cpp**
```CPP
`#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream input("scores.txt"); // Open file named scores.txt

  // Read data
  string firstName;
  char mi;
  string lastName;
  int score;
  input >> firstName >> mi >> lastName >> score;
  cout << firstName << " " << mi << " " << lastName << " "
    << score << endl;

  input >> firstName >> mi >> lastName >> score;
  cout << firstName << " " << mi << " " << lastName << " "
    << score << endl;

  input.close();

  cout << "Done" << endl;

  return 0; // You can view the code animation from
} // https://liangcpp.pearsoncmg.com/codeanimation/TextFileInput.html`
```
```
command>cl TextFileInput.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TextFileInput 
John T Smith 90Eric K Jones 85
Done

command>
```

Since the `ifstream` class is defined in the `fstream` header file, line 2 includes this header file.

Line 8 creates an object, `input`, from the `ifstream` class for file **scores.txt**.

You can read data from the `input` object using the stream extraction operator (`>>`) in the same way that you read data from the **`cin`** o​bject. Lines 15 and 19​ read strings and numeric values from the input file, as shown in **Figure 13.2**.
![[Pasted image 20241006210733.png]]

The `close()` function (line 23) is used to close the stream for the object. It is not necessary to close the input file, but doing so is a good practice in order to release the resources occupied by the file.

You may open an input stream using the following constructor:

```cpp
ifstream input("scores.txt"); 
```

This statement is equivalent to

```cpp
ifstream input; 
input.open("scores.txt"); 
```

>[!warning] Caution
To read data correctly, you need to know exactly how data are stored. For example, the program in **LiveExample** **13.2** would not work if the file contained score as a `double` value with a decimal point.

## Self-Check

### How do you declare and open a file for input?

Use `ifstream` class to create an object for text output, then use the open function to open the file.

### Why should you always close a file after it is processed?

Data may not be saved properly if a file is not closed.

# References
