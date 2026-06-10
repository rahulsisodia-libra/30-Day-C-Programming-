// Write a program to Reverse a number.


#include <stdio.h>

int main() {
    int n, reversed = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &n);

    // Handle negative numbers
    int isNegative = n < 0;
    if (isNegative) n = -n;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (isNegative) reversed = -reversed;

    printf("Reversed number: %d\n", reversed);

    return 0;
}
