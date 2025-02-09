# Summary
# Learning Objectives
- Know the difference between computer organization and computer architecture.
- Understand units of measure common to computer systems.
- Appreciate the evolution of computers.
- Understand the computer as a layered system.
- Be able to explain the von Neumann architecture and the function of basic computer components.
# Related
Prev - 

Next - 
# Content

- Computer organization
	- Encompasses all physical aspects of computer systems (e.g., circuit design, control signals, memory types).
	- How does a computer work?
- Computer architecture
	- Logical aspects of system implementation as seen by the programmer (e.g., instruction sets, instruction formats, data types, addressing modes).
	- How do I design a computer?
- Measurements of capacity and speed
	- Kilo- (K) = 1 thousand = 103 and 210
	- Mega- (M) = 1 million = 106 and 220
	- Giga- (G) = 1 billion = 109 and 230
	- Tera- (T) = 1 trillion = 1012 and 240
	- Peta- (P) = 1 quadrillion = 1015 and 250
	- Exa- (E) = 1 quintillion = 1018 and 260
	- Zetta- (Z) = 1 sextillion = 1021 and 270
	- Yotta- (Y) = 1 septillion = 1024 and 280
- Hertz
	- Is clock cycles per second (frequency)
	- 1MHz = 1,000,000Hz
	- Processor speeds are measured in MHz or GHz.
- Byte
	- Is a unit of storage
	- 1KB = 210 = 1024 Bytes
	- 1MB = 220 = 1,048,576 Bytes
	- 1GB = 230 = 1,099,511,627,776 Bytes
	- Main memory (RAM) is measured in GB
	- Disk storage is measured in GB for small systems, TB (240) for large systems.
- Measures of time and space
	- Milli- (m) = 1 thousandth = 10-3
	- Micro- ( ) = 1 millionth = 10-6
	- Nano- (n) = 1 billionth = 10-9
	- Pico- (p) = 1 trillionth = 10-12
	- Femto- (f) = 1 quadrillionth = 10-15
	- Atto- (a) = 1 quintillionth = 10-18
	- Zepto- (z) = 1 sextillionth = 10-21
	- Yocto- (y) = 1 septillionth = 10-24
- Millisecond
	- 1 thousandth of a second
	- Hard disk drive access times are often 10 to 20 milliseconds.
- Nanosecond
	- 1 billionth of a second
	- Main memory access times are often 50 to 70 nanoseconds.
- Micron
	- (micrometer) = 1 millionth of a meter
	- Circuits on computer chips are measured in microns.
- Computer levels
	- 6 User level
		- Program execution and user interface level
		- The level with which we are most familiar
	- 5 High level languages
		- The level with which we interact when we write programs in languages such as C, Pascal, Lisp, and Java
	- 4 Assembly level language
		- Acts upon assembly language produced from Level 5, as well as instructions programmed directly at this level
	- 3 System software
		- Controls executing processes on the system
		- Protects system resources
		- Assembly language instructions often pass through Level 3 without modification
	- 2 Machine level
		- Also known as the Instruction Set Architecture (ISA) Level
		- Consists of instructions that are particular to the architecture of the machine
		- Programs written in machine language need no compilers, interpreters, or assemblers
	- 1 Control level
		- A control unit decodes and executes instructions and moves data through the system
		- Control units can be microprogrammed or hardwired
		- A microprogram is a program written in a low-level language that is implemented by the hardware
		- Hardwired control units consist of hardware that directly executes machine instructions
	- 0 Digital logic
		- This level is where we find digital circuits (the chips).
		- Digital circuits consist of gates and wires.
		- These components implement the mathematical logic of all other levels.
- Von Neumann Architecture
	- The invention of this idea has since been ascribed to a mathematician, John von Neumann, who was a contemporary of Mauchley and Eckert.
	- Stored-program computers have become known as von Neumann Architecture systems.
	- Today’s stored-program computers have the following characteristics:  Three hardware systems:
		- A central processing unit (CPU)
		- A main memory system
		- An I/O system
		- The capacity to carry out sequential instruction processing
		- A single data path between the CPU and main memory
		- This single path is known as the von Neumann bottleneck

# References

[[9781284261202_SLID_CH01 - Tagged.pdf]]