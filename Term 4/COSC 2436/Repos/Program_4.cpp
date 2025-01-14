/*
Name: Patrick Ignaut W211197397

Date: October 16th, 2024

Explanation: The program calls the A function with two integer parameters. A() either returns (n + 1) if m equals 0, calls A() recursively with m = m-1 and n, and in all other cases
it calls A() recursively with m = m-1 and n = n-1. These results are then printed to the console.
*/

#include <iostream>

// Function to handle the Ackermann's function
int A(int m, int n)
{
    if (m == 0)
        return n+1;
    else if (n == 0)
        return A(m-1, 1);
    else
        return A(m-1, A(m, n-1));
    
}


int main()
{
    // Prints the results of Ackermann's function with the function call
    std::cout << '\n';
    std::cout << "A(0, 0): " << A(0, 0) << '\n';
    std::cout << "A(0, 1): " << A(0, 1) << '\n';
    std::cout << "A(1, 1): " << A(1, 1) << '\n';
    std::cout << "A(1, 2): " << A(1, 2) << '\n';
    std::cout << "A(1, 3): " << A(1, 3) << '\n';
    std::cout << "A(2, 2): " << A(2, 2) << '\n';
    std::cout << "A(3, 2): " << A(3, 2) << '\n';

    return 0;
}