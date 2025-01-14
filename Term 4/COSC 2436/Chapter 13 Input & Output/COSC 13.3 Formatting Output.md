# Summary

# Learning Objectives

# Related
Prev - [[COSC 13.2.5 Letting the User Enter a Filename]]

Next - [[COSC 13.4 Functions - getline, get, and put]]
# Content

## Key Point

The stream manipulators can be used to format console output as well as file output.

You have used the stream manipulators to format output to the console in **Section 4.10**, “Formatting Console Output.” You can use the same stream manipulators to format output to a file. **LiveExample 13.5** gives an example that formats the student records to the file named **formattedscores.txt**.

**LiveExample 13.5 WriteFormattedData.cpp**
```C++
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
  ofstream output;

  // Create a file
  output.open("formattedscores.txt");

  // Write two lines
  output << setw(6) << "John" << setw(2) << "T"
    << setw(6) << "Smith" << " " << setw(4) << 90 << endl;
  output << setw(6) << "Eric" << setw(2) << "K"
    << setw(6) << "Jones" << " " << setw(4) << 85;

  output.close();

  cout << "Done" << endl;

  return 0;
}
```

```
command>cl WriteFormattedData.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>WriteFormattedData 
Done

command>
```

The contents of the file are shown below:
![[Pasted image 20241006211706.png]]

## Self-Check

### Can you use the stream manipulators to format text output?

Yes.

# References
