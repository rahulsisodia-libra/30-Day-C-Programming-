// Write a program to Frequency of an element.

#include <stdio.h>

int main() {
    int arr[100], n, element, frequency = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to find frequency: ");
    scanf("%d", &element);

    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            frequency++;
        }
    }

    printf("Frequency of %d is: %d\n", element, frequency);

    return 0;
}
