// Write a program to Create menu-driven calculator.


#include <stdio.h>

void add(double a, double b) {
    printf("Result: %.2f\n", a + b);
}

void subtract(double a, double b) {
    printf("Result: %.2f\n", a - b);
}

void multiply(double a, double b) {
    printf("Result: %.2f\n", a * b);
}

void divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2f\n", a / b);
    }
}

void modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %d\n", a % b);
    }
}

int main() {
    int choice;
    double num1, num2;

    do {
        printf("\n===== Menu-Driven Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus (integers only)\n");
        printf("0. Exit\n");
        printf("==================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            if (choice == 5) {
                int a, b;
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                modulus(a, b);
            } else {
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);

                switch (choice) {
                    case 1: add(num1, num2);      break;
                    case 2: subtract(num1, num2); break;
                    case 3: multiply(num1, num2); break;
                    case 4: divide(num1, num2);   break;
                }
            }
        } else if (choice != 0) {
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    printf("Exiting calculator. Goodbye!\n");
    return 0;
}
