// Write a program to Create ATM simulation.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define PIN_LENGTH 5
#define NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[NAME_LENGTH];
    char pin[PIN_LENGTH];
    double balance;
    int is_active;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;
int current_account_index = -1;

void initialize_accounts() {
    // Pre-load some accounts for demonstration
    accounts[0].account_number = 1001;
    strcpy(accounts[0].name, "Alice Johnson");
    strcpy(accounts[0].pin, "1234");
    accounts[0].balance = 5000.00;
    accounts[0].is_active = 1;

    accounts[1].account_number = 1002;
    strcpy(accounts[1].name, "Bob Smith");
    strcpy(accounts[1].pin, "5678");
    accounts[1].balance = 3500.50;
    accounts[1].is_active = 1;

    accounts[2].account_number = 1003;
    strcpy(accounts[2].name, "Carol White");
    strcpy(accounts[2].pin, "9012");
    accounts[2].balance = 12000.75;
    accounts[2].is_active = 1;

    account_count = 3;
}

int find_account(int account_number) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number && accounts[i].is_active) {
            return i;
        }
    }
    return -1;
}

int verify_pin(int index, const char *pin) {
    return strcmp(accounts[index].pin, pin) == 0;
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void display_header() {
    printf("\n");
    printf("  ╔══════════════════════════════════╗\n");
    printf("  ║        KIRO BANK ATM             ║\n");
    printf("  ║     Your Trusted Bank Partner    ║\n");
    printf("  ╚══════════════════════════════════╝\n");
    printf("\n");
}

void display_main_menu() {
    printf("  ┌──────────────────────────────────┐\n");
    printf("  │           MAIN MENU              │\n");
    printf("  ├──────────────────────────────────┤\n");
    printf("  │  1. Check Balance                │\n");
    printf("  │  2. Deposit Money                │\n");
    printf("  │  3. Withdraw Money               │\n");
    printf("  │  4. Transfer Money               │\n");
    printf("  │  5. Change PIN                   │\n");
    printf("  │  6. Exit                         │\n");
    printf("  └──────────────────────────────────┘\n");
    printf("\n  Enter your choice: ");
}

void check_balance() {
    printf("\n  ┌──────────────────────────────────┐\n");
    printf("  │         ACCOUNT BALANCE          │\n");
    printf("  ├──────────────────────────────────┤\n");
    printf("  │  Account: %d                  │\n", accounts[current_account_index].account_number);
    printf("  │  Name: %-28s│\n", accounts[current_account_index].name);
    printf("  │  Balance: $%-23.2f│\n", accounts[current_account_index].balance);
    printf("  └──────────────────────────────────┘\n");
}

void deposit_money() {
    double amount;
    printf("\n  ┌──────────────────────────────────┐\n");
    printf("  │           DEPOSIT MONEY          │\n");
    printf("  └──────────────────────────────────┘\n");
    printf("\n  Enter deposit amount: $");
    
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("\n  [!] Invalid amount. Please enter a positive value.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    
    if (amount > 50000) {
        printf("\n  [!] Maximum deposit limit is $50,000 per transaction.\n");
        return;
    }
    
    accounts[current_account_index].balance += amount;
    printf("\n  [✓] Successfully deposited: $%.2f\n", amount);
    printf("  [✓] New balance: $%.2f\n", accounts[current_account_index].balance);
}

void withdraw_money() {
    double amount;
    printf("\n  ┌──────────────────────────────────┐\n");
    printf("  │          WITHDRAW MONEY          │\n");
    printf("  └──────────────────────────────────┘\n");
    printf("\n  Current balance: $%.2f\n", accounts[current_account_index].balance);
    printf("  Enter withdrawal amount: $");
    
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("\n  [!] Invalid amount. Please enter a positive value.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    
    if (amount > 10000) {
        printf("\n  [!] Maximum withdrawal limit is $10,000 per transaction.\n");
        return;
    }
    
    if (amount > accounts[current_account_index].balance) {
        printf("\n  [!] Insufficient funds. Your balance is $%.2f\n", 
               accounts[current_account_index].balance);
        return;
    }
    
    accounts[current_account_index].balance -= amount;
    printf("\n  [✓] Successfully withdrawn: $%.2f\n", amount);
    printf("  [✓] Remaining balance: $%.2f\n", accounts[current_account_index].balance);
}

void transfer_money() {
    int target_account_number;
    double amount;
    
    printf("\n  ┌──────────────────────────────────┐\n");
    printf("  │          TRANSFER MONEY          │\n");
    printf("  └──────────────────────────────────┘\n");
    printf("\n  Current balance: $%.2f\n", accounts[current_account_index].balance);
    printf("  Enter target account number: ");
    
    if (scanf("%d", &target_account_number) != 1) {
        printf("\n  [!] Invalid account number.\n");
        while (getchar() != '\n');
        return;
    }
    
    if (target_account_number == accounts[current_account_index].account_number) {
        printf("\n  [!] Cannot transfer to your own account.\n");
        return;
    }
    
    int target_index = find_account(target_account_number);
    if (target_index == -1) {
        printf("\n  [!] Account %d not found.\n", target_account_number);
        return;
    }
    
    printf("  Transfer to: %s\n", accounts[target_index].name);
    printf("  Enter transfer amount: $");
    
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("\n  [!] Invalid amount.\n");
        while (getchar() != '\n');
        return;
    }
    
    if (amount > accounts[current_account_index].balance) {
        printf("\n  [!] Insufficient funds. Your balance is $%.2f\n", 
               accounts[current_account_index].balance);
        return;
    }
    
    accounts[current_account_index].balance -= amount;
    accounts[target_index].balance += amount;
    
    printf("\n  [✓] Successfully transferred: $%.2f\n", amount);
    printf("  [✓] To: %s (Account: %d)\n", accounts[target_index].name, target_account_number);
    printf("  [✓] Your remaining balance: $%.2f\n", accounts[current_account_index].balance);
}

void change_pin() {
    char current_pin[PIN_LENGTH];
    char new_pin[PIN_LENGTH];
    char confirm_pin[PIN_LENGTH];
    
    printf("\n  ┌──────────────────────────────────┐\n");
    printf("  │            CHANGE PIN            │\n");
    printf("  └──────────────────────────────────┘\n");
    printf("\n  Enter current PIN: ");
    scanf("%4s", current_pin);
    
    if (!verify_pin(current_account_index, current_pin)) {
        printf("\n  [!] Incorrect current PIN.\n");
        return;
    }
    
    printf("  Enter new 4-digit PIN: ");
    scanf("%4s", new_pin);
    
    // Validate PIN is 4 digits
    int valid = 1;
    if (strlen(new_pin) != 4) {
        valid = 0;
    } else {
        for (int i = 0; i < 4; i++) {
            if (new_pin[i] < '0' || new_pin[i] > '9') {
                valid = 0;
                break;
            }
        }
    }
    
    if (!valid) {
        printf("\n  [!] PIN must be exactly 4 digits.\n");
        return;
    }
    
    printf("  Confirm new PIN: ");
    scanf("%4s", confirm_pin);
    
    if (strcmp(new_pin, confirm_pin) != 0) {
        printf("\n  [!] PINs do not match. PIN not changed.\n");
        return;
    }
    
    strcpy(accounts[current_account_index].pin, new_pin);
    printf("\n  [✓] PIN changed successfully.\n");
}

int login() {
    int account_number;
    char pin[PIN_LENGTH];
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;
    
    printf("\n  ┌──────────────────────────────────┐\n");
    printf("  │         ACCOUNT LOGIN            │\n");
    printf("  └──────────────────────────────────┘\n");
    
    while (attempts < MAX_ATTEMPTS) {
        printf("\n  Enter account number: ");
        if (scanf("%d", &account_number) != 1) {
            printf("  [!] Invalid input.\n");
            while (getchar() != '\n');
            attempts++;
            continue;
        }
        
        int index = find_account(account_number);
        if (index == -1) {
            printf("  [!] Account not found.\n");
            attempts++;
            continue;
        }
        
        printf("  Enter PIN: ");
        scanf("%4s", pin);
        
        if (verify_pin(index, pin)) {
            current_account_index = index;
            printf("\n  [✓] Login successful! Welcome, %s.\n", accounts[index].name);
            return 1;
        } else {
            attempts++;
            printf("  [!] Incorrect PIN. Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
        }
    }
    
    printf("\n  [!] Too many failed attempts. Card blocked. Please contact bank.\n");
    return 0;
}

int main() {
    initialize_accounts();
    
    while (1) {
        clear_screen();
        display_header();
        
        printf("  Welcome to Kiro Bank ATM\n");
        printf("  ─────────────────────────────────\n");
        printf("  1. Insert Card (Login)\n");
        printf("  2. Exit\n");
        printf("\n  Choice: ");
        
        int choice;
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        
        if (choice == 2) {
            printf("\n  Thank you for using Kiro Bank ATM.\n");
            printf("  Have a great day!\n\n");
            break;
        }
        
        if (choice != 1) {
            printf("\n  [!] Invalid option.\n");
            printf("  Press Enter to continue...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        
        if (!login()) {
            printf("\n  Press Enter to continue...");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        
        // Main ATM session
        int session_active = 1;
        while (session_active) {
            printf("\n");
            display_main_menu();
            
            int menu_choice;
            if (scanf("%d", &menu_choice) != 1) {
                while (getchar() != '\n');
                continue;
            }
            
            switch (menu_choice) {
                case 1:
                    check_balance();
                    break;
                case 2:
                    deposit_money();
                    break;
                case 3:
                    withdraw_money();
                    break;
                case 4:
                    transfer_money();
                    break;
                case 5:
                    change_pin();
                    break;
                case 6:
                    printf("\n  [✓] Logged out successfully.\n");
                    printf("  Thank you for banking with Kiro Bank!\n");
                    current_account_index = -1;
                    session_active = 0;
                    continue;
                default:
                    printf("\n  [!] Invalid option. Please try again.\n");
                    continue;
            }
            
            printf("\n  Press Enter to continue...");
            while (getchar() != '\n');
            getchar();
        }
    }
    
    return 0;
}
