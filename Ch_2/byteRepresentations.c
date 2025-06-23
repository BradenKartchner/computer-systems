#include <stdio.h>

// unsigned char has a length of 1 byte
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        // print in hexadecimal with at least 2 digits
        // array addressing an unsigned char? this seems evil...
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    // cast the int as type byte_pointer
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_ptr(void* x) {
    // why not use int* here?
    // I guess just to keep this function working with any pointer?
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main() {

    int testInt = 12345;
    float testFloat = 3.14159;
    int *pointVal = &testInt;

    show_int(testInt);
    show_float(testFloat);

    return 0;
}