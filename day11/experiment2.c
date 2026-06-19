// Write a program to Write function to find maximum.


#include <stdio.h>

int findMaximum(int arr[], int size) {
    if (size <= 0) {
        return -1; // Handle empty array
    }

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {3, 7, 1, 9, 4, 6, 2, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maximum = findMaximum(arr, size);
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMaximum element: %d\n", maximum);

    return 0;
}
