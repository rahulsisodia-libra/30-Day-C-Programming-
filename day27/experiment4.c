// Write a program to Create marksheet generation system.


#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int roll_number;
    int num_subjects;
    char subject_names[MAX_SUBJECTS][MAX_NAME_LEN];
    float marks[MAX_SUBJECTS];
    float total;
    float percentage;
    char grade;
} Student;

char calculate_grade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 80) return 'B';
    else if (percentage >= 70) return 'C';
    else if (percentage >= 60) return 'D';
    else if (percentage >= 50) return 'E';
    else return 'F';
}

void calculate_results(Student *s, float max_marks_per_subject) {
    s->total = 0;
    for (int i = 0; i < s->num_subjects; i++) {
        s->total += s->marks[i];
    }
    float max_total = max_marks_per_subject * s->num_subjects;
    s->percentage = (s->total / max_total) * 100.0f;
    s->grade = calculate_grade(s->percentage);
}

void print_marksheet(const Student *s, float max_marks_per_subject) {
    printf("\n");
    printf("============================================================\n");
    printf("                     MARK SHEET                            \n");
    printf("============================================================\n");
    printf("  Student Name  : %s\n", s->name);
    printf("  Roll Number   : %d\n", s->roll_number);
    printf("------------------------------------------------------------\n");
    printf("  %-30s %-10s %-10s\n", "Subject", "Max Marks", "Marks Obtained");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < s->num_subjects; i++) {
        printf("  %-30s %-10.0f %-10.2f\n",
               s->subject_names[i],
               max_marks_per_subject,
               s->marks[i]);
    }

    printf("------------------------------------------------------------\n");
    printf("  %-30s %-10.0f %-10.2f\n",
           "Total",
           max_marks_per_subject * s->num_subjects,
           s->total);
    printf("------------------------------------------------------------\n");
    printf("  Percentage    : %.2f%%\n", s->percentage);
    printf("  Grade         : %c\n", s->grade);
    printf("  Result        : %s\n", s->grade != 'F' ? "PASS" : "FAIL");
    printf("============================================================\n");

    printf("\n  Grade Scale:\n");
    printf("  A: 90%% and above  | B: 80-89%%  | C: 70-79%%\n");
    printf("  D: 60-69%%         | E: 50-59%% | F: Below 50%%\n");
    printf("============================================================\n\n");
}

int main() {
    Student student;
    float max_marks_per_subject;

    printf("============================================================\n");
    printf("           MARKSHEET GENERATION SYSTEM                     \n");
    printf("============================================================\n\n");

    printf("Enter student name: ");
    fgets(student.name, MAX_NAME_LEN, stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter roll number: ");
    scanf("%d", &student.roll_number);

    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &student.num_subjects);

    if (student.num_subjects < 1 || student.num_subjects > MAX_SUBJECTS) {
        printf("Invalid number of subjects. Must be between 1 and %d.\n", MAX_SUBJECTS);
        return 1;
    }

    printf("Enter maximum marks per subject: ");
    scanf("%f", &max_marks_per_subject);

    if (max_marks_per_subject <= 0) {
        printf("Invalid maximum marks. Must be greater than 0.\n");
        return 1;
    }

    // Consume leftover newline
    getchar();

    for (int i = 0; i < student.num_subjects; i++) {
        printf("\nSubject %d name: ", i + 1);
        fgets(student.subject_names[i], MAX_NAME_LEN, stdin);
        student.subject_names[i][strcspn(student.subject_names[i], "\n")] = '\0';

        do {
            printf("Marks obtained in %s (0 - %.0f): ",
                   student.subject_names[i], max_marks_per_subject);
            scanf("%f", &student.marks[i]);

            if (student.marks[i] < 0 || student.marks[i] > max_marks_per_subject) {
                printf("  Invalid marks. Please enter a value between 0 and %.0f.\n",
                       max_marks_per_subject);
            }
        } while (student.marks[i] < 0 || student.marks[i] > max_marks_per_subject);

        // Consume leftover newline
        getchar();
    }

    calculate_results(&student, max_marks_per_subject);
    print_marksheet(&student, max_marks_per_subject);

    return 0;
}
