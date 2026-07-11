// Write a program to Create menu-driven string operations system.


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 256

void to_uppercase(const char *str) {
    printf("Uppercase: ");
    for (int i = 0; str[i]; i++)
        putchar(toupper((unsigned char)str[i]));
    printf("\n");
}

void to_lowercase(const char *str) {
    printf("Lowercase: ");
    for (int i = 0; str[i]; i++)
        putchar(tolower((unsigned char)str[i]));
    printf("\n");
}

void reverse_string(const char *str) {
    int len = strlen(str);
    printf("Reversed: ");
    for (int i = len - 1; i >= 0; i--)
        putchar(str[i]);
    printf("\n");
}

void count_characters(const char *str) {
    int letters = 0, digits = 0, spaces = 0, special = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha((unsigned char)str[i]))       letters++;
        else if (isdigit((unsigned char)str[i]))  digits++;
        else if (isspace((unsigned char)str[i]))  spaces++;
        else                                       special++;
    }
    printf("Letters : %d\n", letters);
    printf("Digits  : %d\n", digits);
    printf("Spaces  : %d\n", spaces);
    printf("Special : %d\n", special);
    printf("Total   : %d\n", (int)strlen(str));
}

void check_palindrome(const char *str) {
    int len = strlen(str);
    int lo = 0, hi = len - 1;
    int is_palindrome = 1;
    while (lo < hi) {
        if (tolower((unsigned char)str[lo]) != tolower((unsigned char)str[hi])) {
            is_palindrome = 0;
            break;
        }
        lo++;
        hi--;
    }
    printf("\"%s\" is %sa palindrome.\n", str, is_palindrome ? "" : "NOT ");
}

void count_words(const char *str) {
    int count = 0;
    int in_word = 0;
    for (int i = 0; str[i]; i++) {
        if (!isspace((unsigned char)str[i])) {
            if (!in_word) { count++; in_word = 1; }
        } else {
            in_word = 0;
        }
    }
    printf("Word count: %d\n", count);
}

void find_replace(const char *str) {
    char find[MAX_LEN], replace[MAX_LEN];
    printf("Enter substring to find   : ");
    fgets(find, sizeof(find), stdin);
    find[strcspn(find, "\n")] = '\0';

    printf("Enter replacement string  : ");
    fgets(replace, sizeof(replace), stdin);
    replace[strcspn(replace, "\n")] = '\0';

    char result[MAX_LEN * 4] = "";
    const char *ptr = str;
    size_t find_len = strlen(find);
    size_t replace_len = strlen(replace);

    if (find_len == 0) {
        printf("Find string cannot be empty.\n");
        return;
    }

    while (*ptr) {
        const char *found = strstr(ptr, find);
        if (found) {
            strncat(result, ptr, found - ptr);
            strncat(result, replace, replace_len);
            ptr = found + find_len;
        } else {
            strcat(result, ptr);
            break;
        }
    }
    printf("Result: %s\n", result);
}

void string_concat(const char *str) {
    char str2[MAX_LEN];
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    printf("Concatenated: %s%s\n", str, str2);
}

void print_menu(void) {
    printf("\n===== String Operations Menu =====\n");
    printf(" 1. Convert to Uppercase\n");
    printf(" 2. Convert to Lowercase\n");
    printf(" 3. Reverse String\n");
    printf(" 4. Count Characters\n");
    printf(" 5. Check Palindrome\n");
    printf(" 6. Count Words\n");
    printf(" 7. Find and Replace\n");
    printf(" 8. Concatenate Strings\n");
    printf(" 9. Enter New String\n");
    printf(" 0. Exit\n");
    printf("==================================\n");
    printf("Choice: ");
}

int main(void) {
    char str[MAX_LEN];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    do {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            /* clear invalid input */
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        /* consume trailing newline */
        getchar();

        printf("\n");
        switch (choice) {
            case 1: to_uppercase(str);    break;
            case 2: to_lowercase(str);    break;
            case 3: reverse_string(str);  break;
            case 4: count_characters(str);break;
            case 5: check_palindrome(str);break;
            case 6: count_words(str);     break;
            case 7: find_replace(str);    break;
            case 8: string_concat(str);   break;
            case 9:
                printf("Enter a new string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';
                printf("String updated.\n");
                break;
            case 0:
                printf("Exiting. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
