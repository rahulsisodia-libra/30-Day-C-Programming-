// Write a program to Remove duplicate characters.


#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int seen[256] = {0};
    int writeIndex = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];
        if (!seen[c]) {
            seen[c] = 1;
            str[writeIndex++] = str[i];
        }
    }
    str[writeIndex] = '\0';
}

int main() {
    char str[256];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline from fgets
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("Original string : %s\n", str);
    removeDuplicates(str);
    printf("After removing duplicates: %s\n", str);

    return 0;
}
