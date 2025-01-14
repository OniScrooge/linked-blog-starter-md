# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 24.5 Handling collisions using separate chaining]]

Next - [[COSC Chapter 24.7 Implementing a Map using Hashing]]
# Content
## Key Point
The **load factor** measures how full a hash table is. If the load factor is exceeded, increase the hash-table size and reload the entries into the new larger hash table. This is called **rehashing**.

[[Load factor]] _λ_ (_lambda_) measures how full a hash table is. It is the ratio of the number of elements to the size of the hash table, that is, $λ=\frac{n}{N}$, where _n_ denotes the number of elements and _N_ the number of locations in the hash table.

Note that _λ_ is zero if the map is empty. For the open addressing scheme, _λ_ is between `0` and `1`; _λ_ is `1` if the hash table is full. For the separate chaining scheme, _λ_ can be any value. As _λ_ increases, the probability of a collision increases. Studies show that you should maintain the load factor under `0.5` for the open addressing scheme and under `0.9` for the separate chaining scheme.

Keeping the load factor under a certain threshold is important for the performance of hashing. Whenever the load factor exceeds the threshold, you need to increase the hash-table size and [[rehash]] all the entries in the map into the new larger hash table. Notice that you need to change the hash functions, since the hash-table size has been changed. To reduce the likelihood of rehashing, since it is costly, you should at least double the hash-table size. Even with periodic rehashing, hashing is an efficient implementation for map.
## Self-Check
### What is load factor? Assume the hash table has the initial size 4 and its load factor is 0.5; show the hash table after inserting entries with the keys 34, 29, 53, 44, 120, 39, 45, and 40, using linear probing.
Load factor is the ratio between the number of elements in the hash table and the hash table size. It measures how full in the hash table. The other part is omitted. Use the animation https://liveexample.pearsoncmg.com/dsanimation/LinearProbingeBook.html to verify your anwser. To start, click the Remove All button to empty the hash table and set the load factor threshhold to 0.5.
# References
