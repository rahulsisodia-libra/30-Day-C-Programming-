// Write a program to Find sum and average of array.


#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double arr[n];
    double sum = 0.0;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }

    double average = sum / n;

    printf("Sum     = %.2f\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
