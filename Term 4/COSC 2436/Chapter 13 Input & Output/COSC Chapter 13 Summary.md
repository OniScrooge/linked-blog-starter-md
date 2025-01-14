# Summary

# Learning Objectives
1. To use `ofstream` for output (§13.2.1) and `ifstream` for input (§13.2.2).
2. To test whether a file exists (§13.2.3).
3. To test the end of a file (§13.2.4).
4. To let the user enter a filename (§13.2.5).
5. To write data in a desired format (§13.3).
6. To read and write data using the `getline`, `get`, and `put` functions (§13.4).
7. To use an `fstream` object to read and write data (§13.5).
8. To open a file with specified modes (§13.5).
9. To use the `eof()`, `fail()`, `bad()`, and `good()` functions to test stream states (§13.6).
10. To understand the difference between text I/O and binary I/O (§13.7).
11. To write binary data using the `write` function (§13.7.1).
12. To read binary data using the `read` function (§13.7.2).
13. To cast primitive type values and objects to byte arrays using the `reinterpret_cast` operator (§13.7).
14. To read/write arrays and objects (§§13.7.3–13.7.4).
15. To use the `seekp` and `seekg` functions to move the file pointers for random file access (§13.8).
16. To open a file for both input and output to update files (§13.9).
# Related

# Content

## Key Terms
1. **[[absolute file name]]**
2. **binary file**
3. **file open mode**
4. **file pointer**
5. **input stream**
6. **output stream**
7. **[[random access file]]**
8. **[[relative file name]]**
9. **[[sequential access file]]**
10. **stream state**
11. **text file**

## Chapter Summary
1. C++ provides the classes `ofstream`, `ifstream`, and `fstream` for facilitating file input and output.
2. You can use the `ofstream` class to write data to a file, use `ifstream` to read data from a file, and use the `fstream` class to read and write data.
3. You can use the `open` function to open a file, the `close` function to close a file, the `fail` function to test whether a file exists, the `eof` function to test whether the end of the file is reached.
4. The stream manipulators (e.g., `setw`, `setprecision`, `fixed`, `showpoint`, `left`, and `right`) can be used to format output.
5. You can use the `getline` function to read a line from a file, the `get` function to read a character from a file, and the `put` function to write a character to a file.
6. The file open modes (`ios::in`, `ios::out`, `ios::app`, `ios::trunc`, and `ios::binary`) can be used to specify how a file is opened.
7. File I/O can be classified into text I/O and binary I/O.
8. Text I/O interprets data in sequences of characters. How text is stored in a file is dependent on the encoding scheme for the file. C++ automatically performs encoding and decoding for text I/O.
9. Binary I/O interprets data as raw binary values. To perform binary I/O, open the file using the `iso::binary` mode.
10. For binary output, use the `write` function. For binary input, use the `read` function.
11. You can use the `reinterpret_cast` operator to cast any type of data into an array of bytes for binary input and output.
12. You can process a file sequentially or in a random manner.
13. The `seekp` and `seekg` functions can be used to move the file-access pointer anywhere in the file before invoking the `put`/`write` and `get`/`read` functions.

# References
