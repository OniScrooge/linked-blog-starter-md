# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.7 Insertion and Deletion and Other functions for a Vector]]

Next - [[COSC 12.9 Case study - Evaluating Expressions]]
# Content

## Key Point

A vector can be used to replace arrays. Vectors are more flexible than arrays, but arrays are more efficient than vectors.

A `vector` object can be used like an array, but there are some differences. ​**Table 12.1**​ lists their similarities and differences.

**Differences and Similarities between Arrays and `vector`**
**Table 12.1**

|   |   |   |
|---|---|---|
|**_Operation_**|**_Array_**|**_vector_**|
|Creating an array/vector|`string` `a[10]`|`vector<string> v`|
|Initializing an array/vector|`int a[] = {1, 2}`|`vector<int> v{1, 2}`|
|Assigning new values||`v = {12, 23}`|
|Accessing an element|`a[index]`|`v[index]`|
|Updating an element|`a[index] = “London”`|`v[index] = “London”`|
|Returning size||`v.size()`|
|Appending a new element||`v.push_back(“London”)`|
|Inserting e to ith position||`v.insert(v.begin() + i, e)`|
|Removing last element||`v.pop_back()`|
|Removing ith element||`v.erase(v.begin() + i)`|
|Removing all elements||`v.clear()`|

Both arrays and vectors can be used to store a list of elements. Using an array is more efficient if the size of the list is fixed. A vector is a resizable array. The `vector` class contains many member functions for accessing and manipulating a vector. Using vectors is more flexible than using arrays. In general, you can always use vectors to replace arrays. All the examples in the preceding chapters that use arrays can be modified using vectors. This section rewrites **LiveExample 7.3**, DeckOfCards.cpp, and **LiveExample 8.1**, PassTwoDimensionalArray, using vectors.

Recall that **LiveExample 7.3** is a program that picks four cards randomly from a deck of `52` cards. We use a vector to store the `52` cards with initial values `0` to `51`, as follows:

```cpp
const int NUMBER_OF_CARDS = 52; 
vector<int> deck(NUMBER_OF_CARDS); 
 
// Initialize cards 
for (int i = 0; i < NUMBER_OF_CARDS; i++) 
  deck[i] = i; 
```

`deck[0]` to `deck[12]` are Clubs, `deck[13]` to `deck[25]` are Diamonds, `deck[26]` to `deck[38]` are Hearts, and `deck[39]` to `deck[51]` are Spades. **LiveExample 12.10** gives the solution to the problem.

**LiveExample 12.10 DeckOfCardsUsingVector.cpp**
```C++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

const int NUMBER_OF_CARDS = 52;
string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
string ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
  "10", "Jack", "Queen", "King"};

int main()
{
  vector<int> deck(NUMBER_OF_CARDS);

  // Initialize cards
  for (int i = 0; i < NUMBER_OF_CARDS; i++)
    deck[i] = i;

  // Shuffle the cards
  srand(time(0));
  random_shuffle(deck.begin(), deck.end()); // Shuffle the cards

  // Display the first four cards
  for (int i = 0; i < 4; i++)
  {
    cout << ranks[deck[i] % 13] << " of " << 
      suits[deck[i] / 13] << endl;
  }

  return 0;
}
```

```
command>cl DeckOfCardsUsingVector.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>DeckOfCardsUsingVector 
6 of Spades
5 of Clubs
9 of Spades
4 of Hearts

command>
```

This program is identical to **LiveExample 7.2**, except that line 2 includes the vector class and line 14 uses a vector to store all cards instead of an array. Additionally this program utilizes the `random_shuffle` function to shuffle the cards (lines 22–23). Interestingly, the syntax for using arrays and vectors is very similar, because you can use indexes in the brackets to access the elements in a vector, which is the same as for accessing array elements.

You could also change the arrays `suits` and `ranks` in lines 8–10 to vectors. If so, you have to write many lines of code to insert the suits and ranks to the vector. The code is simpler and better using arrays.

Recall that **LiveExample 8.1** creates a two-dimensional array and invokes a function to return the sum of all elements in the array. A vector of vectors can be used to represent a two-dimensional array. Here is an example to represent a two-dimensional array with four rows and three columns:

```cpp
vector<vector<int>> matrix(4); // four rows 
for (int i = 0; i < 4; i++) 
  matrix[i] = vector<int>(3); 
matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3; 
matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6; 
matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9; 
matrix[3][0] = 10; matrix[3][1] = 11; matrix[3][2] = 12; 
```

The preceding code can be simplified using the following code:

```cpp
vector<vector<int>> matrix{{1, 2, 3}, 
  {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}; 
```

**LiveExample 12.11** revises **LiveExample 8.1**, PassTwoDimensionalArray.cpp, using vectors.
```C++
#include <iostream>
#include <vector>
using namespace std;

int sum(const vector<vector<int>>& matrix)
{
  int total = 0;
  for (unsigned int row = 0; row < matrix.size(); row++)
  {
    for (unsigned column = 0; column < matrix[row].size(); column++)
    {
      total += matrix[row][column];
    }
  }

  return total;
}

int main()
{
  vector<vector<int>> matrix{
    {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

  cout << "Sum of all elements is " << sum(matrix) << endl;

  return 0;
}
```

```
command>cl TwoDArrayUsingVector.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TwoDArrayUsingVector 
Sum of all elements is 78

command>
```

The variable `matrix` is declared as a vector. Each element of the vector `matrix[i]` is another vector. So, `matrix[i][j]` represents the _i_th row and _j_th column in a two-dimensional array.

The `sum` function returns the sum of all elements in the vector. The size of the vector can be obtained from the `size()` function in the `vector` class. So, you don’t have to specify the vector’s size when invoking the `sum` function. The same function for two-dimensional array requires two parameters as follows:

```cpp
int sum(const int a[][COLUMN_SIZE], int rowSize) 
```

Using vectors for representing two-dimensional arrays simplifies coding.

## Self-Check

### Write the code that represents the following array using a vector:

`int list[4] = {1, 2, 3, 4}; `

#### Answer
```
vector<int> list{1, 2, 3, 4}; or  
vector<int> list = {1, 2, 3, 4};
```

### Line 22 in LiveExample 12.10 DeckOfCardsUsingVector.cpp sets a seed for random generator. What happens if this line is removed from the code?

Every time, the program will pick the same four cards.

### Write the code that represents the following array using a vector:

```C++
int matrix[4][4] =
  {{1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16}};
```

#### Answer
```C++
vector<vector<int>> matrix =
  {{1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16}};
```

### Rewrite lines 8-14 in LiveExample 12.11 using a nested foreach loop.

```C++
for (vector<int> row: matrix)
{
  for (int e: row)
  {
    total += e;
  }
}
```
# References
