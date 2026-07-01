// Write a program to Create number guessing game.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess, attempts = 0;
    const int MAX_ATTEMPTS = 10;

    srand(time(NULL));
    secret = (rand() % 100) + 1; // random number between 1 and 100

    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, MAX_ATTEMPTS);

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Please guess a number between 1 and 100.\n\n");
            attempts--; // don't count invalid range as an attempt
            continue;
        }

        if (guess < secret) {
            printf("Too low! Try a higher number.\n\n");
        } else if (guess > secret) {
            printf("Too high! Try a lower number.\n\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempt(s)!\n",
                   secret, attempts);
            return 0;
        }
    }

    printf("Game over! You've used all %d attempts.\n", MAX_ATTEMPTS);
    printf("The secret number was: %d\n", secret);

    return 0;
}
