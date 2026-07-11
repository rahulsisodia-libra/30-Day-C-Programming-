// Write a program to Create bank account system.


#include <stdio.h>


#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int account_number;
    char name[NAME_LEN];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Find account index by account number, returns -1 if not found
int find_account(int account_number) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number)
            return i;
    }
    return -1;
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return;
    }

    Account acc;
    acc.account_number = account_count + 1001; // Start account numbers at 1001

    printf("Enter account holder name: ");
    scanf(" %[^\n]", acc.name);

    printf("Enter initial deposit: ");
    scanf("%lf", &acc.balance);

    if (acc.balance < 0) {
        printf("Initial deposit cannot be negative.\n");
        return;
    }

    accounts[account_count++] = acc;
    printf("Account created successfully! Account Number: %d\n", acc.account_number);
}

void deposit() {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int idx = find_account(account_number);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }

    accounts[idx].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[idx].balance);
}

void withdraw() {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int idx = find_account(account_number);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }

    if (amount > accounts[idx].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[idx].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[idx].balance);
}

void check_balance() {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    int idx = find_account(account_number);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Account Holder: %s\n", accounts[idx].name);
    printf("Account Number: %d\n", accounts[idx].account_number);
    printf("Balance: %.2f\n", accounts[idx].balance);
}

void display_all_accounts() {
    if (account_count == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("\n%-15s %-25s %-10s\n", "Account No.", "Name", "Balance");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < account_count; i++) {
        printf("%-15d %-25s %.2f\n",
               accounts[i].account_number,
               accounts[i].name,
               accounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Bank Account System =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_account();       break;
            case 2: deposit();              break;
            case 3: withdraw();             break;
            case 4: check_balance();        break;
            case 5: display_all_accounts(); break;
            case 6:
                printf("Thank you for using the Bank Account System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
