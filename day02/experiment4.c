// Write a program to Check whether a number is palindrome.

#include <stdio.h>

int isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    // Handle negative numbers (not palindromes)
    if (n < 0) return 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return original == reversed;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}
