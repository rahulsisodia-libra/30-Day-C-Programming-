// Write a program to Check symmetric matrix.



#include <stdio.h>

#define MAX 10

int isSymmetric(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int matrix[MAX][MAX];
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size. Please enter a size between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nEntered matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric(matrix, n)) {
        printf("\nThe matrix is Symmetric.\n");
    } else {
        printf("\nThe matrix is NOT Symmetric.\n");
    }

    return 0;
}
