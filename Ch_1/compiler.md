## Intro to C compilers

The code in a C file has to be translated into low-level machine-language instructions before it can be run. The instructions are packaged into an **executable object program** and stored as a binary disk file.
executable object program == executable object file

Example flow:
hello.c ---> hello.i ---> hello.s ---> hello.o + other object files ---> hello (executable)  

Example flow with each program that does each translation step
hello.c ---> Pre-processor ---> hello.i ---> Compiler --> hello.s ---> Assembler ---> hello.o, hello.o + other object files ---> Linker ---> hello

*.c = Source program (text)
*.i = Modified source program (text)
*.s = Assembly program (text)
*.o = Relocatable object program (binary)
no suffix = executable