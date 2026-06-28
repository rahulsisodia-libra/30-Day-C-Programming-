// Write a program to Find row-wise sum.


#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int matrix[ROWS][COLS];
    int row_sum;

    printf("Enter elements of the %dx%d matrix:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nRow-wise sum:\n");
    for (int i = 0; i < ROWS; i++) {
        row_sum = 0;
        for (int j = 0; j < COLS; j++) {
            row_sum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, row_sum);
    }

    return 0;
}

