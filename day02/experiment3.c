// Write a program to Find product of digits.

#include <stdio.h>

int productOfDigits(int n) {
    // Handle negative numbers
    if (n < 0) n = -n;
    
    // Single digit
    if (n == 0) return 0;
    
    int product = 1;
    while (n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Product of digits of %d = %d\n", num, productOfDigits(num));
    return 0;
}
