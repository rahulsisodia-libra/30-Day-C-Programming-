#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_SUBJECTS 5

// Structure to hold student data
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    float marks[MAX_SUBJECTS];
    float average;
    char grade;
} Student;

// Subject names
const char subjects[MAX_SUBJECTS][20] = {
    "Mathematics",
    "Physics",
    "Chemistry",
    "English",
    "Computer Sci"
};

// Function prototypes
void addStudent(Student students[], int *count);
void displayAllStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void calculateAverage(Student *s);
char calculateGrade(float average);
void displayToppers(Student students[], int count);
void updateMarks(Student students[], int count);
void deleteStudent(Student students[], int *count);
void displayMenu();
void sortStudentsByAverage(Student students[], int count);

// Calculate average marks for a student
void calculateAverage(Student *s) {
    float sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += s->marks[i];
    }
    s->average = sum / MAX_SUBJECTS;
}

// Assign grade based on average
char calculateGrade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 75) return 'B';
    else if (average >= 60) return 'C';
    else if (average >= 45) return 'D';
    else return 'F';
}

// Add a new student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\n[!] Student list is full. Cannot add more students.\n");
        return;
    }

    Student *s = &students[*count];
    s->id = *count + 1;

    printf("\n--- Add New Student ---\n");
    printf("Enter student name: ");
    getchar(); // flush newline
    fgets(s->name, MAX_NAME_LEN, stdin);
    // Remove trailing newline
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("Enter marks for each subject (0 - 100):\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        do {
            printf("  %s: ", subjects[i]);
            scanf("%f", &s->marks[i]);
            if (s->marks[i] < 0 || s->marks[i] > 100) {
                printf("  [!] Invalid marks. Please enter a value between 0 and 100.\n");
            }
        } while (s->marks[i] < 0 || s->marks[i] > 100);
    }

    calculateAverage(s);
    s->grade = calculateGrade(s->average);

    (*count)++;
    printf("\n[+] Student '%s' added successfully with ID %d.\n", s->name, s->id);
}

// Display all students
void displayAllStudents(Student students[], int count) {
    if (count == 0) {
        printf("\n[!] No students found.\n");
        return;
    }

    printf("\n========== Student Records ==========\n");
    printf("%-5s %-20s", "ID", "Name");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf(" %-13s", subjects[i]);
    }
    printf(" %-9s %-6s\n", "Average", "Grade");
    printf("----------------------------------------------------------------------"
           "------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s", students[i].id, students[i].name);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf(" %-13.2f", students[i].marks[j]);
        }
        printf(" %-9.2f %-6c\n", students[i].average, students[i].grade);
    }
    printf("======================================\n");
}

// Search student by name or ID
void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("\n[!] No students found.\n");
        return;
    }

    int choice;
    printf("\nSearch by:\n 1. Student ID\n 2. Student Name\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int id;
        printf("Enter Student ID: ");
        scanf("%d", &id);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                printf("\n--- Student Found ---\n");
                printf("ID    : %d\n", students[i].id);
                printf("Name  : %s\n", students[i].name);
                for (int j = 0; j < MAX_SUBJECTS; j++) {
                    printf("%-13s: %.2f\n", subjects[j], students[i].marks[j]);
                }
                printf("Average: %.2f\n", students[i].average);
                printf("Grade  : %c\n", students[i].grade);
                found = 1;
                break;
            }
        }
        if (!found) printf("\n[!] Student with ID %d not found.\n", id);

    } else if (choice == 2) {
        char name[MAX_NAME_LEN];
        printf("Enter Student Name: ");
        getchar();
        fgets(name, MAX_NAME_LEN, stdin);
        name[strcspn(name, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < count; i++) {
            // Case-insensitive partial match
            char lname[MAX_NAME_LEN], lsearch[MAX_NAME_LEN];
            strcpy(lname, students[i].name);
            strcpy(lsearch, name);
            for (int k = 0; lname[k]; k++) lname[k] = (char)tolower((unsigned char)lname[k]);
            for (int k = 0; lsearch[k]; k++) lsearch[k] = (char)tolower((unsigned char)lsearch[k]);

            if (strstr(lname, lsearch)) {
                printf("\n--- Student Found ---\n");
                printf("ID    : %d\n", students[i].id);
                printf("Name  : %s\n", students[i].name);
                for (int j = 0; j < MAX_SUBJECTS; j++) {
                    printf("%-13s: %.2f\n", subjects[j], students[i].marks[j]);
                }
                printf("Average: %.2f\n", students[i].average);
                printf("Grade  : %c\n", students[i].grade);
                found = 1;
            }
        }
        if (!found) printf("\n[!] No student found with name '%s'.\n", name);
    } else {
        printf("\n[!] Invalid choice.\n");
    }
}

// Display top 3 students by average
void displayToppers(Student students[], int count) {
    if (count == 0) {
        printf("\n[!] No students found.\n");
        return;
    }

    // Make a copy to sort
    Student temp[MAX_STUDENTS];
    for (int i = 0; i < count; i++) temp[i] = students[i];

    // Bubble sort descending by average
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j].average < temp[j + 1].average) {
                Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    int display = count < 3 ? count : 3;
    printf("\n========== Top %d Students ==========\n", display);
    printf("%-5s %-20s %-9s %-6s\n", "Rank", "Name", "Average", "Grade");
    printf("------------------------------------------\n");
    for (int i = 0; i < display; i++) {
        printf("%-5d %-20s %-9.2f %-6c\n",
               i + 1, temp[i].name, temp[i].average, temp[i].grade);
    }
    printf("==========================================\n");
}

// Sort and display students by average
void sortStudentsByAverage(Student students[], int count) {
    if (count == 0) {
        printf("\n[!] No students found.\n");
        return;
    }

    Student temp[MAX_STUDENTS];
    for (int i = 0; i < count; i++) temp[i] = students[i];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j].average < temp[j + 1].average) {
                Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    printf("\n=== Students Sorted by Average (Descending) ===\n");
    printf("%-5s %-20s %-9s %-6s\n", "Rank", "Name", "Average", "Grade");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-9.2f %-6c\n",
               i + 1, temp[i].name, temp[i].average, temp[i].grade);
    }
    printf("==================================================\n");
}

// Update marks of a student
void updateMarks(Student students[], int count) {
    if (count == 0) {
        printf("\n[!] No students found.\n");
        return;
    }

    int id;
    printf("\nEnter Student ID to update marks: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Updating marks for '%s':\n", students[i].name);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                do {
                    printf("  %s (current: %.2f): ", subjects[j], students[i].marks[j]);
                    scanf("%f", &students[i].marks[j]);
                    if (students[i].marks[j] < 0 || students[i].marks[j] > 100) {
                        printf("  [!] Invalid marks. Enter a value between 0 and 100.\n");
                    }
                } while (students[i].marks[j] < 0 || students[i].marks[j] > 100);
            }
            calculateAverage(&students[i]);
            students[i].grade = calculateGrade(students[i].average);
            printf("\n[+] Marks updated successfully for '%s'.\n", students[i].name);
            return;
        }
    }
    printf("\n[!] Student with ID %d not found.\n", id);
}

// Delete a student record
void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("\n[!] No students found.\n");
        return;
    }

    int id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            char name[MAX_NAME_LEN];
            strcpy(name, students[i].name);
            // Shift left
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
                students[j].id = j + 1; // re-index
            }
            (*count)--;
            printf("\n[-] Student '%s' (ID: %d) deleted successfully.\n", name, id);
            return;
        }
    }
    printf("\n[!] Student with ID %d not found.\n", id);
}

// Display main menu
void displayMenu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║   Student Grade Management System    ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  1. Add Student                      ║\n");
    printf("║  2. Display All Students             ║\n");
    printf("║  3. Search Student                   ║\n");
    printf("║  4. Update Student Marks             ║\n");
    printf("║  5. Delete Student                   ║\n");
    printf("║  6. Display Top Students             ║\n");
    printf("║  7. Sort Students by Average         ║\n");
    printf("║  8. Exit                             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Enter your choice: ");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("\nWelcome to the Student Grade Management System\n");
    printf("Subjects: ");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("%s", subjects[i]);
        if (i < MAX_SUBJECTS - 1) printf(", ");
    }
    printf("\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count);         break;
            case 2: displayAllStudents(students, count);  break;
            case 3: searchStudent(students, count);       break;
            case 4: updateMarks(students, count);         break;
            case 5: deleteStudent(students, &count);      break;
            case 6: displayToppers(students, count);      break;
            case 7: sortStudentsByAverage(students, count); break;
            case 8:
                printf("\nThank you for using the Student Grade Management System. Goodbye!\n");
                break;
            default:
                printf("\n[!] Invalid choice. Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}