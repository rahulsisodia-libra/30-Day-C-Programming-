// Write a program to Find pair with given sum.


#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Find all pairs with the given sum using two-pointer technique
// Time: O(n log n), Space: O(1)
void findPairsWithSum(int arr[], int n, int target) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int found = 0;

    printf("Pairs with sum %d:\n", target);

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            printf("(%d, %d)\n", arr[left], arr[right]);
            found = 1;
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    if (!found) {
        printf("No pairs found.\n");
    }
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Array must have at least 2 elements.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    findPairsWithSum(arr, n, target);

    free(arr);
    return 0;
}
