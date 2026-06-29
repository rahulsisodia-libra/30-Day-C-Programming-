// Write a program to Find maximum occurring character.


#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0};
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline if present
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[--len] = '\0';
    }
    
    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    // Find the maximum occurring character
    int maxFreq = 0;
    char maxChar = str[0];
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = (char)i;
        }
    }
    
    printf("Maximum occurring character: '%c'\n", maxChar);
    printf("Frequency: %d\n", maxFreq);
    
    return 0;
}
