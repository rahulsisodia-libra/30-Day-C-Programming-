// Write a program to Transpose matrix.


#include <stdio.h>

#define MAX 10

void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
        printf("Invalid dimensions. Please enter values between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    transposeMatrix(matrix, transpose, rows, cols);

    printf("\nOriginal Matrix (%d x %d):\n", rows, cols);
    printMatrix(matrix, rows, cols);

    printf("\nTransposed Matrix (%d x %d):\n", cols, rows);
    printMatrix(transpose, cols, rows);

    return 0;
}
