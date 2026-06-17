
// Write a program to Print hollow square pattern.
// * * * * *
// *       *
// *       *
// *       *
// * * * * *


#include <stdio.h>

int main() {
    int n = 5;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Print '*' for border cells (first/last row or first/last column)
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
