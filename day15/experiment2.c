//  Write a program to Rotate array left.


#include <stdio.h>

void rotateLeft(int arr[], int n, int d) {
    // Normalize d in case it's larger than array size
    d = d % n;
    
    int temp[d];
    
    // Store first d elements in temp
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    
    // Shift remaining elements to the left
    for (int i = 0; i < n - d; i++) {
        arr[i] = arr[i + d];
    }
    
    // Copy temp elements to the end
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
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
    int d = 2; // Number of positions to rotate left

    printf("Original array:  ");
    printArray(arr, n);

    rotateLeft(arr, n, d);

    printf("After rotating left by %d: ", d);
    printArray(arr, n);

    return 0;
}
