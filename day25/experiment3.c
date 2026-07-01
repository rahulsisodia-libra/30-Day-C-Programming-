// Write a program to Sort names alphabetically.


#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LEN 50

int main() {
    char names[MAX_NAMES][MAX_LEN];
    char temp[MAX_LEN];
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        fgets(names[i], MAX_LEN, stdin);
        // Remove trailing newline
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Bubble sort alphabetically
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nNames sorted alphabetically:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}
