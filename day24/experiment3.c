//  Write a program to Find longest word.


#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char word[100];
    char longestWord[100] = "";
    int maxLen = 0;
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character if present
    int len = strlen(sentence);
    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    // Traverse the sentence character by character
    while (sentence[i] != '\0') {
        // Collect characters of a word
        if (sentence[i] != ' ') {
            word[j++] = sentence[i];
        } else {
            // End of a word
            if (j > 0) {
                word[j] = '\0';
                if (j > maxLen) {
                    maxLen = j;
                    strcpy(longestWord, word);
                }
                j = 0;
            }
        }
        i++;
    }

    // Check the last word in case there's no trailing space
    if (j > 0) {
        word[j] = '\0';
        if (j > maxLen) {
            maxLen = j;
            strcpy(longestWord, word);
        }
    }

    if (maxLen > 0) {
        printf("Longest word: %s (length: %d)\n", longestWord, maxLen);
    } else {
        printf("No words found.\n");
    }

    return 0;
}
