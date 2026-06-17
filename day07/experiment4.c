// Write a program to Recursive reverse number.


#include <stdio.h>

int reverseNumber(int num, int reversed) {
    if (num == 0) {
        return reversed;
    }
    return reverseNumber(num / 10, reversed * 10 + num % 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int isNegative = num < 0;
    if (isNegative) num = -num;

    int result = reverseNumber(num, 0);
    if (isNegative) result = -result;

    printf("Reversed number: %d\n", result);
    return 0;
}
