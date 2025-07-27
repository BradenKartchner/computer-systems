#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void print_str(char* myString, unsigned int len) {
    show_bytes(myString, len);
}

int main() {

    char stringToTest[6] = "abcdef";
    print_str(stringToTest, strlen(stringToTest));

    return 0;
}