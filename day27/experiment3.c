// Write a program to Create salary management system.


#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    char designation[NAME_LEN];
    double basic_salary;
    double hra;         // House Rent Allowance (20% of basic)
    double da;          // Dearness Allowance (10% of basic)
    double pf;          // Provident Fund (12% of basic)
    double tax;         // Tax (5% of gross)
    double gross_salary;
    double net_salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void calculate_salary(Employee *emp) {
    emp->hra         = 0.20 * emp->basic_salary;
    emp->da          = 0.10 * emp->basic_salary;
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    emp->pf          = 0.12 * emp->basic_salary;
    emp->tax         = 0.05 * emp->gross_salary;
    emp->net_salary  = emp->gross_salary - emp->pf - emp->tax;
}

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Employee limit reached.\n");
        return;
    }

    Employee emp;
    emp.id = employee_count + 1;

    printf("\nEnter Employee Name       : ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Designation         : ");
    scanf(" %[^\n]", emp.designation);

    printf("Enter Basic Salary (INR)  : ");
    scanf("%lf", &emp.basic_salary);

    calculate_salary(&emp);
    employees[employee_count++] = emp;

    printf("\nEmployee added successfully with ID: %d\n", emp.id);
}

void display_employee(const Employee *emp) {
    printf("\n--------------------------------------------------\n");
    printf("  Employee ID      : %d\n",   emp->id);
    printf("  Name             : %s\n",   emp->name);
    printf("  Designation      : %s\n",   emp->designation);
    printf("  Basic Salary     : %.2f\n", emp->basic_salary);
    printf("  HRA (20%%)        : %.2f\n", emp->hra);
    printf("  DA  (10%%)        : %.2f\n", emp->da);
    printf("  Gross Salary     : %.2f\n", emp->gross_salary);
    printf("  PF  (12%%)        : %.2f\n", emp->pf);
    printf("  Tax  (5%%)        : %.2f\n", emp->tax);
    printf("  Net Salary       : %.2f\n", emp->net_salary);
    printf("--------------------------------------------------\n");
}

void view_all_employees() {
    if (employee_count == 0) {
        printf("\nNo employees found.\n");
        return;
    }
    printf("\n========== All Employees ==========\n");
    for (int i = 0; i < employee_count; i++) {
        display_employee(&employees[i]);
    }
}

void search_employee() {
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            display_employee(&employees[i]);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void update_salary() {
    int id;
    printf("\nEnter Employee ID to update salary: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("Current Basic Salary: %.2f\n", employees[i].basic_salary);
            printf("Enter new Basic Salary: ");
            scanf("%lf", &employees[i].basic_salary);
            calculate_salary(&employees[i]);
            printf("Salary updated successfully.\n");
            display_employee(&employees[i]);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void delete_employee() {
    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employee_count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employee_count--;
            printf("Employee deleted successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void display_menu() {
    printf("\n========= Salary Management System =========\n");
    printf("  1. Add Employee\n");
    printf("  2. View All Employees\n");
    printf("  3. Search Employee by ID\n");
    printf("  4. Update Employee Salary\n");
    printf("  5. Delete Employee\n");
    printf("  6. Exit\n");
    printf("=============================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_employee();      break;
            case 2: view_all_employees(); break;
            case 3: search_employee();   break;
            case 4: update_salary();     break;
            case 5: delete_employee();   break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
