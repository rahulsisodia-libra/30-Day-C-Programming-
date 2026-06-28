// Write a program to Convert lowercase to uppercase.


#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    
    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("Uppercase string: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", toupper((unsigned char)str[i]));
    }
    
    return 0;
}
