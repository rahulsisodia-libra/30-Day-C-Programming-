// Write a program to Move zeroes to end.


#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int count = 0; // Index to place next non-zero element

    // Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    // Fill remaining positions with zeroes
    while (count < n) {
        arr[count++] = 0;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 0, 3, 12, 0, 5, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    printArray(arr, n);

    moveZeroesToEnd(arr, n);

    printf("After:  ");
    printArray(arr, n);

    return 0;
}
