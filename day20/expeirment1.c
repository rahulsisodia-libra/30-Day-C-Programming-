// Write a program to Multiply matrices.


#include <stdio.h>

#define MAX 10

void multiplyMatrices(int a[][MAX], int b[][MAX], int result[][MAX], int rowA, int colA, int colB) {
    // Initialize result matrix with zeros
    for (int i = 0; i < rowA; i++)
        for (int j = 0; j < colB; j++)
            result[i][j] = 0;

    // Multiply matrices
    for (int i = 0; i < rowA; i++)
        for (int j = 0; j < colB; j++)
            for (int k = 0; k < colA; k++)
                result[i][j] += a[i][k] * b[k][j];
}

void printMatrix(int matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rowA, colA, rowB, colB;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &rowA, &colA);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &rowB, &colB);

    // Multiplication is only possible if colA == rowB
    if (colA != rowB) {
        printf("Error: Matrix multiplication not possible. Columns of A (%d) must equal rows of B (%d).\n", colA, rowB);
        return 1;
    }

    printf("Enter elements of first matrix (%dx%d):\n", rowA, colA);
    for (int i = 0; i < rowA; i++)
        for (int j = 0; j < colA; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix (%dx%d):\n", rowB, colB);
    for (int i = 0; i < rowB; i++)
        for (int j = 0; j < colB; j++)
            scanf("%d", &b[i][j]);

    multiplyMatrices(a, b, result, rowA, colA, colB);

    printf("\nFirst Matrix:\n");
    printMatrix(a, rowA, colA);

    printf("\nSecond Matrix:\n");
    printMatrix(b, rowB, colB);

    printf("\nResultant Matrix (%dx%d):\n", rowA, colB);
    printMatrix(result, rowA, colB);

    return 0;
}
