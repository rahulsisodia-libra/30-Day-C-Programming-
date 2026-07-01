// Write a program to Create quiz application.



#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define MAX_LEN 256

typedef struct {
    char question[MAX_LEN];
    char options[MAX_OPTIONS][MAX_LEN];
    int correct_option; // 1-based index
} Question;

void display_question(int num, Question *q) {
    printf("\nQuestion %d: %s\n", num, q->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("  %d. %s\n", i + 1, q->options[i]);
    }
}

int main() {
    Question quiz[MAX_QUESTIONS] = {
        {
            "What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Rome"},
            3
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Saturn"},
            2
        },
        {
            "What is the largest ocean on Earth?",
            {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"},
            4
        },
        {
            "Who wrote 'Romeo and Juliet'?",
            {"Charles Dickens", "Mark Twain", "William Shakespeare", "Leo Tolstoy"},
            3
        },
        {
            "What is the value of Pi (approx)?",
            {"2.14", "3.14", "4.14", "1.14"},
            2
        }
    };

    int score = 0;
    int answer;
    char name[50];

    printf("=============================\n");
    printf("     Welcome to Quiz App     \n");
    printf("=============================\n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

    printf("\nHello, %s! The quiz has %d questions.\n", name, MAX_QUESTIONS);
    printf("Enter the option number (1-4) for each answer.\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        display_question(i + 1, &quiz[i]);

        printf("Your answer: ");
        if (scanf("%d", &answer) != 1) {
            printf("Invalid input. Skipping question.\n");
            // Clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (answer < 1 || answer > MAX_OPTIONS) {
            printf("Invalid option. Skipping question.\n");
        } else if (answer == quiz[i].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %d. %s\n",
                   quiz[i].correct_option,
                   quiz[i].options[quiz[i].correct_option - 1]);
        }
    }

    printf("\n=============================\n");
    printf("       Quiz Completed!       \n");
    printf("=============================\n");
    printf("Player  : %s\n", name);
    printf("Score   : %d / %d\n", score, MAX_QUESTIONS);

    float percentage = (float)score / MAX_QUESTIONS * 100;
    printf("Percentage: %.1f%%\n", percentage);

    if (percentage == 100)
        printf("Grade: A+ (Excellent!)\n");
    else if (percentage >= 80)
        printf("Grade: A (Very Good!)\n");
    else if (percentage >= 60)
        printf("Grade: B (Good)\n");
    else if (percentage >= 40)
        printf("Grade: C (Average)\n");
    else
        printf("Grade: F (Better luck next time!)\n");

    printf("=============================\n");

    return 0;
}
