/*
Name: Patrick Ignaut W211197397

Date: October 12th, 2024

Explanation: This program prompts the user for the amount of test scores they need to input. It instantiates a map of that size and prompts the user for each student and their score
and rejecting negatives. It then sorts the scores in ascending order and calculates the sum. Finally, it reads out the scores in order and the average back to the user.

*/
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>


// Function that sums the values of the map
int sumTestScoreMap(std::map<std::string, int>& map)
{
    // Use the accumulate function to iterate through the map with a lambda function that adds the value of the current pair to the previous variable and returns it
    return std::accumulate(map.begin(), map.end(), 0, [](const int previous, const std::pair<std::string, int>& pair)
    {
        return (previous + pair.second);
    });
}

// Function for printing a map sorted in order of their value instead of key
void sortTestScoreMap(const std::map<std::string, int>& map)
{
    // Create an array that can be sorted
    std::vector<std::pair<std::string, int>> mapList;

    // Instantiate it with elements from map
    for (const auto& element : map)
    {
        mapList.push_back(element);
    }

    // Sort that array based on value using a lambda function to compare the values of the current pairs
    std::sort(mapList.begin(), mapList.end(), [](auto& a, auto& b)
    {
        return a.second < b.second;
    });

    // Iterate over the sorted map and print its key and value
    for (const auto& element : mapList)
    {
        std::cout << "Student: " << element.first << " Score: " << element.second << '\n';
    }
}


int main()
{
    // Prompt user for map size
    std::cout << "\nPlease input the number of test scores(1-1000): ";

    int testScoreCount{};
    std::cin >> testScoreCount;
    
    // Instantiate a set and use it's member function to make its size to the user's definition
    std::map<std::string, int> testScoreMap{};

    // Prompt the user for the input of the scores
    std::string name{""};
    int score{0};
    std::cout << "Please input the student name, then the non-negative score\n";
    for (int i{0}; i < testScoreCount; ++i)
    {
        std::cout << "Name: ";
        std::cin >> name;

        std::cout << "Score #" << i+1 << ": ";
        std::cin >> score;

        // Check the attempted value
        while (score < 0)
        {
            // Issue an error and prompt the user for input
            std::cout << "Error: non-negative scores only, please try again: ";
            std::cin >> score;
        }
        
        testScoreMap.insert({name, score});
    }

    // Call the sorting function to sort the map
    sortTestScoreMap(testScoreMap);

    // Create a variable to hold the sum of the array and pass the array to a function for summing
    int testScoreSum {sumTestScoreMap(testScoreMap)};

    // Print the average
    std::cout << "Test score average: " << testScoreSum/testScoreCount;

    return 0;
}