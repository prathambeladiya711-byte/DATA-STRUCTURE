#include <stdio.h>

int main() {
    int arr[100], n;
    int *ptr;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Point to the last element of the array
    ptr = arr + n - 1;

    // Print array elements in reverse order using pointer
    printf("Array elements in reverse order are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *ptr);
        ptr--;
    }

    return 0;
}