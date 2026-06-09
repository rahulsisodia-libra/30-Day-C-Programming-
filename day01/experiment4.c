// Write a program to Count digits in a number.

#include <stdio.h>

int countDigits(long long n) {
    if (n == 0) return 1;
    
    int count = 0;
    
    if (n < 0) n = -n;
    
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    long long number;
    printf("Enter a number: ");
    scanf("%lld", &number);
    
    printf("Number of digits in %lld: %d\n", number, countDigits(number));
    return 0;
}
