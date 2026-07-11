//  Write a program to Create menu-driven array operations system.


#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    int pos, val;
    printf("Enter position (0 to %d): ", *size);
    scanf("%d", &pos);
    if (pos < 0 || pos > *size) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*size)++;
    printf("Element %d inserted at position %d.\n", val, pos);
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    int pos;
    printf("Enter position to delete (0 to %d): ", *size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= *size) {
        printf("Invalid position.\n");
        return;
    }
    printf("Deleted element: %d\n", arr[pos]);
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void searchElement(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int val;
    printf("Enter value to search: ");
    scanf("%d", &val);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            printf("Element %d found at position %d.\n", val, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", val);
    }
}

void sortArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    // Bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

void reverseArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int left = 0, right = size - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    printf("Array reversed.\n");
}

void findMinMax(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
}

void computeSum(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Sum of elements: %lld\n", sum);
    printf("Average of elements: %.2f\n", (double)sum / size);
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    printf("=== Menu-Driven Array Operations System ===\n");

    do {
        printf("\n--- MENU ---\n");
        printf("1. Input array elements\n");
        printf("2. Display array\n");
        printf("3. Insert element\n");
        printf("4. Delete element\n");
        printf("5. Search element\n");
        printf("6. Sort array (Ascending)\n");
        printf("7. Reverse array\n");
        printf("8. Find Min and Max\n");
        printf("9. Compute Sum and Average\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter number of elements (max %d): ", MAX_SIZE);
                int n;
                scanf("%d", &n);
                if (n < 0 || n > MAX_SIZE) {
                    printf("Invalid size.\n");
                    break;
                }
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("Element[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                size = n;
                printf("Array of %d elements loaded.\n", size);
                break;
            }
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                sortArray(arr, size);
                break;
            case 7:
                reverseArray(arr, size);
                break;
            case 8:
                findMinMax(arr, size);
                break;
            case 9:
                computeSum(arr, size);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
