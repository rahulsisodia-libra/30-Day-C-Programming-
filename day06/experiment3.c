// Write a program to Count set bits in a number.


#include <stdio.h>

// Count set bits using Brian Kernighan's algorithm
// Each iteration clears the lowest set bit: n & (n - 1)
int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    int result = countSetBits(num);
    printf("Number of set bits in %u: %d\n", num, result);

    return 0;
}
