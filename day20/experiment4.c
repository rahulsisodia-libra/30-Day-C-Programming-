// Write a program to Find column-wise sum.


#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    int colSum[COLS] = {0};

    printf("Enter elements of %dx%d matrix:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate column-wise sum
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            colSum[j] += matrix[i][j];
        }
    }

    printf("\nColumn-wise sums:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Sum of column %d = %d\n", j + 1, colSum[j]);
    }

    return 0;
}
