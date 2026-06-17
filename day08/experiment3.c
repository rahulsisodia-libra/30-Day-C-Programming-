// Write a program to Print character triangle.
// A
// AB
// ABC
// ABCD
// ABCDE

#include <stdio.h>

int main() {
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c ", 'A' + j);
        }
        printf("\n");
    }
    return 0;
}
