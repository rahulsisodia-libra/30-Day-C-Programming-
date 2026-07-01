// Write a program to Create student record management system.

#include <stdio.h>


#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DEPT_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    char department[DEPT_LEN];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

/* Find index of student by ID, returns -1 if not found */
int findStudentById(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

/* Add a new student record */
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Error: Student database is full.\n");
        return;
    }

    Student s;
    printf("\n--- Add New Student ---\n");
    printf("Enter Student ID: ");
    scanf("%d", &s.id);

    if (findStudentById(s.id) != -1) {
        printf("Error: Student with ID %d already exists.\n", s.id);
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Department: ");
    scanf(" %[^\n]", s.department);
    printf("Enter GPA (0.0 - 4.0): ");
    scanf("%f", &s.gpa);

    if (s.gpa < 0.0f || s.gpa > 4.0f) {
        printf("Error: GPA must be between 0.0 and 4.0.\n");
        return;
    }

    students[studentCount++] = s;
    printf("Student added successfully.\n");
}

/* Display a single student record */
void printStudent(const Student *s) {
    printf("\n  ID         : %d\n", s->id);
    printf("  Name       : %s\n", s->name);
    printf("  Age        : %d\n", s->age);
    printf("  Department : %s\n", s->department);
    printf("  GPA        : %.2f\n", s->gpa);
    printf("  -------------------------\n");
}

/* Display all student records */
void displayAllStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n====== All Student Records ======\n");
    for (int i = 0; i < studentCount; i++) {
        printStudent(&students[i]);
    }
}

/* Search for a student by ID */
void searchStudent() {
    int id;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    int idx = findStudentById(id);
    if (idx == -1) {
        printf("Student with ID %d not found.\n", id);
    } else {
        printf("\n--- Student Found ---");
        printStudent(&students[idx]);
    }
}

/* Update an existing student record */
void updateStudent() {
    int id;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    int idx = findStudentById(id);
    if (idx == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    Student *s = &students[idx];
    printf("Updating record for: %s\n", s->name);
    printf("Enter new Name (current: %s): ", s->name);
    scanf(" %[^\n]", s->name);
    printf("Enter new Age (current: %d): ", s->age);
    scanf("%d", &s->age);
    printf("Enter new Department (current: %s): ", s->department);
    scanf(" %[^\n]", s->department);

    float gpa;
    printf("Enter new GPA (current: %.2f): ", s->gpa);
    scanf("%f", &gpa);
    if (gpa < 0.0f || gpa > 4.0f) {
        printf("Error: GPA must be between 0.0 and 4.0. GPA not updated.\n");
    } else {
        s->gpa = gpa;
    }

    printf("Student record updated successfully.\n");
}

/* Delete a student record by ID */
void deleteStudent() {
    int id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    int idx = findStudentById(id);
    if (idx == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    /* Shift remaining records left to fill the gap */
    for (int i = idx; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    printf("Student with ID %d deleted successfully.\n", id);
}

/* Display the main menu */
void showMenu() {
    printf("\n====== Student Record Management System ======\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Update Student Record\n");
    printf("5. Delete Student Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    printf("Welcome to the Student Record Management System\n");

    while (1) {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            /* Clear invalid input */
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: addStudent();        break;
            case 2: displayAllStudents(); break;
            case 3: searchStudent();     break;
            case 4: updateStudent();     break;
            case 5: deleteStudent();     break;
            case 6:
                printf("Exiting. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select between 1 and 6.\n");
        }
    }

    return 0;
}
