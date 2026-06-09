// Write a program to Find factorial of a number.

#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) return 0; // undefined for negative numbers
    if (n == 0 || n == 1) return 1;
    return (unsigned long long)n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d = %llu\n", num, factorial(num));
    }

    return 0;
}
