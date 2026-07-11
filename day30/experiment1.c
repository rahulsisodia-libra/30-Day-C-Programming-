// Write a program to Create student record system using arrays and strings.


#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define COURSE_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char course[COURSE_LENGTH];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student database is full!\n");
        return;
    }

    Student s;
    s.id = studentCount + 1;

    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter course: ");
    scanf(" %[^\n]", s.course);

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    students[studentCount++] = s;
    printf("Student added successfully with ID: %d\n", s.id);
}

void displayAllStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-5s %-25s %-5s %-20s %-5s\n", "ID", "Name", "Age", "Course", "GPA");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-5d %-25s %-5d %-20s %-5.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].course,
               students[i].gpa);
    }
}

void searchStudent() {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found:\n");
            printf("ID     : %d\n", students[i].id);
            printf("Name   : %s\n", students[i].name);
            printf("Age    : %d\n", students[i].age);
            printf("Course : %s\n", students[i].course);
            printf("GPA    : %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void updateStudent() {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Updating record for %s:\n", students[i].name);

            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new course: ");
            scanf(" %[^\n]", students[i].course);

            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);

            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void deleteStudent() {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student record deleted successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

int main() {
    int choice;

    printf("=== Student Record System ===\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent();        break;
            case 2: displayAllStudents(); break;
            case 3: searchStudent();     break;
            case 4: updateStudent();     break;
            case 5: deleteStudent();     break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
