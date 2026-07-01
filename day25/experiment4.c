// Write a program to Sort words by length.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort: sorts by word length ascending
int compareByLength(const void *a, const void *b) {
    const char *wordA = *(const char **)a;
    const char *wordB = *(const char **)b;
    int lenA = strlen(wordA);
    int lenB = strlen(wordB);
    if (lenA != lenB) return lenA - lenB;
    // Secondary sort: alphabetical for equal lengths
    return strcmp(wordA, wordB);
}

int main(void) {
    char input[1024];
    char *words[256];
    int count = 0;

    printf("Enter words (one per line, empty line to stop):\n");

    while (count < 256) {
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        // Strip trailing newline
        input[strcspn(input, "\n")] = '\0';

        // Stop on empty line
        if (input[0] == '\0') break;

        words[count] = malloc(strlen(input) + 1);
        if (words[count] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            break;
        }
        strcpy(words[count], input);
        count++;
    }

    if (count == 0) {
        printf("No words entered.\n");
        return 0;
    }

    qsort(words, count, sizeof(char *), compareByLength);

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < count; i++) {
        printf("  %s (length: %zu)\n", words[i], strlen(words[i]));
        free(words[i]);
    }

    return 0;
}
