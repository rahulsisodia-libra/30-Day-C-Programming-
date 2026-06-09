// Write a program to Calculate sum of first N natural numbers.

#include <stdio.h>

int main() {
    int n;
    long int sum = 0;

    printf("Enter a positive integer N: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    
    sum = (long int)n * (n + 1) / 2;

    printf("Sum of first %d natural numbers = %ld\n", n, sum);

    return 0;
}
