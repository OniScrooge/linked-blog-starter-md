/*
Name: Patrick Ignaut - w211197397 CRN:15693
Date: October 10th, 2024
Explanation: This program instantiates 6 DivisionSales objects from the DivisionSales class. It prompts the used for the input of sales numebrs as doubles.
It then displays a table of the numbers entered for reference. The program issues the total sales of the combined numbers entered by the used, then terminates.
*/
#include <iostream>

class DivisionSales
{
private:
    double sales[4];
    static double totalSales;

public:
    DivisionSales()
    {
        std::cout << '\n' << "Please enter the sales for four quarters: " << std::endl;
        double temp[4];
        for (int i{0}; i < 4; ++i)
        {
            std::cin >> temp[i];
        }

        setSales(temp[0], temp[1], temp[2], temp[3]);
    }

    // A member function that takes four arguments, each assumed to be the sales for a quarter
    void setSales(double v1, double v2, double v3, double v4)
    {
        // The value of the arguments should be copied into the array that holds the sales data
        sales[0] = v1;
        sales[1] = v2;
        sales[2] = v3;
        sales[3] = v4;

        std::cout << '\n' << "Input complete." << std::endl;
        std::cout << '\n';

        // After the data is entered, the program displays a table showing the division sales for each quarter
        std::cout << "Division sales: \n";
        for (int i{0}; i < 4; ++i) 
        {
            std::cout << "Quarter " << i+1 << ": " << sales[i] << '\n';
        }

        // Add the sales of the current division to the totalSales
        for (int i = 0; i < 4; ++i) 
        {
            totalSales += sales[i];
        }

        std::cout << std::endl;

        std::cout << std::endl;
    }

    // A function that takes an integer argument within the range of 0 to 3
    double getQSales(int q)
    {
        // The argument is to be used as a subscript into the division quarterly sales array
        if (q > 3 || q < 0)
        {
            std::cout << "Error: Input not in scope";
        }
        // The function should return the value of the array element with that subscript
        return sales[q];
    }

    double getCorpSales()
    {
        return totalSales;
    }

};

// Initialize the static variable
double DivisionSales::totalSales = 0;

int main()
{
    DivisionSales v1;
    DivisionSales v2;
    DivisionSales v3;
    DivisionSales v4;
    DivisionSales v5;
    DivisionSales v6;

    std::cout << "Total corporate sales: " << v6.getCorpSales() << std::endl;

    return 0;
}