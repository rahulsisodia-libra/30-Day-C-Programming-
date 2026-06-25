// Write a program to Union of arrays.


#include <stdio.h>

// Function to check if element exists in array
int contains(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element)
            return 1;
    }
    return 0;
}

// Function to compute union of two arrays
int unionArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int idx = 0;

    // Add all elements from arr1
    for (int i = 0; i < n1; i++) {
        if (!contains(result, idx, arr1[i])) {
            result[idx++] = arr1[i];
        }
    }

    // Add elements from arr2 that are not already in result
    for (int i = 0; i < n2; i++) {
        if (!contains(result, idx, arr2[i])) {
            result[idx++] = arr2[i];
        }
    }

    return idx; // size of union
}

int main() {
    int n1, n2;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements of first array:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements of second array:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int result[n1 + n2];
    int unionSize = unionArrays(arr1, n1, arr2, n2, result);

    printf("Union of the two arrays:\n");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
