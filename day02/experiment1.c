// Write a program to Find sum of digits of a number.


#include <stdio.h>

int sumOfDigits(int n) {
    int sum = 0;
    // Handle negative numbers
    if (n < 0) n = -n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum of digits of %d = %d\n", num, sumOfDigits(num));
    return 0;
}
