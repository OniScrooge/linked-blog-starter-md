/*
Name: Patrick Ignaut W211197397
Date: October 12th, 2024
Explanation: This program prompts the user for the amount of test scores they need to input. It instantiates an array of that size and prompts the user for each score
and rejecting negatives. It then sorts the scores in ascending order and calculates the sum. Finally, it reads out the scores in order and the average back to the user.
*/
#include <algorithm>
#include <iostream>
#include <vector>

// Function that sorts the array
void sortTestScoreArray(std::vector<int>& list)
{
    std::sort(list.begin(), list.end());
}

// Function that sums the values of the array
int sumTestScoreArray(std::vector<int> list)
{
    int sum {0};
    for (const auto& element : list)
    {
        sum += (element);
    }

    return sum;
}

int main()
{
    // Prompt user for array size
    std::cout << "\nPlease input the number of test scores(1-1000): ";

    int testScoreCount{};
    std::cin >> testScoreCount;
    
    // Instantiate an integer array and use it's member function to make its size to the user's definition
    std::vector<int> testScoreArray;
    testScoreArray.resize(testScoreCount);

    // Prompt the user for the input of the scores 
    std::cout << "Please input your non-negative scores\n";
    int temp{};
    for (int i{0}; i < testScoreCount; ++i)
    {
        std::cout << "Score #" << i+1 << ": ";
        std::cin >> temp;
        // Check the attempted value
        while (temp < 0)
        {
            // Issue an error and prompt the user for input
            std::cout << "Error: non-negative scores only, please try again: ";
            std::cin >> temp;
        }
        testScoreArray[i] = temp;
    }

    // Pass array to function for sorting
    sortTestScoreArray(testScoreArray);

    // Create a variable to hold the sum of the array and pass the array to a function for summing
    int testScoreSum {sumTestScoreArray(testScoreArray)};

    // Iterate over the array and print the now sorted array and then the average
    std::cout << "Test scores\n";
    for (int i{0}; i < testScoreCount; ++i)
    {
        std::cout << "Score #" << i+1 << ": " << testScoreArray[i] << '\n';
    }
    std::cout << "Test score sum: " << testScoreSum/testScoreCount;

    return 0;
}