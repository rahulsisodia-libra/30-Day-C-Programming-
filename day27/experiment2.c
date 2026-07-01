// Write a program to Create employee management system.


#include <stdio.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define DEPT_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached.\n");
        return;
    }
    Employee e;
    e.id = employeeCount + 1;

    printf("Enter name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter department: ");
    scanf(" %[^\n]", e.department);

    printf("Enter salary: ");
    scanf("%f", &e.salary);

    employees[employeeCount++] = e;
    printf("Employee added successfully with ID %d.\n", e.id);
}

void displayAllEmployees() {
    if (employeeCount == 0) {
        printf("No employees found.\n");
        return;
    }
    printf("\n%-5s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-5d %-20s %-20s %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nID       : %d\n", employees[i].id);
            printf("Name     : %s\n", employees[i].name);
            printf("Dept     : %s\n", employees[i].department);
            printf("Salary   : %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void updateEmployee() {
    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", employees[i].name);

            printf("Enter new department: ");
            scanf(" %[^\n]", employees[i].department);

            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);

            printf("Employee updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void deleteEmployee() {
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee deleted successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

int main() {
    int choice;

    printf("=== Employee Management System ===\n");

    do {
        printf("\n1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee();       break;
            case 2: displayAllEmployees(); break;
            case 3: searchEmployee();    break;
            case 4: updateEmployee();    break;
            case 5: deleteEmployee();    break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
