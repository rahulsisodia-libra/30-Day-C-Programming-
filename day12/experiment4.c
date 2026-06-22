// Write a program to Write function for perfect number.


// A perfect number is a positive integer that equals the sum of its proper divisors
// (all divisors excluding the number itself).
// Example: 6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14


#include <stdio.h>

int isPerfect(int n) {
    if (n <= 1) return 0;
    
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum == n;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPerfect(num))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);
    
    printf("\nPerfect numbers between 1 and 1000:\n");
    for (int i = 2; i <= 1000; i++) {
        if (isPerfect(i))
            printf("%d\n", i);
    }
    
    return 0;
}
