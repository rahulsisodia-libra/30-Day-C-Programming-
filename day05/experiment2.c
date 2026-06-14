// Write a program to Check strong number.

#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to check if a number is a Strong number
// A Strong number is a number where the sum of factorials
// of its digits equals the number itself. Example: 145 = 1! + 4! + 5!
int isStrong(int num) {
    int sum = 0;
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    return sum == num;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isStrong(num)) {
        printf("%d is a Strong number.\n", num);
    } else {
        printf("%d is not a Strong number.\n", num);
    }

    return 0;
}
