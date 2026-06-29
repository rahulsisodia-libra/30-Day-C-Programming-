// Write a program to Find first repeating character.


#include <stdio.h>
#include <string.h>

char firstRepeatingChar(const char *str) {
    int seen[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];
        if (seen[c]) {
            return c;
        }
        seen[c] = 1;
    }

    return '\0'; // No repeating character found
}

int main() {
    char str[256];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    char result = firstRepeatingChar(str);

    if (result != '\0') {
        printf("First repeating character: '%c'\n", result);
    } else {
        printf("No repeating character found.\n");
    }

    return 0;
}
