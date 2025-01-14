# Summary

# Learning Objectives

# Related
Prev - [[COSC 13.2.3 Testing File Existence]]

Next - [[COSC 13.2.5 Letting the User Enter a Filename]]
# Content

**LiveExample 13.2** reads two lines from the data file. If you don’t know how many lines are in the file and want to read them all, how do you recognize the end of file? You can invoke the `eof()` function on the input object to detect it, as discussed in **LiveExample 5.6**, ReadAllData.cpp. However, this program will not work if there are extra blank characters after the last number. To understand this, let us look at the file that contains the numbers shown in **Figure 13.3**. Note there is an extra blank character after the last number.

![[Pasted image 20241006211123.png]]

>[!Note]
A line ends with an end-of-line character. The Windows, Mac, and UNIX use \r\n , \r, and \n respectively to designate the end of a line in a text file. However, there is no end-of-file character to designate the end of a file.

If you use the following code to read all data and add the total, the last number will be added twice.

```cpp
ifstream input("score.txt"); 
double sum = 0; 
double number; 
while (!input.eof()) // Continue if not end of file 
{ 
  input >> number; // Read data 
  cout << number << " "; // Display data 
  sum += number; 
} 
```

The reason for this is that when the last number `85.6` is read, the file system does not know it is the last number because there are blank characters after the last number. So, the `eof()` function returns `false`. When the program reads the number again, the `eof()` function returns `true`, but the variable `number` is not changed, because nothing is read from the file. The variable `number` still contains the value `85.6`, which is added again to `sum`.

There are two ways to fix this problem. One is to check the `eof()` function right after reading a number. If the `eof()` function returns `true`, exit the loop, as shown in the following code:

```cpp
ifstream input("score.txt"); 
double sum = 0; 
double number; 
while (!input.eof()) // Continue if not end of file 
{ 
  input >> number; // Read data 
  if (input.eof()) break; 
  cout << number << " "; // Display data 
  sum += number; 
} 
```

The other way to fix this problem is to write the code like this:

```cpp
while (input >> number) // Continue to read data until it fails 
{ 
  cout << number << " "; // Display data 
  sum += number; 
} 
```

The statement `input >>` `number` is actually to invoke an operator function. Operator functions will be introduced in **Chapter 14**. This function returns an object if a number is read; otherwise it returns `NULL`. `NULL` is a constant value `0`. C++ automatically casts it to a `bool` value `false` when it is used as a condition in a loop statement or a selection statement. If no number is read from the input stream, `input >> number` returns `NULL` and the loop terminates.

**LiveExample 13.3** gives a complete program that reads numbers from the file and displays their sum.
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // Open a file
  ifstream input("score.txt");

  if (input.fail())
  {
    cout << "File does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  double sum = 0;
  double number;
  while (input >> number) // Read data to the end of file
  {
    cout << number << " "; // Display data
    sum += number;
  }

  input.close();

  cout << "\nTotal is " << sum << endl;

  return 0;
}
```

```
command>cl TestEndOfFile.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestEndOfFile 
1 2 3
Total is 6

command>
```

The program reads data in a loop (lines 19–23). Each iteration of the loop reads one number and adds it to `sum`. The loop terminates when the input reaches the end of file.

If you replace `(input >> number)` with `(cin >> number)` in line 19, the input will be entered from the console. The input ends when CTRL + D is pressed.

## Self-Check

### How do you detect whether the end of file is reached?

Invoking the eof() function on the stream object. If true, it means it is the end of file.

# References
