// Write a program to Write function for Fibonacci.


#include <stdio.h>

// Recursive Fibonacci
int fibonacci_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative Fibonacci (more efficient)
long long fibonacci_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n = 10;

    printf("Fibonacci sequence (first %d terms):\n", n);

    printf("Recursive: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");

    printf("Iterative: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibonacci_iterative(i));
    }
    printf("\n");

    return 0;
}
