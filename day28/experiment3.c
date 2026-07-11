// Write a program to Create ticket booking system.


#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50
#define MAX_NAME_LEN 100

typedef struct {
    int seat_number;
    int is_booked;
    char passenger_name[MAX_NAME_LEN];
    int age;
} Seat;

typedef struct {
    int ticket_id;
    int seat_number;
    char passenger_name[MAX_NAME_LEN];
    int age;
} Ticket;

Seat seats[MAX_SEATS];
Ticket tickets[MAX_SEATS];
int ticket_count = 0;
int next_ticket_id = 1001;

void initialize_seats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seat_number = i + 1;
        seats[i].is_booked = 0;
        strcpy(seats[i].passenger_name, "");
        seats[i].age = 0;
    }
}

void display_available_seats() {
    printf("\n========== Available Seats ==========\n");
    int found = 0;
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i].is_booked) {
            printf("[%2d] ", seats[i].seat_number);
            found++;
            if (found % 10 == 0) printf("\n");
        }
    }
    if (!found) {
        printf("No seats available.\n");
    }
    printf("\n=====================================\n");
}

void display_all_seats() {
    printf("\n========== All Seats Status ==========\n");
    printf("%-10s %-15s %-5s %s\n", "Seat No.", "Status", "Age", "Passenger Name");
    printf("----------------------------------------------\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("%-10d %-15s %-5d %s\n",
               seats[i].seat_number,
               seats[i].is_booked ? "Booked" : "Available",
               seats[i].age,
               seats[i].is_booked ? seats[i].passenger_name : "-");
    }
    printf("==============================================\n");
}

void book_ticket() {
    char name[MAX_NAME_LEN];
    int age, seat_no;

    display_available_seats();

    printf("\nEnter seat number to book: ");
    if (scanf("%d", &seat_no) != 1 || seat_no < 1 || seat_no > MAX_SEATS) {
        printf("Invalid seat number.\n");
        while (getchar() != '\n');
        return;
    }

    if (seats[seat_no - 1].is_booked) {
        printf("Seat %d is already booked. Please choose another seat.\n", seat_no);
        return;
    }

    printf("Enter passenger name: ");
    while (getchar() != '\n');
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Enter passenger age: ");
    if (scanf("%d", &age) != 1 || age <= 0 || age > 120) {
        printf("Invalid age.\n");
        while (getchar() != '\n');
        return;
    }

    // Book the seat
    seats[seat_no - 1].is_booked = 1;
    strncpy(seats[seat_no - 1].passenger_name, name, MAX_NAME_LEN - 1);
    seats[seat_no - 1].age = age;

    // Create ticket
    tickets[ticket_count].ticket_id = next_ticket_id++;
    tickets[ticket_count].seat_number = seat_no;
    strncpy(tickets[ticket_count].passenger_name, name, MAX_NAME_LEN - 1);
    tickets[ticket_count].age = age;
    ticket_count++;

    printf("\n========== Booking Confirmed ==========\n");
    printf("Ticket ID     : %d\n", tickets[ticket_count - 1].ticket_id);
    printf("Seat Number   : %d\n", seat_no);
    printf("Passenger Name: %s\n", name);
    printf("Age           : %d\n", age);
    printf("========================================\n");
}

void cancel_ticket() {
    int ticket_id;
    printf("\nEnter Ticket ID to cancel: ");
    if (scanf("%d", &ticket_id) != 1) {
        printf("Invalid Ticket ID.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < ticket_count; i++) {
        if (tickets[i].ticket_id == ticket_id) {
            int seat_no = tickets[i].seat_number;

            // Free the seat
            seats[seat_no - 1].is_booked = 0;
            strcpy(seats[seat_no - 1].passenger_name, "");
            seats[seat_no - 1].age = 0;

            printf("\nTicket ID %d for seat %d (%s) has been cancelled.\n",
                   ticket_id, seat_no, tickets[i].passenger_name);

            // Remove ticket from array
            for (int j = i; j < ticket_count - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            ticket_count--;
            return;
        }
    }

    printf("Ticket ID %d not found.\n", ticket_id);
}

void view_booked_tickets() {
    if (ticket_count == 0) {
        printf("\nNo tickets booked yet.\n");
        return;
    }

    printf("\n========== Booked Tickets ==========\n");
    printf("%-12s %-10s %-5s %s\n", "Ticket ID", "Seat No.", "Age", "Passenger Name");
    printf("--------------------------------------------\n");
    for (int i = 0; i < ticket_count; i++) {
        printf("%-12d %-10d %-5d %s\n",
               tickets[i].ticket_id,
               tickets[i].seat_number,
               tickets[i].age,
               tickets[i].passenger_name);
    }
    printf("============================================\n");
    printf("Total Booked: %d / %d\n", ticket_count, MAX_SEATS);
}

int main() {
    initialize_seats();

    int choice;
    printf("======================================\n");
    printf("   Welcome to Ticket Booking System   \n");
    printf("======================================\n");

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Book a Ticket\n");
        printf("2. Cancel a Ticket\n");
        printf("3. View All Booked Tickets\n");
        printf("4. View All Seats Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                book_ticket();
                break;
            case 2:
                cancel_ticket();
                break;
            case 3:
                view_booked_tickets();
                break;
            case 4:
                display_all_seats();
                break;
            case 5:
                printf("\nThank you for using the Ticket Booking System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select from 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}
