// Write a program to Create mini library system.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_ISBN_LEN 20

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char isbn[MAX_ISBN_LEN];
    int is_available;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// Initialize the library
void init_library(Library *lib) {
    lib->count = 0;
}

// Add a new book to the library
int add_book(Library *lib, const char *title, const char *author, const char *isbn) {
    if (lib->count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return -1;
    }

    Book *book = &lib->books[lib->count];
    book->id = lib->count + 1;
    strncpy(book->title, title, MAX_TITLE_LEN - 1);
    book->title[MAX_TITLE_LEN - 1] = '\0';
    strncpy(book->author, author, MAX_AUTHOR_LEN - 1);
    book->author[MAX_AUTHOR_LEN - 1] = '\0';
    strncpy(book->isbn, isbn, MAX_ISBN_LEN - 1);
    book->isbn[MAX_ISBN_LEN - 1] = '\0';
    book->is_available = 1;

    lib->count++;
    printf("Book '%s' added successfully with ID %d.\n", title, book->id);
    return book->id;
}

// Display all books in the library
void display_all_books(const Library *lib) {
    if (lib->count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n%-5s %-30s %-25s %-15s %-10s\n", "ID", "Title", "Author", "ISBN", "Status");
    printf("%-5s %-30s %-25s %-15s %-10s\n", "---", "-----", "------", "----", "------");
    for (int i = 0; i < lib->count; i++) {
        const Book *book = &lib->books[i];
        printf("%-5d %-30s %-25s %-15s %-10s\n",
               book->id,
               book->title,
               book->author,
               book->isbn,
               book->is_available ? "Available" : "Borrowed");
    }
    printf("\n");
}

// Search for a book by title
void search_by_title(const Library *lib, const char *title) {
    int found = 0;
    printf("\nSearch results for title '%s':\n", title);
    for (int i = 0; i < lib->count; i++) {
        if (strstr(lib->books[i].title, title) != NULL) {
            const Book *book = &lib->books[i];
            printf("ID: %d | Title: %s | Author: %s | ISBN: %s | Status: %s\n",
                   book->id, book->title, book->author, book->isbn,
                   book->is_available ? "Available" : "Borrowed");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with that title.\n");
    }
}

// Search for a book by author
void search_by_author(const Library *lib, const char *author) {
    int found = 0;
    printf("\nSearch results for author '%s':\n", author);
    for (int i = 0; i < lib->count; i++) {
        if (strstr(lib->books[i].author, author) != NULL) {
            const Book *book = &lib->books[i];
            printf("ID: %d | Title: %s | Author: %s | ISBN: %s | Status: %s\n",
                   book->id, book->title, book->author, book->isbn,
                   book->is_available ? "Available" : "Borrowed");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by that author.\n");
    }
}

// Borrow a book by ID
int borrow_book(Library *lib, int id) {
    for (int i = 0; i < lib->count; i++) {
        if (lib->books[i].id == id) {
            if (lib->books[i].is_available) {
                lib->books[i].is_available = 0;
                printf("You have successfully borrowed '%s'.\n", lib->books[i].title);
                return 0;
            } else {
                printf("Sorry, '%s' is currently not available.\n", lib->books[i].title);
                return -1;
            }
        }
    }
    printf("Book with ID %d not found.\n", id);
    return -1;
}

// Return a book by ID
int return_book(Library *lib, int id) {
    for (int i = 0; i < lib->count; i++) {
        if (lib->books[i].id == id) {
            if (!lib->books[i].is_available) {
                lib->books[i].is_available = 1;
                printf("Thank you for returning '%s'.\n", lib->books[i].title);
                return 0;
            } else {
                printf("'%s' was not marked as borrowed.\n", lib->books[i].title);
                return -1;
            }
        }
    }
    printf("Book with ID %d not found.\n", id);
    return -1;
}

// Remove a book from the library by ID
int remove_book(Library *lib, int id) {
    for (int i = 0; i < lib->count; i++) {
        if (lib->books[i].id == id) {
            printf("Removing book '%s'.\n", lib->books[i].title);
            // Shift remaining books left
            for (int j = i; j < lib->count - 1; j++) {
                lib->books[j] = lib->books[j + 1];
            }
            lib->count--;
            printf("Book removed successfully.\n");
            return 0;
        }
    }
    printf("Book with ID %d not found.\n", id);
    return -1;
}

// Read a string from stdin safely, stripping the newline
void read_input(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

// Print the main menu
void print_menu(void) {
    printf("\n===== Mini Library System =====\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Search by title\n");
    printf("4. Search by author\n");
    printf("5. Borrow a book\n");
    printf("6. Return a book\n");
    printf("7. Remove a book\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    Library lib;
    init_library(&lib);

    // Pre-populate with some sample books
    add_book(&lib, "The C Programming Language", "Brian Kernighan", "978-0131103627");
    add_book(&lib, "Clean Code", "Robert C. Martin", "978-0132350884");
    add_book(&lib, "The Pragmatic Programmer", "Andrew Hunt", "978-0135957059");

    char input[10];
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char isbn[MAX_ISBN_LEN];
    int choice, id;

    while (1) {
        print_menu();
        read_input(input, sizeof(input));
        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                read_input(title, sizeof(title));
                printf("Enter author: ");
                read_input(author, sizeof(author));
                printf("Enter ISBN: ");
                read_input(isbn, sizeof(isbn));
                add_book(&lib, title, author, isbn);
                break;

            case 2:
                display_all_books(&lib);
                break;

            case 3:
                printf("Enter title to search: ");
                read_input(title, sizeof(title));
                search_by_title(&lib, title);
                break;

            case 4:
                printf("Enter author to search: ");
                read_input(author, sizeof(author));
                search_by_author(&lib, author);
                break;

            case 5:
                printf("Enter book ID to borrow: ");
                read_input(input, sizeof(input));
                id = atoi(input);
                borrow_book(&lib, id);
                break;

            case 6:
                printf("Enter book ID to return: ");
                read_input(input, sizeof(input));
                id = atoi(input);
                return_book(&lib, id);
                break;

            case 7:
                printf("Enter book ID to remove: ");
                read_input(input, sizeof(input));
                id = atoi(input);
                remove_book(&lib, id);
                break;

            case 8:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
