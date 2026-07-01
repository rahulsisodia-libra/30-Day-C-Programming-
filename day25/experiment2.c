// Write a program to Find common characters in strings.


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRINGS 100
#define MAX_LEN 1000
#define CHAR_SIZE 26

// Find minimum frequency of each character across all strings
void findCommonChars(char strings[][MAX_LEN], int n) {
    // min_freq[i] stores the minimum frequency of character (i + 'a') across all strings
    int min_freq[CHAR_SIZE];
    int curr_freq[CHAR_SIZE];

    // Initialize min_freq with frequency of characters in the first string
    memset(min_freq, 0, sizeof(min_freq));
    for (int i = 0; strings[0][i] != '\0'; i++) {
        min_freq[strings[0][i] - 'a']++;
    }

    // For each subsequent string, update min_freq
    for (int i = 1; i < n; i++) {
        memset(curr_freq, 0, sizeof(curr_freq));

        // Count frequency of each character in current string
        for (int j = 0; strings[i][j] != '\0'; j++) {
            curr_freq[strings[i][j] - 'a']++;
        }

        // Update min_freq to be the minimum across all strings seen so far
        for (int k = 0; k < CHAR_SIZE; k++) {
            if (curr_freq[k] < min_freq[k]) {
                min_freq[k] = curr_freq[k];
            }
        }
    }

    // Print common characters
    printf("Common characters in all strings:\n");
    bool found = false;
    for (int i = 0; i < CHAR_SIZE; i++) {
        for (int j = 0; j < min_freq[i]; j++) {
            printf("%c ", (char)(i + 'a'));
            found = true;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_STRINGS) {
        printf("Invalid number of strings. Must be between 1 and %d.\n", MAX_STRINGS);
        return 1;
    }

    char strings[MAX_STRINGS][MAX_LEN];

    printf("Enter %d lowercase strings:\n", n);
    for (int i = 0; i < n; i++) {
        printf("String %d: ", i + 1);
        scanf("%999s", strings[i]);

        // Validate: only lowercase letters allowed
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (strings[i][j] < 'a' || strings[i][j] > 'z') {
                printf("Error: Only lowercase alphabetic characters are allowed.\n");
                return 1;
            }
        }
    }

    findCommonChars(strings, n);

    return 0;
}
