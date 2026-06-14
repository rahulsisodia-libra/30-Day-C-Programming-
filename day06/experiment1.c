// Write a program to Convert decimal to binary.


#include <stdio.h>

void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    // Handle negative numbers
    if (n < 0) {
        printf("-");
        n = -n;
    }

    int binary[32];
    int index = 0;

    while (n > 0) {
        binary[index++] = n % 2;
        n /= 2;
    }

    // Print in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary representation: ");
    decimalToBinary(decimal);
    printf("\n");

    return 0;
}
