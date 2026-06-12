

#include <stdio.h>
#include <stdbool.h>

int countDigits(int n) {
    if (n == 0) return 1;      // fix: 0 has 1 digit
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

long int intPow(int base, int exp) {   // fix: avoid pow() float errors
    long int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

bool isArmstrong(int n) {
    if (n < 0) return false;   // negative numbers can't be Armstrong
    int digits = countDigits(n);
    int temp = n;
    long int sum = 0;

    while (temp != 0) {
        int digit = temp % 10;
        sum += intPow(digit, digits);  // use intPow instead of pow()
        temp /= 10;
    }

    return sum == n;  // simplified if-return
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}