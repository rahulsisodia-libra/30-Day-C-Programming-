// Write a program to Count words in a sentence.


#include <stdio.h>
#include <string.h>

int countWords(const char *sentence) {
    int count = 0;
    int inWord = 0;

    while (*sentence) {
        if (*sentence == ' ' || *sentence == '\t' || *sentence == '\n') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
        sentence++;
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove trailing newline if present
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    int wordCount = countWords(sentence);
    printf("Number of words: %d\n", wordCount);

    return 0;
}
