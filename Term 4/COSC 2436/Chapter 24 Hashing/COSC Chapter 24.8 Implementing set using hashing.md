# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 24.7 Implementing a Map using Hashing]]

Next - [[COSC Chapter Summary 24]]
# Content
## Key Point
A set can be implemented using hashing.

The C++ STL defines the `set` and `multiset` for modeling sets. You can implement them using the same approach as for implementing `MyMap`. The only difference is that key/value pairs are stored in the map, while elements are stored in the set.

In this section, we will implement the set class. The code can be easily modified to implement the multiset class. We design our custom `set` class to mirror `set` and name it `MySet`, as shown in **Figure 24.11**.

## Figure 24.11
![[Pasted image 20241204200941.png]]
**LiveExample** **24.3** implements `MySet` using separate chaining.

## **LiveExample 24.3 MySet.h**
```cpp
#ifndef MYSet_H
#define MYSet_H

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

int DEFAULT_INITIAL_CAPACITY = 4;
float DEFAULT_MAX_LOAD_FACTOR = 0.75f; 
unsigned MAXIMUM_CAPACITY = 1 << 30; 

template<typename K>
class MySet
{
public:
  MySet();
  MySet(int initialCapacity);
  MySet(int initialCapacity, float loadFactorThreshold);

  int getSize() const;
  bool isEmpty() const;
  bool contains(const K& key) const;
  bool add(const K& key);
  bool remove(const K& key);
  void clear();
  vector<K> getKeys() const;
  string toString() const;

private:
  int size; 
  float loadFactorThreshold; 
  int capacity; 

  // Hash table is an array with each cell as a vector
  vector<K>* table; // table is a pointer to the array

  int hash(int hashCode) const;
  unsigned hashCode(const K& key) const;
  int supplementalHash(int h) const; 
  int trimToPowerOf2(int initialCapacity);
  void rehash(); // rehash() function
  void removeKeys();
};

template<typename K>
MySet<K>::MySet()
{
  capacity = DEFAULT_INITIAL_CAPACITY;
  table = new vector<K>[capacity]; // Create the array for hash table
  loadFactorThreshold = DEFAULT_MAX_LOAD_FACTOR;
  size = 0;
}

template<typename K>
MySet<K>::MySet(int initialCapacity)
{
  capacity = initialCapacity;
  table = new vector<K>[capacity]; // Create the array for hash table
  loadFactorThreshold = DEFAULT_MAX_LOAD_FACTOR;
  size = 0;
}

template<typename K>
MySet<K>::MySet(int initialCapacity, float loadFactorThreshold) 
{ 
  if (initialCapacity > MAXIMUM_CAPACITY)
    capacity = MAXIMUM_CAPACITY;
  else
    capacity = trimToPowerOf2(initialCapacity);
    
  this->loadFactorThreshold = loadFactorThreshold;    
  table = new vector<K>[capacity]; // Create the array for hash table
  size = 0;
}

template<typename K>
bool MySet<K>::add(const K& key)
{
  if (contains(key)) return false; // key is already in the set
  
  // Check load factor
  if (size >= capacity * loadFactorThreshold) 
  {
    if (capacity == MAXIMUM_CAPACITY)
      throw runtime_error("Exceeding maximum capacity");
      
    rehash();
  }
    
  int bucketIndex = hash(hashCode(key)); // Map the key to an index

  // Add a new entry (key, value) to hashTable[index]
  table[bucketIndex].push_back(key);

  size++; // Increase size

  return true;
} 

template<typename K>
bool MySet<K>::isEmpty() const
{
  return size == 0; // Return true if size is 0
}

template<typename K>
bool MySet<K>::contains(const K& key) const
{    
  int bucketIndex = hash(hashCode(key));

  for (K& e: table[bucketIndex]) // Test every element in table[bucket]
    if (e == key) 
      return true;
    
  return false;
}
  
template<typename K>
bool MySet<K>::remove(const K& key) 
{
  int bucketIndex = hash(hashCode(key));
    
  // Remove the first entry that matches the key from a bucket
  if (table[bucketIndex].size() > 0) 
  {
    for (auto p = table[bucketIndex].begin(); 
        p != table[bucketIndex].end(); p++)
      if (*p == key) // Test if *p is key
      {
        table[bucketIndex].erase(p);
        size--; // Decrease size
        return true; // Remove just one entry that matches the key
      }
  } 

  return false;
}

template<typename K>
void MySet<K>::clear() 
{
  size = 0;
  removeKeys();
}

template<typename K>
vector<K> MySet<K>::getKeys() const
{
  vector<K> v;
    
  for (int i = 0; i < capacity; i++) 
  {
    for (K& e: table[i])
      v.push_back(e); // Add e to v
  }
    
  return v;
}

template<typename K>
void MySet<K>::removeKeys() 
{
  for (int i = 0; i < capacity; i++) 
  {
    table[i].clear();
  }
}

template<typename K>
string MySet<K>::toString() const
{
  stringstream ss;
  ss << "[";
    
  for (int i = 0; i < capacity; i++) 
  {
    for (K& e: table[i])
      ss << e << " ";
  }
    
  ss << "]";
  return ss.str();
}

template<typename K>
unsigned MySet<K>::hashCode(const K& key) const
{ 
  return std::hash<K>()(key); // Use hash<K>()(key) 
}

template<typename K>
int MySet<K>::hash(int hashCode) const
{
  return supplementalHash(hashCode) & (capacity - 1);
}
  
template<typename K>
int MySet<K>::supplementalHash(int h) const
{
  h ^= (h >> 20) ^ (h >> 12);
  return h ^ (h >> 7) ^ (h >> 4);
}

template<typename K>
int MySet<K>::trimToPowerOf2(int initialCapacity) 
{
  int capacity = 1;
  while (capacity < initialCapacity) 
    capacity <<= 1;
    
  return capacity;
}

template<typename K>
void MySet<K>::rehash() 
{
  vector<K> set = getKeys(); // Get entries
  capacity <<= 1; // Double capacity   
  delete[] table; // Delete old hash table
  table = new vector<K>[capacity]; // Create a new hash table
  size = 0; // Reset size to 0
    
  for (K& e: set) 
    add(e); // Store to new table
}

template<typename K>
int MySet<K>::getSize() const
{
  return size; // Return size
}

#endif
```

Implementing `MySet` is very similar to implementing `MyMap` except that the keys are stored in the hash table for `MySet`, but the entries (key/value pairs) are stored in the hash table for `MyMap`.

Three constructors are provided to construct a set. You can construct a default set with the default capacity and load factor using the no-arg constructor (lines 47–54), a set with the specified capacity and a default load factor (lines 56–63), and a set with the specified capacity and load factor (lines 65–76).

The `add(key)` function adds a new key into the set. The function first checks if the key is already in the set (line 81). If so, the function returns false. The function then checks whether the size exceeds the load-factor threshold (line 84). If so, the program invokes `rehash()` (line 89) to increase the capacity and store keys into the new larger hash table.

The `rehash()` function first copies all keys in a list (line 219), doubles the capacity (line 220), delete the old table (line 221), creates a new hash table (line 222), and resets the size to `0` (line 223). The function then copies the keys into the new larger hash table (lines 225–226). The `rehash` function takes _O_(_capacity_) time. If no rehash is performed, the `add` function takes _O_(1) time to add a new key.

The `clear` function removes all keys from the set (lines 141–146). It invokes `removeKeys()`, which clears all table cells (line 167). Each table cell is a vector that stores the keys with the same hash code. The `removeKeys()` function takes _O_(_capacity_) time.

The `contains(key)` function checks whether the specified key is in the set by examining whether the designated bucket contains the key (lines 108–118). This function takes _O_(1) time.

The `remove(key)` function removes the specified key in the set (lines 120–139). This function takes _O_(1) time.

The `getSize()` function simply returns the number of keys in the set (lines 229–233). This function takes _O_(1) time.

The `hashCode`, `hash`, `supplementalHas`h, and `trimToPowerOf2` are the same as in the `MyMap` class.

**Table 24.2** summarizes the time complexity of the functions in `MySet`.

#### Table 24.2

#### **Time Complexities for Functions in `MySet`**

|**Functions**|**Time**|
|---|---|
|`clear()`|_O_(_capacity_)|
|`contains(k: K)`|_O_(1)|
|`add(k: K)`|_O_(1)|
|`remove(k: K)`|_O_(1)|
|`isEmpty()`|_O_(1)|
|`getSize()`|_O_(1)|
|`getKeys()`|_O_(_size_)|
|`rehash()`|_O_(_capacity_)|

**LiveExample 24.4** gives a test program that uses `MySet`.

## **LiveExample 24.4 TestMySet.cpp**
```cpp
#include <iostream>
#include <string>
#include "MySet.h"
using namespace std;

int main()
{ 
  // Create a MySet
  MySet<string> set;
  set.add("Smith"); // Add Smith to set
  set.add("Anderson");
  set.add("Lewis");
  set.add("Cook");
  set.add("Smith"); // Add Smith to set

  cout << "Keys in set: " << set.toString() << endl;
  cout << "Number of keys in set: " << set.getSize() << endl;
  cout << "Is Smith in set? " << set.contains("Smith") << endl;

  set.remove("Smith");
  cout << "Names in set are ";
  for (string s: set.getKeys())
    cout << s << " ";

  set.clear();
  cout << "\nKeys in set: " << set.toString() << endl;

  return 0;
}
```
```
command>cl TestMySet.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestMySet 
Keys in set: [Smith Anderson Lewis Cook ]
Number of keys in set: 4
Is Smith in set? 1
Names in set are Anderson Lewis Cook 
Keys in set: []

command>
```

The program creates a set using `MySet` (line 9) and adds five keys to the set (lines 10–14). Line 10 adds `Smith` and line 14 adds `Smith` again. Since only nonduplicate keys are stored in the set, `Smith` appears in the set only once. The set actually has four keys. The program displays the keys (line 16), gets its size (line 17), checks whether the set contains a specified key (line 18), and removes an key (line 20). Since the keys in a set are iterable, a for-each loop is used to traverse all keys in the set (lines 22–23). Finally, the program clears the set (line 25) and displays an empty set (line 26).
# References
