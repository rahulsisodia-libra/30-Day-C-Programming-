// Write a program to Check anagram strings.


#include <stdio.h>
#include <ctype.h>

#define MAX_CHARS 256

int isAnagram(const char *str1, const char *str2) {
    int count[MAX_CHARS] = {0};

    // Increment count for each character in str1
    for (int i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)tolower(str1[i])]++;
    }

    // Decrement count for each character in str2
    for (int i = 0; str2[i] != '\0'; i++) {
        count[(unsigned char)tolower(str2[i])]--;
    }

    // If all counts are zero, strings are anagrams
    for (int i = 0; i < MAX_CHARS; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%99s", str1);

    printf("Enter second string: ");
    scanf("%99s", str2);

    if (isAnagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are not anagrams.\n", str1, str2);
    }

    return 0;
}
