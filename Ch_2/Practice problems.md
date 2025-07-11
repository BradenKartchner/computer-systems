### Problem 2.3 (pg 38)

Decimal: 167
Hexadecimal:
167 / 16 = 10 * 16 + 7 => remainder 7 (7 in hex)
160 / 16 = 10 => A in hex
0xA7 is the answer
Binary:
1010 0111 (A7)

Binary: 1111 0011 (0b11110011)
Hex: 0xf3
Decimal: 16 * 15 + 3 * 1 = 243


### Practice example problem

Convert the following decimal number to hex:
314156
314156 / 16 = 19634 * 16 + 12 => remainder 12 (C in hex)
19634 / 16 = 1227 * 16 + 2 => remainder 2 (2 in hex)
1227 / 16 = 76 * 16 + 11 => remainder 11 (B in hex)
76 / 16 = 4 * 16 + 12 => remainder 12 (C in hex)
64 / 16 = 4 => 4 in hex
Final answer:
0x4CB2C

### Practice problem 2.4 (pg 39)

a. 0x503c + 0x8 = 0x5030 + 0x14 = 0x5044
b. 0x503c - 0x40

0x503c
0x  40
------

 0x10 (carry 16)
0x4f3c
0x  40
-------
0x4ffc

Zoom in on carry step:
0x13c - 0x40 = 0xfc

### Problem 2.5 (pg 48)

int val = 0x87654321
a. byte 1. Little endian: 21, big endian: 87
b. byte 2. little endian: 43, big endian: 65
c. byte 3. little endian: 65, big endian: 43
* note: while technically correct, I forgot a nuance about the program itself

### Problem 2.6 (pg 49)

int: 3510593
hex: 0x00359141
float: 3510593.0
hex: 0x4a564504

a.
Binary of the int:
0000 0000 0011 0101 1001 0001 0100 0001
0100 1010 0101 0110 0100 0101 0000 0100
(above) Binary of the float
how are floats encoded?

b. shift the binary until a maximum amount of bits match
0011 0101 1001 0001 0100 0001 0000 0000 (shifted 8 right)
0100 1010 0101 0110 0100 0101 0000 0100 (not shifted)
this probably isn't right, would be easier to write program to match bits
take 2:
0000 0000 0011 0101 1001 0001 0100 0001 (not shifted)
1010 0101 0110 0100 0101 0000 0100 0000 (shifted 4 left)
idk. shrug.
solution: shift bottom string 2 bits to the right
0000 0000 0011 0101 1001 0001 0100 0001
  01 0010 1001 0101 1001 0001 0100 0001 00
All of the bits in the int are in the float, except for the very top bit
The float has a few more bits on the top that the int doesn't have