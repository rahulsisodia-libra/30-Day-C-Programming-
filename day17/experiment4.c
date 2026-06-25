// Write a program to Find common elements.


#include <stdio.h>

void findCommonElements(int arr1[], int n1, int arr2[], int n2) {
    printf("Common elements: ");
    int found = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                found = 1;
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
    int n1, n2;

    printf("Enter the number of elements in first array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter elements of first array:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in second array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter elements of second array:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    findCommonElements(arr1, n1, arr2, n2);

    return 0;
}
