// Write a program to Find diagonal sum.



#include <stdio.h>

#define MAX 10

int main() {
    int matrix[MAX][MAX];
    int n, i, j;
    int primarySum = 0, secondarySum = 0;

    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum (top-left to bottom-right)
    // and secondary diagonal sum (top-right to bottom-left)
    for (i = 0; i < n; i++) {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][n - 1 - i];
    }

    // If n is odd, the center element is counted twice, subtract it once
    int totalSum = primarySum + secondarySum;
    if (n % 2 != 0) {
        totalSum -= matrix[n / 2][n / 2];
    }

    printf("\nMatrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPrimary diagonal sum   : %d\n", primarySum);
    printf("Secondary diagonal sum : %d\n", secondarySum);
    printf("Total diagonal sum     : %d\n", totalSum);

    return 0;
}
