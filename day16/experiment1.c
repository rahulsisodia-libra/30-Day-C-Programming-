// Write a program to Find missing number in array.


#include <stdio.h>


int findMissingNumber(int arr[], int n) {
    // Expected sum of numbers from 1 to n
    int expectedSum = n * (n + 1) / 2;

    // Actual sum of elements in the array
    int actualSum = 0;
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n - 1];
    printf("Enter %d elements (one number from 1 to %d is missing):\n", n - 1, n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missing);

    return 0;
}
