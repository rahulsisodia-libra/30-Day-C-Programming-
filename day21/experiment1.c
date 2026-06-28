// Write a program to Find string length without strlen().


#include <stdio.h>

int stringLength(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets, if present
    int len = stringLength(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("Length of the string \"%s\" is: %d\n", str, len);
    return 0;
}
