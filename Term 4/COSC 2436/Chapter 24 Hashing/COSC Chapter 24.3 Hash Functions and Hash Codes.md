# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 24.2 What is Hashing]]

Next - [[COSC Chapter 24.4 Handling Collisions using open addressing]]
# Content
## Key Point

A typical hash function first converts a search key to an integer value called a hash code, then compresses the hash code into an index to the hash table.

In C++11, you can use `hash``<``KeyType``>``()(key)` to return an unsigned integer [[hash code]] for an element of a primitive type or an object type depending on the type and value of the element. For example, `hash``<``string``>``()("abc")` returns the hash code for string `"abc"` and `hash``<``int``>``()(454)` returns the hash code for `454`. The contract for the hash function is as follows:
1. The function returns the same hash code if the two elements are equal.
2. During the execution of a program, invoking the hash function multiple times returns the same integer, provided that the object’s data are not changed.
3. Two unequal objects may have the same hash code, but the function in C++11 is to avoid too many such cases.

The following sections discuss the possible implementation of the hash code for numbers and strings.

## 24.3.1 Hash Codes for Primitive Types

For search keys of the type `short,` `int`, and `char`, simply cast them to `int`. Therefore, two different search keys of any one of these types will have different hash codes.

For a search key of the type `float`, use `floatToIntBits(key)` as the hash code, where `floatToIntBits(float f)` returns an `int` value whose bit representation is the same as the bit representation for the floating number `f`. Thus, two different search keys of the `float` type will have different hash codes. See **Programming Exercise 24.6** for the implementation of `floatToIntBits`.

For a search key of the type `long long` (`long long` is 64 bits in C++11), simply casting it to `int` would not be a good choice, because all keys that differ in only the first 32 bits will have the same hash code. To take the first 32 bits into consideration, divide the 64 bits into two halves and perform the exclusive-or operation to combine the two halves. This process is called _folding_. The hash code for a `long long` key is
```cpp
int hashCode = static_cast<int>(key ^ (key >> 32)); 
```

Note that `>>` is the right-shift operator that shifts the bits 32 positions to the right. For example, `1010110 >> 2` yields `0010101`. The `^` is the bitwise exclusive-or operator. It operates on two corresponding bits of the binary operands. For example, `1010110 ^ 0110111` yields `1100001`. For more on bitwise operations, see **Appendix E**, Bitwise Operations.

For a search key of the type `double`, first convert it to a `long long` value using the `doubleToLongLongBits` function, and then perform a folding as follows:
```cpp
long long bits = *reinterpret_cast<long long*>(&key); 
int hashCode = static_cast<int>(bits ^ (bits >> 32)); 
```

Note that `reinterprete_cast` was introduced in **Section 13.7**.

## 24.3.2 Hash Codes for Strings

Search keys are often strings, so it is important to design a good hash function for strings. An intuitive approach is to sum the numeric code of all characters as the hash code for the string. This approach may work if two search keys in an application don’t contain the same letters, but it will produce a lot of collisions if the search keys contain the same letters, such as `tod` and `dot`.

A better approach is to generate a hash code that takes the position of characters into consideration. Specifically, let the hash code be

$s0×b(n−1)+s1×b(n−2) +…+sn−1$

where _si_ is `s[i]`. This expression is a polynomial for some positive _b_, so this is called a [[polynomial hash code]]. Using Horner’s rule for polynomial evaluation (see **Section 6.14**), the hash code can be calculated efficiently as follows:

$$(… ((s_{0}*b+s_{1})*b+s_{2})*b+…+s_{n−2})*b+s_{n−1}$$

This computation can cause an overflow for long strings, but arithmetic overflow is ignored in C++. You should choose an appropriate value _b_ to minimize collisions. Experiments show that good choices for _b_ are 31, 33, 37, 39, and 41.

## 24.3.3 Compressing Hash Codes

The hash code for a key can be a large integer that is out of the range for the hash-table index, so you need to scale it down to fit in the index’s range. Assume the index for a hash table is between `0` and `N-1`. The most common way to scale an integer to between `0` and `N-1` is to use
```cpp
h(hashCode) = hashCode % N 
```

Ideally, you should choose a prime number for `N` to ensure that the indices are spread evenly. However, it is time consuming to find a large prime number. We will choose `N` to be a value of the power of `2`. There is a good reason for this choice. When `N` is a value of the power of `2`,
```cpp
h(hashCode) = hashCode % N 
```

is the same as
```cpp
h(hashCode) = hashCode & (N – 1) 
```

The ampersand, `&`, is a bitwise AND operator (see **Appendix E**, Bitwise Operations). The AND of two corresponding bits yields a `1` if both bits are `1`. For example, assume `N = 4` and `hashCode = 11`, `11 % 4 = 3`, which is the same as `01011 & 00011 = 11`. The & operator can be performed much faster than the `%` operator.

To ensure that the hashing is evenly distributed, a supplemental hash function is also used along with the primary hash function. The supplemental function may be defined as:
```cpp
int supplementalHash(int h) 
{ 
  h ^= (h >> 20) ^ (h >> 12); 
  return h ^ (h >> 7) ^ (h >> 4); 
} 
```

`^` and `>>` are bitwise exclusive-or and unsigned right-shift operations (also introduced in **Appendix E**). The bitwise operations are much faster than the multiplication, division, and remainder operations. You should replace these operations with the bitwise operations whenever possible.

The complete hash function is defined as:
```cpp
h(hashCode) = supplementalHash(hashCode) % N 
```

This is the same as
```cpp
h(hashCode) = supplementalHash(hashCode) & (N – 1) 
```

since `N` is a value of the power of `2`.

## Self-Check
### What is a hash code? What is the hash code for short, int, and char?
A hash code is a number generated from an object. This code allows an object to be stored/retrieved quickly in a hash table.  
For a search key of the type short, int, and char, simply cast it to int. So two different search keys of any one of these types will have different hash codes.
### How is the hash code for a float value computed
For a search key of the type float, use `floatToIntBits(key)` as the hash code. Note that `floatToIntBits(float f)` returns an `int` value whose bit representation is the same as the bit representation for the floating number f. So, two different search keys of the float type will have different hash codes. For the implementation of `floatToIntBits(float f)`, see Programming Exercise 24.6.
### How is the hash code for a long long value computed?
For a search key of the type long, simply casting it to `int` would not be a good choice, because all keys that differ in only the first 32 bits will have the hash code. To take the first 32 bits into consideration, divide the 64 bits into two halves and perform the exclusive or operator to combine the two halves. This process is called folding. So, the hashing code is
```cpp
int hashCode = static_cast<int>(key ^ (key >> 32));
```
Note that >> is the right-shift operator that shifts the bits 32 position to the right.
### How is the hash code for a double value computed?
For a search key of the type double, first convert it to a long value using `doubleToLongBits`, then perform a folding as follows:
```cpp
long bits = doubleToLongBits(key);
int hashCode = static_cast<int>(bits ^ (bits >> 32));
```
For the implementation of `doubleToIntBits(float f)`, see Programming Exercise 24.7.
### How is the hash code for a string object computed?
The hashcode for a string is
$$(...((s_{0}*b + s_{1})b + s_{2})b+...+s_{n-2})b+ s_{n-1}$$
where b is 2.
### How is a hash code compressed to an integer representing the index in a hash table?
The hash code for a key can be a large integer that is out of the range for the hash table index. You need to scale it down to fit in the range of the index. Assume the index for a hash table is between 0 and N-1. The most common way to scale an integer to between 0 and N-1 is to use
```cpp
h(hashCode) = hashCode % N
```
To ensure that the indices are spread evenly, choose N to be a prime number greater than 2.
### If N is a value of the power of 2, is N / 2 same as N >> 1?
Yes.
### If N is a value of the power of 2, is m % N same as m & (N - 1) for any integer m?
Yes.
# References
