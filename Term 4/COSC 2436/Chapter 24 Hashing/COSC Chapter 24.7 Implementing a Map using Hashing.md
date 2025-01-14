# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 24.6 Load Factor and Rehashing]]

Next - [[COSC Chapter 24.8 Implementing set using hashing]]
# Content
## Key Point
A map can be implemented using hashing.

Now you understand the concept of hashing. You know how to design a good hash function to map a key to an index in a hash table, how to measure performance using the load factor, and how to increase the table size and rehash to maintain the performance. This section demonstrates how to implement a map using separate chaining.

The STL defines the `map` and `multimap` classes for modeling maps. In this section, we will implement the `map` class. The code can be easily modified to implement the `multimap` class. We design our custom `map` class and name it `MyMap`, as shown in **Figure 24.10**.

## Figure 24.10
![[Pasted image 20241204200407.png]]

How do you implement `MyMap`? We will use a vector for the hash table and each element in the hash table is a bucket. The bucket is also a vector. **LiveExample 24.1** implements `MyMap` using separate chaining.

## **LiveExample 24.1 MyMap.h**
```cpp
#ifndef MYMAP_H
#define MYMAP_H

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

int DEFAULT_INITIAL_CAPACITY = 4;
float DEFAULT_MAX_LOAD_FACTOR = 0.75f;
unsigned MAXIMUM_CAPACITY = 1 << 30;

template<typename K, typename V>
class Entry // Represent an entry with key and value
{
public:
  Entry(const K& key, const V& value)
  {
    this->key = key;
    this->value = value;
  }

  string toString() const
  {
    stringstream ss;
    ss << "[" << key << ", " << value << "]";
    return ss.str();
  }

  K key;
  V value;
};

template<typename K, typename V>
class MyMap
{
public:
  MyMap();
  MyMap(int initialCapacity);
  MyMap(int initialCapacity, float loadFactorThreshold);

  V put(const K& key, const V& value);
  V& get(const K& key) const;
  int getSize() const;
  bool isEmpty() const;
  vector<Entry<K, V>> getEntries() const;
  vector<K> getKeys() const;
  vector<V> getValues() const;
  string toString() const;
  bool containsKey(const K& key) const;
  bool containsValue(const V& value) const;
  void remove(const K& key);
  void clear();

private:
  int size;
  float loadFactorThreshold;
  int capacity;

  // Hash table is an array with each cell as a vector
  vector<Entry<K, V>>* table; // table is a pointer to the array

  int hash(int hashCode) const;
  unsigned hashCode(const K& key) const;
  int supplementalHash(int h) const;
  int trimToPowerOf2(int initialCapacity);
  void rehash(); // rehash() function
  void removeEntries();
};

template<typename K, typename V>
MyMap<K, V>::MyMap()
{
  capacity = DEFAULT_INITIAL_CAPACITY;
  table = new vector<Entry<K, V>>[capacity]; // Create an array of vector<Entry<K, V>>
  loadFactorThreshold = DEFAULT_MAX_LOAD_FACTOR;
  size = 0; // Set size to 0
}

template<typename K, typename V>
MyMap<K, V>::MyMap(int initialCapacity)
{
  capacity = initialCapacity;
  table = new vector<Entry<K, V>>[capacity]; // Create an array of vector<Entry<K, V>>
  loadFactorThreshold = DEFAULT_MAX_LOAD_FACTOR;
  size = 0;
}

template<typename K, typename V>
MyMap<K, V>::MyMap(int initialCapacity, float loadFactorThreshold)
{
  if (initialCapacity > MAXIMUM_CAPACITY)
    capacity = MAXIMUM_CAPACITY;
  else
    capacity = trimToPowerOf2(initialCapacity);

  this->loadFactorThreshold = loadFactorThreshold;
  table = new vector<Entry<K, V>>[capacity];
  size = 0;
}

template<typename K, typename V>
V MyMap<K, V>::put(const K& key, const V& value)
{
  if (containsKey(key)) // Test if key is in the map
  { // The key is already in the map. Update the value for the key.
    int bucketIndex = hash(hashCode(key)); // Hash key to an index
    for (Entry<K, V>& entry : table[bucketIndex])
    {
      if (entry.key == key) // Test if key is already in the map
      {
        V oldValue = entry.value;
        // Replace old value with new value
        entry.value = value;
        // Return the old value for the key
        return oldValue;
      }
    }
  }

  // Check load factor
  if (size >= capacity * loadFactorThreshold)
  {
    if (capacity == MAXIMUM_CAPACITY)
      throw runtime_error("Exceeding maximum capacity");

    rehash();
  }

  int bucketIndex = hash(hashCode(key)); // Hash key to an index 

  // Add a new entry (key, value) to hashTable[index]
  table[bucketIndex].push_back(Entry<K, V>(key, value));

  size++; // Increase size

  return value;
}

template<typename K, typename V>
V& MyMap<K, V>::get(const K& key) const
{
  int bucketIndex = hash(hashCode(key));

  for (Entry<K, V>& entry : table[bucketIndex])
    if (entry.key == key)
      return entry.value; // Return the value for the key

  throw runtime_error("Key not found");
}

template<typename K, typename V>
bool MyMap<K, V>::isEmpty() const
{
  return size == 0;
}

template<typename K, typename V>
vector<Entry<K, V>> MyMap<K, V>::getEntries() const
{
  vector<Entry<K, V>> v;

  for (int i = 0; i < capacity; i++)
  {
    for (Entry<K, V>& entry : table[i])
      v.push_back(entry);
  }

  return v;
}

template<typename K, typename V>
bool MyMap<K, V>::containsKey(const K& key) const
{
  try
  {
    get(key);
    return true;
  }
  catch (runtime_error& ex)
  {
    return false; // Key not found
  }
}

template<typename K, typename V>
bool MyMap<K, V>::containsValue(const V& value) const
{
  for (int i = 0; i < capacity; i++)
  {
    for (Entry<K, V> entry : table[i])
      if (entry.value == value)
        return true;
  }

  return false;
}

template<typename K, typename V>
void MyMap<K, V>::remove(const K& key)
{
  int bucketIndex = hash(hashCode(key));

  // Remove the entry that matches the key from a bucket
  if (table[bucketIndex].size() > 0)
  {
    for (auto p = table[bucketIndex].begin();
      p != table[bucketIndex].end(); p++)
      if (p->key == key) // Test if p->key is key
      {
        table[bucketIndex].erase(p);
        size--; // Decrease size
        break; // No need to continue in the loop
      }
  }
}

template<typename K, typename V>
void MyMap<K, V>::clear()
{
  size = 0;
  removeEntries();
}

template<typename K, typename V>
void MyMap<K, V>::removeEntries()
{
  for (int i = 0; i < capacity; i++)
  {
    table[i].clear();
  }
}

template<typename K, typename V>
vector<K> MyMap<K, V>::getKeys() const
{
  // Left as exercise
}

template<typename K, typename V>
vector<V> MyMap<K, V>::getValues() const
{
  // Left as exercise
}

template<typename K, typename V>
string MyMap<K, V>::toString() const
{
  stringstream ss;
  ss << "[";

  for (int i = 0; i < capacity; i++)
  {
    for (Entry<K, V>& entry : table[i])
      ss << entry.toString();
  }

  ss << "]";
  return ss.str();
}

template<typename K, typename V>
unsigned MyMap<K, V>::hashCode(const K& key) const
{
  return std::hash<K>()(key);
}

template<typename K, typename V>
int MyMap<K, V>::hash(int hashCode) const
{
  return supplementalHash(hashCode) & (capacity - 1);
}

template<typename K, typename V>
int MyMap<K, V>::supplementalHash(int h) const
{
  h ^= (h >> 20) ^ (h >> 12);
  return h ^ (h >> 7) ^ (h >> 4);
}

template<typename K, typename V>
int MyMap<K, V>::trimToPowerOf2(int initialCapacity)
{
  int capacity = 1;
  while (capacity < initialCapacity) {
    capacity <<= 1;
  }

  return capacity;
}

template<typename K, typename V>
void MyMap<K, V>::rehash()
{
  vector<Entry<K, V>> set = getEntries(); // Get entries
  capacity <<= 1; // Double capacity   
  delete[] table; // Delete old hash table
  table = new vector<Entry<K, V>>[capacity]; // Create a new hash table
  size = 0; // Reset size to 0

  for (Entry<K, V>& entry : set)
    put(entry.key, entry.value); // Store to new table
}

template<typename K, typename V>
int MyMap<K, V>::getSize() const
{
  return size; // Return size
}

#endif
```

The `MyMap` class is implemented using separate chaining. The parameters that determine load factors (line 58) and the hash-table capacity (line 59) are defined in the class. The default initial capacity is `4` (line 10) and the maximum capacity is 2 ^ 30 (line 12). The current hash-table capacity is designed as an integer of the power of `2`. The default load-factor threshold is `0.75f` (line 11). You can specify a custom load-factor threshold when constructing a map. The custom load-factor threshold is stored in `loadFactorThreshold` (line 58). The data field `size` denotes the number of entries in the map (line 59). The hash table is an array. Each cell in the array is a vector (line 62).

Three constructors are provided to construct a map. You can construct a default map with the default capacity and load-factor threshold using the no-arg constructor (lines 72–79), a map with the specified capacity and a default load-factor threshold (lines 81–88), and a map with the specified capacity and load-factor threshold (lines 90–101).

The `put(key, value)` function adds a new entry into the map (lines 103–120). The function first tests if the key is already in the map (line 106), if so, it locates the entry and replaces the old value with the new value in the entry for the key (line 115) and the old value is returned (line 117). If the key is new in the map, the new entry is created in the map (line 134). Before inserting the new entry, the function checks whether the size exceeds the load-factor threshold (line 123). If so, the program invokes `rehash()` (line 128) to increase the capacity and store entries into the new larger hash table.

The `rehash()` function first copies all entries into a vector (line 296), doubles the capacity (line 297), deletes the current hash table (line 298), creates a new hash table (line 299), and resets the size to `0` (line 300). The function then copies the entries into the new hash table (lines 302–303). The `rehash` function takes _O_(_capacity_) time. If no rehash is performed, the `put` function takes _O_(1) time to add a new entry.

The `get(key)` function returns the value of the first entry with the specified key (lines 141–151). This function takes _O_(1) time. This function invokes `hashCode(key)` (line 144), which returns the hash code for the key.

The `hash()` function invokes the `supplementalHash` to ensure that the hashing is evenly distributed to produce an index for the hash table (lines 269–273). This function takes _O_(1) time.

The `remove(key)` function removes the entry with the specified key in the map (lines 200–217). This function takes _O_(1) time.

The `getSize()` function simply returns the size of the map (lines 306–310). This function takes _O_(1) time.

The `getKeys()` function returns all keys in the map as a set. The function finds the keys from each bucket and adds them to a set (lines 235–239). This function takes _O_(_capacity_) time. For the implementation of this function, see **Programming Exercise 24.10**.

The `getValues()` function returns all values in the map. The function examines each entry from all buckets and adds it to a set (lines 241–245). This function takes _O_(_capacity_) time. For the implementation of this function, see **Programming Exercise 24.11**.

The `clear` function removes all entries from the map (lines 219–224). It invokes `removeEntries()`, which deletes all entries in the buckets (line 223). The `removeEntries()` function (lines 226–233) takes _O_(_capacity_) time to clear all entries in the table.

The `containsKey(key)` function checks whether the specified key is in the map by invoking the `get` function (lines 173–185). Since the `get` function takes _O_(1) time, the `containsKey(key)` function takes _O_(1) time.

The `containsValue(value)` function checks whether the value is in the map (lines 187–198). This function takes _O(capacity + size)_. It is actually _O_(_capacity_), since capacity > size.

The `getEntries()` function returns a vector that contains all entries in the map (lines 159–171). This function takes _O_(_capacity_) time.

The `isEmpty()` function simply returns true if the map is empty (lines 153–157). This function takes _O_(1) time.

**Table 24.1** summarizes the time complexities of the functions in `MyMap`.

#### Table 24.1

#### **Time Complexities for Functions in MyMap**

|**Functions**|**Time**|
|---|---|
|`clear()`|_O(capacity)_|
|`containsKey(key: Key)`|_O_(1)|
|`containsValue(value: V)`|_O(capacity)_|
|`getEntries()`|_O(capacity)_|
|`get(key: K)`|_O_(1)|
|`isEmpty()`|_O_(1)|
|`getKeys()`|_O(capacity)_|
|`put(key: K, value: V)`|_O_(1)|
|`remove(key: K)`|_O_(1)|
|`getSize()`|_O_(1)|
|`getValues()`|_O(capacity)_|
|`rehash()`|_O(capacity)_|

Since rehashing does not happen very often, the time complexity for the `put` function is _O_(1). Note that the complexities of the `clear`, `getEntries`, `getKeys`, `getValues`, and `rehash` functions depend on `capacity`, so to avoid poor performance for these functions you should choose an initial capacity carefully.

**LiveExample 24.2** gives a test program that uses `MyMap`.

## **LiveExample 24.2 TestMyMap.cpp**
```cpp
#include <iostream>
#include <string>
#include "MyMap.h"
using namespace std;

int main()
{ 
  // Create a map
  MyMap<string, int> map;
  map.put("Smith", 30);
  map.put("Anderson", 31);
  map.put("Lewis", 29);
  map.put("Cook", 29);
  map.put("Smith", 65); // Add ("smith", 65) to the map

  cout << "Entries in map: " << map.toString() << endl;
  cout << "The age for " << "Lewis is " <<
    map.get("Lewis") << endl;
  cout << "Is Smith in the map? " <<
    (map.containsKey("Smith") ? "true" : "false") << endl;
  cout << "Is age 33 in the map? " << 
    (map.containsValue(33) ? "true" : "false") << endl;

  map.remove("Smith"); // Remove the entry with key Smith
  cout << "Entries in map: " << map.toString() << endl;

  map.clear(); // Clear the map
  cout << "Entries in map: " << map.toString() << endl;

  return 0;
}
```
```
command>cl TestMyMap.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestMyMap 
Entries in map: [[Smith, 65][Anderson, 31][Lewis, 29][Cook, 29]]
The age for Lewis is 29
Is Smith in the map? true
Is age 33 in the map? false
Entries in map: [[Anderson, 31][Lewis, 29][Cook, 29]]
Entries in map: []

command>
```

The program creates a map using `MyMap` (line 9) and adds five entries into the map (lines 10–14). Line 10 adds key `Smith` with value `30` and line 14 adds `Smith` with value `65`. The latter value replaces the former value. The map actually has only four entries. The program displays the entries in the map (line 16), gets a value for a key (line 18), checks whether the map contains the key (line 20) and a value (line 22), removes an entry with the key `Smith` (line 24), and redisplays the entries in the map (line 25). Finally, the program clears the map (line 27) and displays an empty map (line 28).

## Self-Check
### What is 1 << 30 in line 8 in LiveExample 24.2? What are the integers resulted from 1 << 1, 1 << 2, and 1 << 3?
$2^{30}$
$2^1$
$2^2$
$2^3$

### What are the integers resulted from 32 >> 1, 32 >> 2, 32 >> 3, and 32 >> 4?
32 >> 1 is 16  
32 >> 2 is 8  
32 >> 3 is 4  
32 >> 4 is 2

### In LiveExample 24.1, will the program work if vector is replaced by list?
Yes.  
The second part of this question: return get(key) != null

### Describe how the put(key, value) function is implemented in the MyHashMap class.

See the text.

### Show the output of the following code.
    MyMap<String, String> map;
    map.put("Texas", "Dallas");
    map.put("Oklahoma", "Norman");
    map.put("Texas", "Austin");
    map.put("Oklahoma", "Tulsa");
    cout << map.get("Texas")) << endl;
    cout << map.size() << endl;

Austin  
2
### If x is a negative int value, will x & (capacity - 1) be negative?
capacity is a 32-bit int value. Since the maximum capacity for the hash table is 230 (line 8 in MyMap.cpp), the first bit in capacity is 0. Thus, the first bit in the result of x & (capacity - 1) is 0. Therefore, x & (capacity - 1) is positive, even though x is negative.
# References
