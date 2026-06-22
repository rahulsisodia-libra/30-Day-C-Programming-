//   Write a program to Rotate array right.


#include <stdio.h>

void rotateRight(int arr[], int n, int k) {
    // Handle cases where k > n
    k = k % n;
    if (k == 0) return;

    // Temporary array to store last k elements
    int temp[k];

    // Store last k elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy stored elements to the beginning
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Number of positions to rotate right

    printf("Original array:  ");
    printArray(arr, n);

    rotateRight(arr, n, k);

    printf("Rotated right by %d: ", k);
    printArray(arr, n);

    return 0;
}
