# Summary

# Learning Objectives

# Related

# Content

## Key Point

The `ios::binary` mode can be used to open a file for binary input and output.

So far, you have used text files. Files can be classified into text and binary. A file that can be processed (read, created, or modified) using a text editor such as Notepad on Windows or vi on UNIX is called a [text file](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:5f61a7b9-483c-43b2-b5f3-36109c9b2611?source=dashboard#). All the other files are called [binary files](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:5f61a7b9-483c-43b2-b5f3-36109c9b2611?source=dashboard#). You cannot read binary files using a text editor. They are designed to be read by programs. For example, the C++ source programs are stored in text files and can be read by a text editor, but the C++ executable files are stored in binary files and are read by the operating system.

Although it is not technically precise and correct, you can envision a text file as consisting of a sequence of characters and a binary file as consisting of a sequence of bits. For example, the decimal integer `199` is stored as the sequence of the three characters, `'1'`, `'9'`, `'9'`, in a text file, and the same integer is stored as an integer `C7` in a binary file, because decimal `199` equals hex `C7` (199 = 12 × 161 + 7). The advantage of binary files is that they are more efficient to process than text files.

>[!Note]
Computers do not differentiate binary files and text files. All files are stored in binary format, and thus all files are essentially binary files. Text I/O is built upon binary I/O to provide a level of abstraction for character encoding and decoding.

Binary I/O does not require conversions. If you write a numeric value to a file using binary I/O, the exact value in the memory is copied into the file. To perform binary I/O in C++, you have to open a file using the binary mode `ios::binary`. By default, a file is opened in text mode.

You used the `<<` operator and `put` function to write data to a text file and the `>>` operator, `get`, and `getline` functions to read data from a text file. To read/write data from/to a binary file, you have to use the `read` and `write` functions on a stream.

## Self-Check

### What is a text file, and what is a binary file? Can you view a text file or a binary file using a text editor?

Although it is not technically precise, a text file consists of a sequence of characters and a binary file consists of a sequence of bits. You can use a text editor to view a text file, but not a binary file.

# References
