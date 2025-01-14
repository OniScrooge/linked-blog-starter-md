# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 24.1 Introduction]]

Next - [[COSC Chapter 24.3 Hash Functions and Hash Codes]]
# Content
## Key Point
Hashing uses a hashing function to map a key to an index.

Before introducing hashing, let us review map, which is a data structure that is implemented using hashing. Recall that a _map_ (introduced in **Section 22.6**) is a container object that stores entries. Each entry contains two parts: a _key_ and a _value_. The key, also called a _search key_, is used to search for the corresponding value. For example, a dictionary can be stored in a map, in which the words are the keys and the definitions of the words are the values.

>[!Note]
A map is also called a [[dictionary]], a [[hash table]], or an [[associative array]].

The `STL` defines the `map` and `multimap` classes for modeling maps. You will learn the concept of hashing and use it to implement a map in this chapter.

If you know the index of an element in the array, you can retrieve the element using the index in _O_(1) time. So does that mean we can store the values in an array and use the key as the index to find the value? The answer is yes—if you can map a key to an index. The array that stores the values is called a _hash table_. The function that maps a key to an index in the hash table is called a [[hash function]]. As shown in **Figure 24.1**, a hash function obtains an index from a key and uses the index to retrieve the value for the key. _Hashing_ is a technique that retrieves the value using the index obtained from the key without performing a search.

## Figure 24.1
![[r06waazn.bmp]]

How do you design a hash function that produces an index from a key? Ideally, we would like to design a function that maps each search key to a different index in the hash table. Such a function is called a [[perfect hash function]]. However, it is difficult to find a perfect hash function. When two or more keys are mapped to the same index, we say that a _collision_ has occurred. Although there are ways to deal with collisions, which are discussed later in this chapter, it is better to avoid collisions in the first place. Thus, you should design a fast and easy-to-compute hash function that minimizes collisions.

## Self-Check
### What is a hash function? What is a perfect hash function? What is a collision?
If you know the index of an element in the array, you can retrieve the element using the index in $O(1)$ time. So, can we store the values in an array and use the key as the index to find the value? The answer is yes if you can map a key to an index. The array that stores the values is called a hash table. The function that maps a key to an index in the hash table is called a hash function.  
How do you design a hash function that produces an index from a key? Ideally, we would like to design a function that maps each search key to a different index in the hash table. Such a function is called a perfect hash function. However, it is difficult to find a perfect hash function.  
When two or more keys are mapped to the same hash value, we say that a collision has occurred.
# References
