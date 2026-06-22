// Write a program to Count even and odd elements.


#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }

    printf("Even count: %d\n", even_count);
    printf("Odd count: %d\n", odd_count);

    return 0;
}
