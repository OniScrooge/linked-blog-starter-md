# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.3 Passing objects to functions]]

Next - [[COSC Chapter 10.5 Instance and static members]]
# Content
## Key Point
You can create an array of any objects just like an array of primitive values or strings.

In **Chapter 7**, arrays of primitive type elements and strings were created. You can create arrays of any objects. For example, the following statement declares an array of 10 `Circle` objects:
```cpp
Circle circleArray[10]; // Declare an array of ten Circle objects 
```

The name of the array is `circleArray`, and the [[no-arg constructor]] is called to initialize each element in the array. So, `circleArray[0].getRadius()` returns `1`, because the [[no-arg constructor]] assigns `1` to `radius`.

You can also use the array initializer to declare and initialize an array using a constructor with arguments. For example:
```cpp
Circle circleArray[3] = {Circle(3), Circle(4), Circle(5)}; 
```

**LiveExample 10.5** gives an example that demonstrates how to use an array of objects. The program summarizes the areas of an array of circles. It creates `circleArray`, an array composed of 10 `Circle` objects; it then sets circle radii with radius `1`, `2`, `3`, `4`, ..., and `10` and displays the total area of the circles in the array.

## **LiveExample 10.5 TotalArea.cpp**
```cpp
#include <iostream>
#include <iomanip>
#include "CircleWithPrivateDataFields.h"
using namespace std;

// Add circle areas
double sum(Circle circleArray [], int size)
{
  // Initialize sum
  double sum = 0;

  // Add areas to sum
  for (int i = 0; i < size; i++)
    sum += circleArray[i].getArea();

  return sum;
}

// Print an array of circles and their total area
void printCircleArray(Circle circleArray[], int size)
{
  cout << setw(35) << left << "Radius" << setw(8) << "Area" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << setw(35) << left << circleArray[i].getRadius() 
      << setw(8) << circleArray[i].getArea() << endl;
  }

  cout << "-----------------------------------------" << endl;

  // Compute and display the result
  cout << setw(35) << left << "The total area of circles is" 
    << setw(8) << sum(circleArray, size) << endl;
}

int main()
{
  const int SIZE = 10;

  // Create a Circle object with radius 1
  Circle circleArray[SIZE];

  for (int i = 0; i < SIZE; i++)
  {
    circleArray[i].setRadius(i + 1);
  }

  printCircleArray(circleArray, SIZE);

  return 0;
}
```
```
command>cl TotalArea.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TotalArea 
Radius                             Area    
1                                  3.14159 
2                                  12.5664 
3                                  28.2743 
4                                  50.2654 
5                                  78.5397 
6                                  113.097 
7                                  153.938 
8                                  201.062 
9                                  254.469 
10                                 314.159 
-----------------------------------------
The total area of circles is       1209.51 

command>
```
The program creates an array of ten `Circle` objects (line 41). Two `Circle` classes were introduced in **Chapter 9**. This example uses the `Circle` class defined in **LiveExample 9.9** (line 3).

Each object element in the array is created using the `Circle`’s no-arg constructor. A new radius for each circle is set in lines 43–46. `circleArray[i]` refers to a `Circle` object in the array. `circleArray[i].setRadius(i + 1)` sets a new radius in the `Circle` object (line 45). The array is passed to the `printCircleArray` function, which displays the radius and area of each circle and the total area of the circles (line 48).

The sum of the areas of the circle is computed using the `sum` function (line 33), which takes the array of `Circle` objects as the argument and returns a `double` value for the total area.

## Self-Check
### How do you declare an array of 10 string objects?
`string strArray[10];`
### What is the output of the following code?
```cpp
1  int main()
2  {
3    string cities[] = {"Atlanta", "Dallas", "Savannah"};
4    cout << cities[0] << endl;
5    cout << cities[1] << endl;
6
7    return 0;
8  }
```
Atlanta  
Dallas
# References
