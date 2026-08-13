#include <stdio.h>

// Call by Value
void callByValue(int x) {
    x = x + 10;
    printf("Inside Call by Value: %d\n", x);
}

// Call by Reference
void callByReference(int *x) {
    *x = *x + 10;
    printf("Inside Call by Reference: %d\n", *x);
}

int main() {
    int a = 10, b = 10;

    printf("Before Call by Value: %d\n", a);
    callByValue(a);
    printf("After Call by Value: %d\n\n", a);

    printf("Before Call by Reference: %d\n", b);
    callByReference(&b);
    printf("After Call by Reference: %d\n", b);

    return 0;
}