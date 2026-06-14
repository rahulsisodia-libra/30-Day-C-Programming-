// Write a program to Find x^n without pow().


#include <stdio.h>

long long power(int x, int n) {
    // Handle negative exponents
    if (n < 0) return 0; // integer result undefined for negative n
    if (n == 0) return 1;

    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

int main() {
    int x, n;
    printf("Enter base (x): ");
    scanf("%d", &x);
    printf("Enter exponent (n): ");
    scanf("%d", &n);

    printf("%d^%d = %lld\n", x, n, power(x, n));
    return 0;
}
