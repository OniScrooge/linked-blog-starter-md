# Related
Prev - [[COSC Chapter 24.8 Implementing set using hashing]]

Next - [[COSC Chapter 25 AVL Trees]]
# Key Terms
1. **​associative array**
2. **cluster**
3. **dictionary**
4. **double hashing**
5. **hash code**
6. **hash function**
7. **hash map**
8. **hash set**
9. **hash table**
10. **linear probing**
11. **load factor**
12. **open addressing**
13. **perfect hash function**
14. **polynomial hash code**
15. **quadratic probing**
16. **rehashing**
17. **secondary clustering**
18. **separate chaining​**
# Chapter Summary
1. A _map_ is a data structure that stores entries. Each entry contains two parts: a _key_ and a _value_. The key is also called a _search key_, which is used to search for the corresponding value. You can implement a map to obtain _O_(1) time complexity on searching, retrieval, insertion, and deletion using the hashing technique.
2. A _set_ is a data structure that stores elements. You can use the hashing technique to implement a set to achieve _O_(1) time complexity on searching, insertion, and deletion for a set.
3. _Hashing_ is a technique that retrieves the value using the index obtained from a key without performing a search. A typical _hash function_ first converts a search key to an integer value called a _hash code_, then compresses the hash code into an index to the _hash table_.
4. A _collision_ occurs when two keys are mapped to the same index in a hash table. Generally, there are two ways for handling collisions: _open addressing_ and _separate chaining_.
5. Open addressing is the process of finding an open location in the hash table in the event of collision. Open addressing has several variations: _linear probing_, _quadratic probing_, and _double hashing_.
6. The _separate chaining_ scheme places all entries with the same hash index into the same location, rather than finding new locations. Each location in the separate chaining scheme is called a _bucket_. A bucket is a container that holds multiple entries.
