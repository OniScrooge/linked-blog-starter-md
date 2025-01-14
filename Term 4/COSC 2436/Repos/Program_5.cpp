/*
Name: Patrick Ignaut W211197397

Date:10/26/24

Explanation: This program implements an abstract and normal class. The classes keep track of the amount of comparisons done during the sorting of integer arrays.
The main function instantiates an array, creates a veriable to hold the size of the array, creates a RealSort object, and calls its sort function on the array.
The sort() function takes in the array and its size, and iterates through the function calling the compare() function for the elements in the array.
The compare() function increments the counter of comparisons every time it's called and returns the greater of the two variables.
If this returns true, the standard swap function is called on the elements. Once sorted, the sorted list is printed to the console.
*/

#include <iostream>


class AbstractSort 
{
protected:
    int comparisonCount;  // To keep track of the number of comparisons

public:
    AbstractSort() : comparisonCount(0) {}

    // Virtual function to be overridden by subclasses for sorting
    virtual void sort(int arr[], int size) = 0;

    // Function to compare two elements and increment comparison count
    bool compare(int a, int b)
    {
        ++comparisonCount;  // Increment comparison count
        return (a > b);       // Return result of comparison
    }

    // Function to retrieve the number of comparisons
    int getComparisonCount() const
    {
        return comparisonCount;
    }
};

class RealSort : public AbstractSort 
{
public:
    // Implementing bubble sort
    void sort(int arr[], int size) override 
    {
        for (int i = 0; i < size - 1; ++i) 
        {
            for (int j = 0; j < size - i - 1; ++j) 
            {
                if (compare(arr[j], arr[j + 1]))    // Use compare to check and count comparisons
                {
                    std::swap(arr[j], arr[j + 1]);  // Swap if elements are out of order
                }
            }
        }
    }
};


int main()
{
    const int size {5};
    int arr[size] = {5, 3, 8, 4, 2};

    RealSort sorter;
    sorter.sort(arr, size);

    std::cout << '\n' << "Sorted array: ";
    for (int i{0}; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    std::cout << "Number of comparisons: " << sorter.getComparisonCount() << std::endl;

    return 0;
}