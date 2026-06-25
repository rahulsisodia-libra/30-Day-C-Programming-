// Write a program to Find maximum frequency element.


#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxFreq = 0;
    int maxElement = arr[0];
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;

        int freq = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                freq++;
                visited[j] = 1;
            }
        }

        if (freq > maxFreq) {
            maxFreq = freq;
            maxElement = arr[i];
        }
    }

    printf("Maximum frequency element: %d (appears %d times)\n", maxElement, maxFreq);

    return 0;
}
