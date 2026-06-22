// Write a program to Write function for palindrome.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Check if a string is a palindrome
// Returns 1 if palindrome, 0 otherwise
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum((unsigned char)str[left]))
            left++;
        while (left < right && !isalnum((unsigned char)str[right]))
            right--;

        // Case-insensitive comparison
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right]))
            return 0;

        left++;
        right--;
    }
    return 1;
}

// Check if an integer is a palindrome
int isIntPalindrome(int n) {
    if (n < 0) return 0;

    int original = n;
    int reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return original == reversed;
}

int main() {
    // Test string palindromes
    const char *words[] = {"racecar", "hello", "A man a plan a canal Panama", "level", "world"};
    int count = sizeof(words) / sizeof(words[0]);

    printf("=== String Palindrome Check ===\n");
    for (int i = 0; i < count; i++) {
        printf("\"%s\" -> %s\n", words[i], isPalindrome(words[i]) ? "Palindrome" : "Not a Palindrome");
    }

    // Test integer palindromes
    int numbers[] = {121, 123, 1221, 12321, -121, 0};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    printf("\n=== Integer Palindrome Check ===\n");
    for (int i = 0; i < numCount; i++) {
        printf("%d -> %s\n", numbers[i], isIntPalindrome(numbers[i]) ? "Palindrome" : "Not a Palindrome");
    }

    return 0;
}
