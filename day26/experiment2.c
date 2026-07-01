//  Write a program to Create voting eligibility system.


#include <stdio.h>

int main() {
    int age;
    char citizenship;

    printf("=== Voting Eligibility System ===\n");
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Are you a citizen? (y/n): ");
    scanf(" %c", &citizenship);

    if (age < 0 || age > 150) {
        printf("Invalid age entered.\n");
        return 1;
    }

    if ((citizenship == 'y' || citizenship == 'Y') && age >= 18) {
        printf("You ARE eligible to vote.\n");
    } else if (citizenship != 'y' && citizenship != 'Y') {
        printf("You are NOT eligible to vote (not a citizen).\n");
    } else {
        printf("You are NOT eligible to vote (must be at least 18 years old).\n");
    }

    return 0;
}
