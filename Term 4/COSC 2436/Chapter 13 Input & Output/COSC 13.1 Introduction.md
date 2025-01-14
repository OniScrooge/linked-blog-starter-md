# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 12 Summary]]

Next - [[COSC 13.2 Text Input and Output]]
# Content

## Key Point
You can read/write data from/to a file using the functions in the `ifstream`, `ofstream`, and `fstream` classes. 

Data stored in variables, arrays, and objects are temporary; they are lost when the program terminates. To store the data created in a program permanently, you must save them in a file on a permanent storage medium, such as a disk. The file can be transported and can be read later by other programs. **Section 4.11**, “Simple File Input and Output,” introduced simple text I/O involving numeric values. This chapter introduces I/O in detail.

C++ provides the `ifstream`, `ofstream`, and `fstream` classes for processing and manipulating files. These classes are defined in the `<``fstream``>` header file. The `ifstream` class is for reading data from a file, the `ofstream` class is for writing data to a file, and the `fstream` class can be used for reading and writing data in a file.

C++ uses the term _stream_ to describe a flow of data. If it flows to your program, the stream is called an [input stream](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:b1a1b4fa-2889-4b47-8838-e03703976297?source=dashboard#). If it flows out from your program, it is called an [output stream](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:b1a1b4fa-2889-4b47-8838-e03703976297?source=dashboard#). C++ uses objects to read/write a stream of data. For convenience, an input object is called an _input stream_ and an output object is called an _output stream_.

You have already used the input stream and output stream in your programs. `cin` (console input) is a predefined object for reading input from the keyboard, and `cout` (console output) is a predefined object for outputting characters to the console. These two objects are defined in the `<``iostream``>` header file. In this chapter, you will learn how to read/write data from/to files.
# References
