#include <stdio.h>

// unsigned char has a length of 1 byte
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    // cast the int as type byte_pointer
    show_bytes((byte_pointer) &x, sizeof(int));
}

int main() {

    int testInt = 12345;
    float testFloat = 3.14159;
    int *pointVal = &testInt;

    show_int(testInt);

    return 0;
}