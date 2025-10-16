#include <stdio.h>

// see practice problem 2.10 (pg 54)
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y; // step 1
    *x = *x ^ *y; // step 2
    *y = *x ^ *y; // step 3
}

int main() {

    int a = 5;
    int b = 8;

    int *ptr_a = &a;
    int *ptr_b = &b;

    inplace_swap(ptr_a, ptr_b);

    printf("value of a: %d, value of b: %d\n", a, b);

    return 0;
}