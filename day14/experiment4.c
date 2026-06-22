// Write a program to Find duplicates in array.
 

#include <stdio.h>
#include <stdlib.h>


/* Find and print duplicate elements in an array using a hash-based approach.
 * Time complexity: O(n), Space complexity: O(n)
 */
void findDuplicates(int arr[], int n) {
    if (n <= 0) {
        printf("Array is empty.\n");
        return;
    }

    /* Find the max value to size the frequency table */
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int *freq = (int *)calloc(range, sizeof(int));
    if (!freq) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    /* Count occurrences of each element */
    for (int i = 0; i < n; i++) {
        freq[arr[i] - min]++;
    }

    /* Report duplicates */
    int found = 0;
    printf("Duplicate elements in the array:\n");
    for (int i = 0; i < range; i++) {
        if (freq[i] > 1) {
            printf("  %d (appears %d times)\n", i + min, freq[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("  No duplicates found.\n");
    }

    free(freq);
}

int main(void) {
    int arr[] = {4, 2, 7, 1, 2, 6, 4, 3, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n\n");

    findDuplicates(arr, n);

    return 0;
}
