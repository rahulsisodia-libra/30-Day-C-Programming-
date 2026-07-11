//Write a program to Create contact management system.


#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_EMAIL_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    Contact new_contact;

    printf("Enter name: ");
    scanf(" %[^\n]", new_contact.name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", new_contact.phone);

    printf("Enter email: ");
    scanf(" %[^\n]", new_contact.email);

    contacts[contact_count++] = new_contact;
    printf("Contact added successfully!\n");
}

void display_contacts() {
    if (contact_count == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-30s\n", "No.", "Name", "Phone", "Email");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < contact_count; i++) {
        printf("%-5d %-20s %-15s %-30s\n",
               i + 1,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }
}

void search_contact() {
    char search_name[MAX_NAME_LEN];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", search_name);

    printf("\nSearch results for \"%s\":\n", search_name);
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < contact_count; i++) {
        if (strstr(contacts[i].name, search_name) != NULL) {
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("Email : %s\n", contacts[i].email);
            printf("----------------------------------------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found with name \"%s\".\n", search_name);
    }
}

void update_contact() {
    char search_name[MAX_NAME_LEN];
    int found = 0;

    printf("Enter name of contact to update: ");
    scanf(" %[^\n]", search_name);

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found! Enter new details:\n");

            printf("Enter new name: ");
            scanf(" %[^\n]", contacts[i].name);

            printf("Enter new phone number: ");
            scanf(" %[^\n]", contacts[i].phone);

            printf("Enter new email: ");
            scanf(" %[^\n]", contacts[i].email);

            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact \"%s\" not found.\n", search_name);
    }
}

void delete_contact() {
    char search_name[MAX_NAME_LEN];
    int found = 0;

    printf("Enter name of contact to delete: ");
    scanf(" %[^\n]", search_name);

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            /* Shift remaining contacts left to fill the gap */
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contact_count--;
            printf("Contact \"%s\" deleted successfully!\n", search_name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact \"%s\" not found.\n", search_name);
    }
}

int main() {
    int choice;

    printf("========================================\n");
    printf("       CONTACT MANAGEMENT SYSTEM        \n");
    printf("========================================\n");

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                update_contact();
                break;
            case 5:
                delete_contact();
                break;
            case 6:
                printf("Exiting Contact Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
