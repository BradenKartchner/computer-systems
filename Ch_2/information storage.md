## Memory

Most computers use the byte (8 bits) as the smallest addressable unit of memory. You can't address smaller than a byte

A machine-level program views memory as a very large array of bytes (virtual memory). Each byte of memory is identified by a unique number, known as its **address**.
The set of all possibly addresses known to the program is known as the **virtual address space**. The actual implementation uses a combination of DRAM, flash memory, disk storage, special hardware, and OS software to provide the program with what appears to be a monolithic byte array.

The value of a pointer in C is the virtual address of the first byte of some block of storage. Each pointer also has type information associated with it, so the compiler can generate different machine-level code to access the value(s) stored at the location.The compiler has information about data types, but the machine-level program it generates has no information about data types. The program treats each program object as a block of bytes and the program itself as a sequence of bytes.

## Versions of C

| C version | GCC command-line option |
| ---------- | ------------------- |
| GNU 89 | none, `-std=gnu89` |
| ANSI, ISO C90 | `-ansi` , `-std=c89` |
| ISO C99 | `-std=c99` |
| ISO C11 | `-std=c11` |

## Representing Bytes

A byte is 8 bits
00000000 to 11111111
Decimal: 0 to 255
Hexadecimal: 00 to FF
In C, hexadecimal representations start with `0x`
`0x00 to 0xFF`
Upper or lower case letters

example conversions:
1010b to hex: 0xA
1011b to hex: 0xB
1100b to hex: 0xC
1101b to hex: 0xD
1110b to hex: 0xE
1111b to hex: 0xF

For longer than 4 bits, split up into groups of 4
00111010b to hex: 0011 is 3, 1010 is A, so 0x3A

## Data sizes

Every computer has a **word size**, which indicates the normal size of pointer data.
Word size determines the maximum size of the virtual address space.
For a machine with x-bit word size, the virtual addresses can range from 0 to 2^x - 1, giving the program access to at most 2^x bytes.
Slightly older computers had 32-bit word size, which limits virtual address space to ~4 GB. That's why most machines have been shifting to 64-bit architecture.
64-bit word size can have virtual address space of 16 exabytes, ~1.84 x 10^19 bytes.

`getconf WORD_BIT`: CLI output word bit size

As a form of backwards compatibility, most 64-bit machines can run programs compiled for use on 32-bit machines.
GCC can compile directly for 32-bit:
`gcc -m32 prog.c`
GCC can also compile directly for 64-bit:
`gcc -m64 prog.c`

## C lang data formats

| C declaration | | Bytes | |
| ----- | --- | --- | --- |
| **Signed** | **Unsigned** | **32-bit** | **64-bit** |
| [signed] char | unsigned char | 1 | 1 | 
| short | unsigned short | 2 | 2 |
| int | unsigned | 4 | 4 |
| long | unsigned long | 4 | 8 |
| int32_t | uint32_t | 4 | 4 |
| int64_t | uint64_t | 8 | 8 |
| char * | | 4 | 8 |
| float | | 4 | 4 |
| double | | 8 | 8 |

So the only differences are `char *` and `long`??

int vs uint32_t:  
int can change how long it is based on the architecture and OS. It is used when bit width is not critical.
uint32_t is always 32 bits long. It ensures consistent behavior across OS and platform.

ISO C99 introduced int32_t, uint32_t, etc..

## Byte ordering (endianness)

Example:
Suppose the variable `x` of type `int` starts at address `0x100` and has a hexadecimal value of `0x01234567`.
Split into Bytes: `01` `23` `45` `67`
Little endian: means that least significant byte comes first.
Memory map for little endian:
`0x100`: `67`
`0x101`: `45`
`0x102`: `23`
`0x103`: `01`
So each byte is at its own memory address, and the least significant byte comes first.

Big endian: means that most significant byte comes first.
Memory map for big endian:
`0x100`: `01`
`0x101`: `23`
`0x102`: `45`
`0x103`: `67`

Most intel-compatible machines operate exclusively in little-endian mode. Many recent microprocessor chips are bi-endian, meaning they can be configured to run in either mode. Once an OS is chosen, the byte ordering becomes fixed.
Which convention doesn't matter, the choice is arbitrary.  

Code written for networking applications needs to adhere to a standard so that there isn't a miscommunication between big and little endian machines.

**Warning:**
When casting data as a different type than it was originally defined as, the byte order matters. Cross-platform applications shouldn't use casting tricks. Platform specific applications like OS's can use casting, but still need to be careful.

## Compatibility of binary files

Binary files are almost never compatible between devices
Only the exact same processor running the exact same OS will be compatible
Even the same processor across different OS will have different binary files

# Intro to Boolean algebra

** note: using the C bit-level operators for logic
~ = NOT
~
----
0   1
1   0

& = AND
&    0  1
---------
0    0  0
1    0  1

| = OR
|    0  1
---------
0    0  1
1    1  1

^ = EXCLUSIVE-OR (ONLY 1 is true, not both)
^    0  1
---------
0    0  1
1    1  0

Example of bit-level comparisons:
  0110
& 1100
-------
  0100