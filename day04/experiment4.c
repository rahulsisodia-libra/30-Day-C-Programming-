// Write a program to Print Armstrong numbers in a range.


#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int isArmstrong(int n) {
    int digits = countDigits(n);
    int temp = n;
    int sum = 0;

    while (temp != 0) {
        int digit = temp % 10;
        sum += (int)pow(digit, digits);
        temp /= 10;
    }

    return sum == n;
}

int main() {
    int lower, upper;

    printf("Enter the lower bound of the range: ");
    scanf("%d", &lower);

    printf("Enter the upper bound of the range: ");
    scanf("%d", &upper);

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);

    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
