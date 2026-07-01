// Write a program to Compress a string.

#include <stdio.h>
#include <string.h>

void compressString(const char *input, char *output) {
    int len = strlen(input);
    int outIndex = 0;

    for (int i = 0; i < len; ) {
        char currentChar = input[i];
        int count = 1;

        // Count consecutive occurrences of the current character
        while (i + count < len && input[i + count] == currentChar) {
            count++;
        }

        // Write character to output
        output[outIndex++] = currentChar;

        // Write count only if greater than 1
        if (count > 1) {
            int digits = snprintf(NULL, 0, "%d", count);
            snprintf(&output[outIndex], digits + 1, "%d", count);
            outIndex += digits;
        }

        i += count;
    }

    output[outIndex] = '\0';
}

int main() {
    char input[1000];
    char output[2000];

    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline if present
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    compressString(input, output);

    // Only use compressed version if it's actually shorter
    if (strlen(output) < strlen(input)) {
        printf("Compressed string: %s\n", output);
    } else {
        printf("Compression not beneficial. Original string: %s\n", input);
    }

    return 0;
}
