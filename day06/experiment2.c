// Write a program to Convert binary to decimal.


#include <stdio.h>
#include <string.h>

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return -1; // invalid binary digit
        }
        decimal = decimal * 2 + (binary[i] - '0');
    }

    return decimal;
}

int main() {
    char binary[65];

    printf("Enter a binary number: ");
    scanf("%64s", binary);

    int result = binaryToDecimal(binary);

    if (result == -1) {
        printf("Invalid binary number.\n");
    } else {
        printf("Decimal equivalent of %s is %d\n", binary, result);
    }

    return 0;
}
