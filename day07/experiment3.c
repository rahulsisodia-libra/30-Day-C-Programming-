// Write a program to Recursive sum of digits.


#include <stdio.h>

int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    int result = sumOfDigits(num);
    printf("Sum of digits of %d = %d\n", num, result);

    return 0;
}
