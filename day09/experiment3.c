// Write a program to Print repeated character pattern.
// A
// BB
// CCC
// DDDD
// EEEEE


#include <stdio.h>

int main() {
    int rows = 5;
    
    for (int i = 0; i < rows; i++) {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
    
    return 0;
}