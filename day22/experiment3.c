// Write a program to Character frequency.

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0};
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    
    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    // Display character frequencies
    printf("\nCharacter Frequencies:\n");
    printf("%-10s %s\n", "Character", "Frequency");
    printf("--------------------\n");
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (i == ' ') {
                printf("%-10s %d\n", "(space)", freq[i]);
            } else {
                printf("%-10c %d\n", i, freq[i]);
            }
        }
    }
    
    return 0;
}
