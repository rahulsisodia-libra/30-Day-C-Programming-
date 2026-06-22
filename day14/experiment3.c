// Write a program to Second largest element.

#include <stdio.h>

int secondLargest(int arr[], int n) {
    if (n < 2) {
        return -1; // Not enough elements
    }

    int first = -__INT_MAX__, second = -__INT_MAX__;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return (second == -__INT_MAX__) ? -1 : second;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least 2 elements are required.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = secondLargest(arr, n);
    if (result == -1) {
        printf("No second largest element found (all elements may be equal).\n");
    } else {
        printf("Second largest element: %d\n", result);
    }

    return 0;
}
