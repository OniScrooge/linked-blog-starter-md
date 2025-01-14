# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.7 Bucket Sort and Radix Sort]]

Next - [[COSC Chapter Summary 19]]
# Content
## Key Point

You can sort a large amount data using an [[external sort]].

All the sort algorithms discussed in the preceding sections assume that all the data to be sorted are available at one time in internal memory, such as in an array. To sort data stored in an external file, you must first bring the data to the memory and then sort it internally. However, if the file is too large, all the data in the file cannot be brought to memory at one time. This section discusses how to sort data in a large external file. This is called an [[external sort]].

For simplicity, assume that two million `int` values are stored in a binary file named largedata.dat. This file was created using the program in **LiveExample 19.7**.

#### **LiveExample 19.7 CreateLargeFile.cpp**
```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
  fstream output;
  output.open("largedata.dat", ios::out | ios::binary);

  for (int i = 0; i < 2000000; i++)
  {
    int value = rand();
    output.write(reinterpret_cast<char *>(&value), sizeof(value));
  }

  output.close();
  cout << "File created" << endl;

  fstream input;
  input.open("largedata.dat", ios::in | ios::binary);
  int value;

  cout << "The first 10 numbers in the file are " << endl;
  for (int i = 0; i < 10; i++)
  {
    input.read(reinterpret_cast<char *>(& value), sizeof(value));
    cout << value << " ";
  }

  input.close();

  return 0;
}
```
```
command>cl CreateLargeFile.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>CreateLargeFile 
569193 131317 608695 776266 767910 624915 458599 5010 ... (omitted)

command>
```

A variation of [[merge sort]] can be used to sort this file in two phases:

>[!note] Figure 19.16
>**Phase I:** Repeatedly bring data from the file to an array, sort the array using an internal sorting algorithm, and output the data from the array to a temporary file. This process is shown in **Figure** **19.16**. Ideally, you want to create a large array, but its maximum size depends on how much memory is allocated to the JVM by the operating system. Assume that the maximum array size is 100,000 `int` values. In the temporary file, every 100,000 `int` values are sorted. They are denoted as S1,S2,…, and Sk, where the last segment, Sk, may contain less than 100000 values.
>![[19fig23.png]]
>**Phase II**: Merge a pair of sorted segments (e.g., S1 with S2, S3 with S4,..., and so on) into a larger sorted segment and save the new segment into a new temporary file. Continue the same process until only one sorted segment results. **Figure 19.17** shows how to merge eight segments.
>![[19fig24.png]]

>[!Note]
It is not necessary to merge two successive segments. For example, you can merge S1 with S5, S2 with S6, S3 with S7, and S4 with S8, in the first merge step. This observation is useful in implementing Phase II efficiently.

## 19.8.1 Implementing Phase I

**Listing 19.5** gives the [[function]] that reads each segment of data from a file, sorts the segment, and stores the sorted segments into a new file. The [[function]] returns the number of segments.

### **Listing 19.5 Creating Initial Sorted Segments**

```cpp
    // Sort original file into sorted segments  
    int initializeSegments(int segmentSize, string sourceFile, string f1) 
    { 
      int* list = new int[segmentSize]; 
 
      fstream input; 
      input.open(sourceFile.c_str(), ios::in | ios::binary); 
      fstream output; 
      output.open(f1.c_str(), ios::out | ios::binary); 
    
     int numberOfSegments = 0; 
     while (!input.eof())  
     { 
       int i = 0; 
       for ( ; !input.eof() && i < segmentSize; i++) 
       { 
         input.read(reinterpret_cast<char*> 
           (&list[i]), sizeof(list[i])); 
       } 
    
       if (input.eof()) i--; 
       if (i <= 0) 
         break; 
       else 
         numberOfSegments++; 
    
       // Sort an array list[0..i-1] 
       quickSort(list, i); 
    
       // Write the array to f1.dat 
       for (int j = 0; j < i; j++) 
       { 
         output.write(reinterpret_cast<char*> 
           (&list[j]), sizeof(list[j])); 
       } 
     } 
    
     input.close(); 
     output.close(); 
     delete [] list; 
    
     return numberOfSegments; 
   } 
```

The [[function]] declares an array with the specified segment size in line 4, declares a data input stream for the original file in line 7, and declares a data output stream for a temporary file in line 9.

Lines 15–19 read a segment of data from the file into the array. Line 28 sorts the array. Lines 31–35 write the data in the array to the temporary file.

The number of the segments is returned in line 42. Note that every segment has `segmentSize` number of elements except the last segment, which may have a smaller number of elements.

## 19.8.2 Implementing Phase II

In each merge step, two sorted segments are merged to form a new segment. The size of the new segment is doubled. The number of segments is reduced by half after each merge step. A segment is too large to be brought to an array in memory. To implement a merge step, copy half of the number of segments from the file **f1.dat** to a temporary file **f2.dat**. Then merge the first remaining segment in **f1.dat** with the first segment in **f2.dat** into a temporary file named **f3.dat**, as shown in **Figure 19.18**.

>[!note] Figure 19.18
>![[19fig25.png]]

>[!Note]
**f1.dat** may have one segment more than **f2.dat.** If so, move the last segment into **f3.dat** after the merge.

**Listing 19.6** gives a [[function]] that copies the first half of the segments in f1.dat to f2.dat. **Listing 19.7** gives a [[function]] that merges a pair of segments in f1.dat and f2.dat. **Listing 19.8** gives a [[function]] that merges two segments.

### **Listing 19.6 Copying First Half Segments**
![[Pasted image 20241107115841.png]]

### **Listing 19.7 Merging All Segments**
![[Pasted image 20241107115901.png]]

## 19.8.3 Combining Two Phases

**LiveExample 19.8** gives the complete program for sorting `int` values in largedata.dat and storing the sorted data in sortedfile.dat.

### **LiveExample 19.8 ExternalSort.cpp**
```cpp
#include <iostream>
#include <fstream>
#include "QuickSort.h"
#include <string>
using namespace std;

// Function prototype
void sort(string sourcefile, string targetfile);
int initializeSegments(int segmentSize,
  string sourcefile, string f1);
void mergeTwoSegments(int segmentSize, fstream &f1, fstream &f2,
  fstream &f3);
void merge(int numberOfSegments, int segmentSize,
  string f1, string f2, string f3, string targetfile) ;
void copyHalfToF2(int numberOfSegments, int segmentSize,
  fstream &f1, fstream &f2);
void mergeOneStep(int numberOfSegments, int segmentSize,
  string f1, string f2, string f3);
void mergeSegments(int numberOfSegments, int segmentSize,
  fstream &f1, fstream &f2, fstream &f3);
void copyFile(string f1, string targetfile);
void displayFile(string filename);

int main()
{
  // Sort largedata.dat into sortedfile.dat
  sort("largedata.dat", "sortedfile.dat");

  // Display the first 100 numbers in sortedfile.dat
  displayFile("sortedfile.dat");
}

/** Sort sourcefile into targetfile */
void sort(string sourcefile, string targetfile)
{
  const int MAX_ARRAY_SIZE = 10000;

  // Implement Phase 1: Create initial segments
  int numberOfSegments =
    initializeSegments(MAX_ARRAY_SIZE, sourcefile, "f1.dat");

  // Implement Phase 2: Merge segments recursively
  merge(numberOfSegments, MAX_ARRAY_SIZE,
    "f1.dat", "f2.dat", "f3.dat", targetfile);
}

/* Sort original file into sorted segments */
int initializeSegments(int segmentSize, string sourceFile, string f1)
{
  int *list = new int[segmentSize];

  fstream input;
  input.open(sourceFile.c_str(), ios::in | ios::binary);
  fstream output;
  output.open(f1.c_str(), ios::out | ios::binary);

  int numberOfSegments = 0;
  while (!input.eof())
  {
    int i = 0;
    for ( ; !input.eof() && i < segmentSize; i++)
    {
      input.read(reinterpret_cast<char*>
        (&list[i]), sizeof(list[i]));
    }

    if (input.eof()) i--;
    if (i <= 0)
      break;
    else
      numberOfSegments++;

    // Sort an array list[0..i-1]
    quickSort(list, i);

    // Write the array to f1.dat
    for (int j = 0; j < i; j++)
    {
      output.write(reinterpret_cast<char*>
        (&list[j]), sizeof(list[j]));
    }
  }

  input.close();
  output.close();
  delete [] list;

  return numberOfSegments;
}

void merge(int numberOfSegments, int segmentSize,
  string f1, string f2, string f3, string targetfile)
{
  if (numberOfSegments > 1)
  {
    mergeOneStep(numberOfSegments, segmentSize, f1, f2, f3);
    merge((numberOfSegments + 1) / 2, segmentSize * 2,
      f3, f1, f2, targetfile);
  }
  else
  { // rename f1 as the final sorted file
    copyFile(f1, targetfile);
    cout << "\nSorted into the file " << targetfile << endl;
  }
}

void copyFile(string f1, string targetfile)
{
  fstream input;
  input.open(f1.c_str(), ios::in | ios::binary);

  fstream output;
  output.open(targetfile.c_str(), ios::out | ios::binary);
  int i = 0;
  while (!input.eof()) // Continue if not end of file
  {
    int value;
    input.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (input.eof()) break;
    output.write(reinterpret_cast<char*>(&value), sizeof(value));
  }

  input.close();
  output.close();
}

void mergeOneStep(int numberOfSegments, int segmentSize, string f1,
  string f2, string f3)
{
  fstream f1Input;
  f1Input.open(f1.c_str(), ios::in | ios::binary);

  fstream f2Output;
  f2Output.open(f2.c_str(), ios::out | ios::binary);

  // Copy half number of segments from f1.dat to f2.dat
  copyHalfToF2(numberOfSegments, segmentSize, f1Input, f2Output);
  f2Output.close();

  // Merge remaining segments in f1 with segments in f2 into f3
  fstream f2Input;
  f2Input.open(f2.c_str(), ios::in | ios::binary);
  fstream f3Output;
  f3Output.open(f3.c_str(), ios::out | ios::binary);

  mergeSegments(numberOfSegments / 2, segmentSize, f1Input, f2Input, f3Output);

  f1Input.close();
  f2Input.close();
  f3Output.close();
}

/** Copy first half number of segments from f1.dat to f2.dat */
void copyHalfToF2(int numberOfSegments, int segmentSize, fstream &f1,
  fstream &f2)
{
  for (int i = 0; i < (numberOfSegments / 2) * segmentSize; i++)
  {
    int value;
    f1.read(reinterpret_cast<char*>(&value), sizeof(value));
    f2.write(reinterpret_cast<char*>(&value), sizeof(value));
  }
}

/** Merge all segments */
void mergeSegments(int numberOfSegments, int segmentSize, fstream &f1,
  fstream &f2, fstream &f3)
{
  for (int i = 0; i < numberOfSegments; i++)
  {
    mergeTwoSegments(segmentSize, f1, f2, f3);
  }

  // f1 may have one extra segment, copy it to f3
  while (!f1.eof())
  {
    int value;
    f1.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (f1.eof()) break;
    f3.write(reinterpret_cast<char*>(&value), sizeof(value));
  }
}

/** Merge two segments */
void mergeTwoSegments(int segmentSize, fstream &f1, fstream &f2,
  fstream &f3)
{
  int intFromF1;
  f1.read(reinterpret_cast<char*>(&intFromF1), sizeof(intFromF1));
  int intFromF2;
  f2.read(reinterpret_cast<char*>(&intFromF2), sizeof(intFromF2));
  int f1Count = 1;
  int f2Count = 1;

  while (true)
  {
    if (intFromF1 < intFromF2)
    {
      f3.write(reinterpret_cast<char*>(&intFromF1), sizeof(intFromF1));
      if (f1.eof() || f1Count++ >= segmentSize)
      {
        if (f1.eof()) break;
        f3.write(reinterpret_cast<char*>(&intFromF2), sizeof(intFromF2));
        break;
      }
      else
      {
        f1.read(reinterpret_cast<char*> (&intFromF1), sizeof(intFromF1));
      }
    }
    else
    {
      f3.write(reinterpret_cast<char*>(&intFromF2), sizeof(intFromF2));
      if (f2.eof() || f2Count++ >= segmentSize)
      {
        if (f2.eof()) break;
        f3.write(reinterpret_cast<char*>(&intFromF1), sizeof(intFromF1));
        break;
      }
      else {
        f2.read(reinterpret_cast<char*>(&intFromF2), sizeof(intFromF2));
      }
    }
  }

  while (!f1.eof() && f1Count++ < segmentSize) {
    int value;
    f1.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (f1.eof()) break;
    f3.write(reinterpret_cast<char*>(&value), sizeof(value));
  }

  while (!f2.eof() && f2Count++ < segmentSize) {
    int value;
    f2.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (f2.eof()) break;
    f3.write(reinterpret_cast<char*>(&value), sizeof(value));
  }
}

/** Display the first 10 numbers in the specified file */
void displayFile(string filename)
{
  fstream input(filename.c_str(), ios::in | ios::binary);
  int value;
  for (int i = 0; i < 100; i++)
  {
    input.read(reinterpret_cast<char*>(&value), sizeof(int));
    cout << value << " ";
  }

  input.close();
}
```

Before you run this program, first run **LiveExample 19.7**, CreateLargeFile.cpp, to create largedata.dat. Invoking `sort("largedata.dat", "sortedfile.dat")` (line 27) reads data from `largedata.dat` and writes sorted data `sortedfile.dat`. Invoking `displayFile("sortedfile.dat")` (line 30) displays the first `100` numbers in the specified file. Note that the files are created using binary I/O. You cannot view them using a text editor such as Notepad.

The `sort` [[function]] first creates initial segments from the original array and stores the sorted segments in a new file f1.dat (lines 39–40), and then produces a sorted file in targetfile (lines 43–44).

The merge [[function]] (lines 91-105) merges the segments in `f1` into `f3`, using `f2` to assist the merge. The `merge` [[function]] is invoked recursively with many merge steps. Each merge step reduces the `numberOfSegments` by half and doubles the sorted segment size. After completing one merge step, the next merge step merges the new segments in `f3` to `f2`, using `f1` to assist the merge recursively (lines 97-98).

The `numberOfSegments` for the next merge step is `(numberOfSegments + 1) / 2` in line 97. For example, if `numberOfSegments` is 5, `numberOfSegments` is 3 for the next merge step, because every two segments are merged but there is one left unmerged.

The recursive `merge` [[function]] ends when `numberOfSegments` is `1`. In this case, `f1` contains sorted data. File `f1` is copied to targetfile in line 102.

## 19.8.4 [[External Sort]] Complexity

In the [[external sort]], the dominating cost is that of I/O. Assume _n_ is the number of elements to be sorted in the file. In Phase I, _n_ number of elements are read from the original file and output to a temporary file. Therefore, the I/O for Phase I is _O_(_n_).

In Phase II, before the first merge step, the number of sorted segments is nc, where _c_ is `MAX_ARRAY_SIZE`. Each merge step reduces the number of segments by half. Thus, after the first merge step, the number of segments is n23c.  After the second merge step, the number of segments is n22c,  and after the third merge step the number of segments is n23c.  After log (nc) merge steps, the number of segments has been reduced to 1. Therefore, the total number of merge steps is log(nc).

In each merge step, half of the number of segments are read from file `f1` and then written into a temporary file `f2`. The remaining segments in `f1` are merged with the segments in `f2`. The number of I/Os in each merge step is _O_(_n_). Since the total number of merge steps is log (nc), the total number of I/Os is

$$O (n) × log (nc) = O (n log n)$$

Therefore, the complexity of the [[external sort]] is _O_(_n_ log _n_).

## Self-Check
### Describe how [[external sort]] works. What is the complexity of the [[external sort]] algorithm?

See the text. The time complexity for an [[external sort]] is $O(nlogn)$ on disk I/O of blocks of data.
# References
