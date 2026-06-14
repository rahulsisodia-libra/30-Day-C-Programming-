// Write a program to Find largest prime factor.

#include <stdio.h>

long long largestPrimeFactor(long long n) {
    long long largest = -1;

    // Divide out all factors of 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Check odd factors from 3 onwards
    for (long long i = 3; (long long)i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // If n is still greater than 1, then it's a prime factor
    if (n > 1) {
        largest = n;
    }

    return largest;
}

int main() {
    long long n;
    printf("Enter a number: ");
    scanf("%lld", &n);

    if (n <= 1) {
        printf("Please enter a number greater than 1.\n");
        return 1;
    }

    printf("Largest prime factor of %lld is: %lld\n", n, largestPrimeFactor(n));
    return 0;
}
