/*
Name: Patrick Ignaut W211197397

Date: October 16th, 2024

Explanation: The program creates a input file, then prompts the user for the name of the file. Then it concatenates ".txt" onto the string to specify it is a txt file.
It then opens an ifstream with the input name and checks to see if the open was successful. If it was is creates an array and an integer variable to hold and convert each letter
to a number. While the end of file has yet to be reached, the program will take in the next input, store it, the increment the array at the index of the letter according to ASCII.
Finally, it prints out the results.
*/
#include <array>
#include <fstream>
#include <iostream>
#include <string>


int main()
{
    // Prompt the user for the filename
    std::string inputFileName = "";
    std::cout << '\n' << "Please input your file name only: ";
    std::cin >> inputFileName;

    inputFileName = inputFileName + ".txt";
    std::ifstream input;
    input.open(inputFileName);

    // Check to see if the file opened
    if (!input.is_open())
    {
        std::cout << "File failed to open" << std::endl;

        return 1;
    }

    // Take input and increment the array
    std::array<int, 128> letterArray {};
    char letter;
    int letterNumber;
    while (input >> letter)
    {
        letterNumber = static_cast<int>(letter);
        if (letterNumber >= 65 && letterNumber < 128)
        {
            letterArray[letterNumber] += 1;
        }
    }

    // Print out the results
    std::cout << '\n';
    for (int i{33}; i < 128; ++i)
    {
        std::cout << "Letter " << static_cast<char>(i) << " has a count of: " << letterArray[i] << std::endl;
    }

    input.close();

    return 0;
}