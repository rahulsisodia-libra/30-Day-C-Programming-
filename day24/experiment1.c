// Write a program to Check string rotation.


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Check if str2 is a rotation of str1
bool isRotation(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths differ, str2 cannot be a rotation of str1
    if (len1 != len2) {
        return false;
    }

    // Concatenate str1 with itself
    // If str2 is a rotation of str1, it must be a substring of str1+str1
    char temp[2 * len1 + 1];
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of temp
    if (strstr(temp, str2) != NULL) {
        return true;
    }

    return false;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if (isRotation(str1, str2)) {
        printf("\"%s\" is a rotation of \"%s\"\n", str2, str1);
    } else {
        printf("\"%s\" is NOT a rotation of \"%s\"\n", str2, str1);
    }

    return 0;
}
