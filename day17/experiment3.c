// Write a program to Intersection of arrays.



#include <stdio.h>

// Function to find intersection of two arrays
void findIntersection(int arr1[], int n1, int arr2[], int n2) {
    printf("Intersection: ");
    int found = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                // Check for duplicates in result
                int isDuplicate = 0;
                for (int k = 0; k < i; k++) {
                    if (arr1[k] == arr1[i]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    printf("%d ", arr1[i]);
                    found = 1;
                }
                break;
            }
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    findIntersection(arr1, n1, arr2, n2);

    return 0;
}
