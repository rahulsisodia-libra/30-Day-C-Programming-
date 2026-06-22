// Write a program to Write function for Armstrong.


#include <stdio.h>
#include <math.h>

// Function to count the number of digits in a number
int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Function to check if a number is an Armstrong number
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
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    // Print all Armstrong numbers up to 1000
    printf("\nArmstrong numbers up to 1000:\n");
    for (int i = 1; i <= 1000; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
