// Write a program to Find first non-repeating character.


#include <stdio.h>
#include <string.h>

char firstNonRepeating(const char *str) {
    int freq[256] = {0};
    int len = strlen(str);

    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < len; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }

    return '\0'; // No non-repeating character found
}

int main() {
    char str[256];

    printf("Enter a string: ");
    scanf("%255s", str);

    char result = firstNonRepeating(str);

    if (result != '\0') {
        printf("First non-repeating character: %c\n", result);
    } else {
        printf("No non-repeating character found.\n");
    }

    return 0;
}
