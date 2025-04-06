# Summary
- Computers store data in the form of _bits_, _bytes_, and _words_ using the binary numbering system.
- Hexadecimal numbers are formed using four-bit groups called _nibbles_.
- Signed integers can be stored in one's complement, two's complement, or signed magnitude representation.
- Floating-point numbers are usually coded using _IEEE 754_ floating-point standard.
- Floating-point operations are not necessarily commutative or distributive.
- Character data is stored using _ASCII_, _EBCDIC_, or _Unicode_.
- Error detecting and correcting codes are necessary because we can expect no transmission or storage medium to be perfect
- _CRC_, _Reed-Solomon_, and _Hamming_ codes are three important error control codes
# Learning Objectives
- Understand the fundamentals of numerical data representation and manipulation in digital computers.
- Master the skill of converting between various radix systems.
- Understand how errors can occur in computation because of overflow and truncation.
- Understand the fundamental concepts of floating-point representation.
- Gain familiarity with the most popular character codes.
- Understand the concepts of error detecting and correcting codes.
# Related
Prev - [[Computer Organization - Chapter 1]]

Next - 
# Content
- __Bit__ - The most basic unit of information in a computer.
	- Is either 'On' or 'Off', binary.
	- Sometimes can be addressed as 'High' and 'Low' instead
- __Byte__ - Group of _8_ bits
	- The smallest possible _addressable_ unit of computer storage
	- __Addressable__ - A particular byte can be retrieved according to its location in memory

- __Word__ - Contiguous group of bytes
	- Can be any number of bits or bytes.
	- Most common sizes: 16, 32, 64
	- Smallest addressable unit of storage in a word-addressable system
- __Nibble__ - A group of four bits
	- _Bytes_ consist of 2 nibbles, the "high-order" and "low-order"
- The binary system
	- Stores numbers using the position to represent a power of _2_.
		- Binary system also referred to as _base-2_ system
		- Our decimal system is the _base-10_ system, since it uses power of _10_.
	- Decimal of 947 in powers of 10
		- $9\times 10^2+4\times 10^1+7\times 10^0$
	- Decimal of 5836.47 in powers of 10
		- $5\times 10^3+8\times 10^2+3\times 10^1+6\times 10^0+4\times 10^{-1}+7\times10^{-2}$
	- Binary of 11001 in powers of 2
		- $1*2^4+1*2^3+0*2^2+0*2^1+1*2^0=16+8+0+0+1=25$
- Converting between bases
	- $538_{10}\to 8$
	- $538-512=8^3*1$
	- $26-0=8^2*0$
	- $26-24=8^1*3$
	- $2-2=8^0*2$
	- __Conclusion__ $538_{10}=1032_{8}$
- Converting decimal to binary
	- $0.8125_{10}$
	- $0.8125-0.5000=2^{-1}*1$
	- $0.3125-0.2500=2^{-2}*1$
	- $0.0625-0.0000=2^{-4}*0$
	- $0.0625-0.0625=2^{-4}*1$
	- __Conclusion__ $0.8125_{10}=0.1101_{2}$
- Hamming Codes - Code words formed by adding redundant check bits, or parity bits, to a data word.
	- __Hamming distance__ - Number of bits in which two code words differ
	- Minimum hamming distance for a code is the smallest distance between all pairs of words in the code
	- To detect _k_ single-bit error, the hamming distance must be $D(min)=k+1$
	- Hamming codes can detect $\frac{D(min)-1}{2}$ errors
	- A distance of $2k+1$ is required to correct _k_ errors in any data word


# References
