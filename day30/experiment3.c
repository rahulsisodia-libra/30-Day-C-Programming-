// Write a program to Create mini employee management system.


#include <stdio.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define DEPT_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    double salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee database is full.\n");
        return;
    }

    Employee emp;
    emp.id = employeeCount + 1;

    printf("Enter employee name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter department: ");
    scanf(" %[^\n]", emp.department);

    printf("Enter salary: ");
    scanf("%lf", &emp.salary);

    employees[employeeCount++] = emp;
    printf("Employee added successfully with ID %d.\n", emp.id);
}

void displayAll() {
    if (employeeCount == 0) {
        printf("No employees found.\n");
        return;
    }

    printf("\n%-5s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("%-5s %-20s %-20s %-10s\n", "----", "--------------------", "--------------------", "----------");

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
            printf("\nEmployee Found:\n");
            printf("ID         : %d\n", employees[i].id);
            printf("Name       : %s\n", employees[i].name);
            printf("Department : %s\n", employees[i].department);
            printf("Salary     : %.2f\n", employees[i].salary);
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
            printf("Updating employee: %s\n", employees[i].name);

            printf("Enter new name: ");
            scanf(" %[^\n]", employees[i].name);

            printf("Enter new department: ");
            scanf(" %[^\n]", employees[i].department);

            printf("Enter new salary: ");
            scanf("%lf", &employees[i].salary);

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
            /* Shift remaining employees left */
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void calculateAverageSalary() {
    if (employeeCount == 0) {
        printf("No employees to calculate average salary.\n");
        return;
    }

    double total = 0;
    for (int i = 0; i < employeeCount; i++) {
        total += employees[i].salary;
    }

    printf("Average Salary: %.2f\n", total / employeeCount);
}

int main() {
    int choice;

    printf("=== Mini Employee Management System ===\n");

    do {
        printf("\n1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Calculate Average Salary\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee();           break;
            case 2: displayAll();            break;
            case 3: searchEmployee();        break;
            case 4: updateEmployee();        break;
            case 5: deleteEmployee();        break;
            case 6: calculateAverageSalary(); break;
            case 0: printf("Exiting...\n");  break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
