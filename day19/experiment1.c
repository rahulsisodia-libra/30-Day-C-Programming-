// Write a program to Add matrices.


#include <stdio.h>ss

#define ROWS 3
#define COLS 3

void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[ROWS][COLS], b[ROWS][COLS], result[ROWS][COLS];

    printf("Enter elements of first matrix (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &b[i][j]);

    addMatrices(a, b, result);

    printf("\nFirst Matrix:\n");
    printMatrix(a);

    printf("\nSecond Matrix:\n");
    printMatrix(b);

    printf("\nSum of Matrices:\n");
    printMatrix(result);

    return 0;
}
