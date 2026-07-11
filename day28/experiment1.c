// Write a program to Create library management system.

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50
#define TITLE_LEN 100
#define AUTHOR_LEN 50
#define ISBN_LEN 20
#define NAME_LEN 50

/* ── Data structures ── */

typedef struct {
    int    id;
    char   title[TITLE_LEN];
    char   author[AUTHOR_LEN];
    char   isbn[ISBN_LEN];
    int    quantity;
    int    available;
} Book;

typedef struct {
    int  id;
    char name[NAME_LEN];
    int  borrowed_book_ids[10]; /* up to 10 books at a time */
    int  borrow_count;
} Member;

/* ── Global state ── */

static Book   books[MAX_BOOKS];
static int    book_count = 0;

static Member members[MAX_MEMBERS];
static int    member_count = 0;

/* ── Helper utilities ── */

static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static Book *find_book_by_id(int id) {
    for (int i = 0; i < book_count; i++)
        if (books[i].id == id) return &books[i];
    return NULL;
}

static Member *find_member_by_id(int id) {
    for (int i = 0; i < member_count; i++)
        if (members[i].id == id) return &members[i];
    return NULL;
}

/* ── Book operations ── */

static void add_book(void) {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book b = {0};
    b.id = book_count + 1;

    printf("Enter title  : ");
    fgets(b.title, TITLE_LEN, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter author : ");
    fgets(b.author, AUTHOR_LEN, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter ISBN   : ");
    fgets(b.isbn, ISBN_LEN, stdin);
    b.isbn[strcspn(b.isbn, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &b.quantity);
    clear_input_buffer();
    b.available = b.quantity;

    books[book_count++] = b;
    printf("Book added successfully (ID: %d).\n", b.id);
}

static void display_books(void) {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\n%-5s %-30s %-20s %-15s %-5s %-5s\n",
           "ID", "Title", "Author", "ISBN", "Qty", "Avail");
    printf("%-5s %-30s %-20s %-15s %-5s %-5s\n",
           "---", "------------------------------",
           "--------------------", "---------------", "---", "-----");
    for (int i = 0; i < book_count; i++) {
        printf("%-5d %-30s %-20s %-15s %-5d %-5d\n",
               books[i].id, books[i].title, books[i].author,
               books[i].isbn, books[i].quantity, books[i].available);
    }
    printf("\n");
}

static void search_book(void) {
    char keyword[TITLE_LEN];
    printf("Enter title or author to search: ");
    fgets(keyword, TITLE_LEN, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(books[i].title,  keyword) ||
            strstr(books[i].author, keyword)) {
            if (!found)
                printf("\n%-5s %-30s %-20s %-15s %-5s %-5s\n",
                       "ID", "Title", "Author", "ISBN", "Qty", "Avail");
            printf("%-5d %-30s %-20s %-15s %-5d %-5d\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].isbn, books[i].quantity, books[i].available);
            found = 1;
        }
    }
    if (!found) printf("No matching books found.\n");
    else        printf("\n");
}

static void delete_book(void) {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    clear_input_buffer();

    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            if (books[i].available != books[i].quantity) {
                printf("Cannot delete: some copies are currently borrowed.\n");
                return;
            }
            /* shift left */
            for (int j = i; j < book_count - 1; j++)
                books[j] = books[j + 1];
            book_count--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

/* ── Member operations ── */

static void add_member(void) {
    if (member_count >= MAX_MEMBERS) {
        printf("Member limit reached.\n");
        return;
    }

    Member m = {0};
    m.id = member_count + 1;

    printf("Enter member name: ");
    fgets(m.name, NAME_LEN, stdin);
    m.name[strcspn(m.name, "\n")] = '\0';

    members[member_count++] = m;
    printf("Member added successfully (ID: %d).\n", m.id);
}

static void display_members(void) {
    if (member_count == 0) {
        printf("No members registered.\n");
        return;
    }
    printf("\n%-5s %-30s %-15s\n", "ID", "Name", "Books Borrowed");
    printf("%-5s %-30s %-15s\n", "---",
           "------------------------------", "--------------");
    for (int i = 0; i < member_count; i++) {
        printf("%-5d %-30s %-15d\n",
               members[i].id, members[i].name, members[i].borrow_count);
    }
    printf("\n");
}

/* ── Borrow / Return ── */

static void borrow_book(void) {
    int mid, bid;
    printf("Enter member ID : ");
    scanf("%d", &mid);
    clear_input_buffer();

    Member *m = find_member_by_id(mid);
    if (!m) { printf("Member not found.\n"); return; }

    if (m->borrow_count >= 10) {
        printf("Member has reached the borrowing limit (10 books).\n");
        return;
    }

    printf("Enter book ID   : ");
    scanf("%d", &bid);
    clear_input_buffer();

    Book *b = find_book_by_id(bid);
    if (!b) { printf("Book not found.\n"); return; }

    if (b->available == 0) {
        printf("No copies available for \"%s\".\n", b->title);
        return;
    }

    /* check member hasn't already borrowed the same book */
    for (int i = 0; i < m->borrow_count; i++) {
        if (m->borrowed_book_ids[i] == bid) {
            printf("Member has already borrowed this book.\n");
            return;
        }
    }

    b->available--;
    m->borrowed_book_ids[m->borrow_count++] = bid;
    printf("\"%s\" issued to %s successfully.\n", b->title, m->name);
}

static void return_book(void) {
    int mid, bid;
    printf("Enter member ID : ");
    scanf("%d", &mid);
    clear_input_buffer();

    Member *m = find_member_by_id(mid);
    if (!m) { printf("Member not found.\n"); return; }

    printf("Enter book ID   : ");
    scanf("%d", &bid);
    clear_input_buffer();

    /* find the book in member's borrowed list */
    int idx = -1;
    for (int i = 0; i < m->borrow_count; i++) {
        if (m->borrowed_book_ids[i] == bid) { idx = i; break; }
    }

    if (idx == -1) {
        printf("This member has not borrowed book ID %d.\n", bid);
        return;
    }

    Book *b = find_book_by_id(bid);
    if (b) b->available++;

    /* remove from member's list */
    for (int i = idx; i < m->borrow_count - 1; i++)
        m->borrowed_book_ids[i] = m->borrowed_book_ids[i + 1];
    m->borrow_count--;

    printf("Book returned successfully.\n");
}

static void view_member_books(void) {
    int mid;
    printf("Enter member ID: ");
    scanf("%d", &mid);
    clear_input_buffer();

    Member *m = find_member_by_id(mid);
    if (!m) { printf("Member not found.\n"); return; }

    printf("\nBooks currently borrowed by %s:\n", m->name);
    if (m->borrow_count == 0) {
        printf("  (none)\n\n");
        return;
    }
    printf("%-5s %-30s %-20s\n", "ID", "Title", "Author");
    for (int i = 0; i < m->borrow_count; i++) {
        Book *b = find_book_by_id(m->borrowed_book_ids[i]);
        if (b)
            printf("%-5d %-30s %-20s\n", b->id, b->title, b->author);
    }
    printf("\n");
}

/* ── Menus ── */

static void book_menu(void) {
    int choice;
    do {
        printf("\n=== Book Management ===\n");
        printf("1. Add book\n");
        printf("2. Display all books\n");
        printf("3. Search book\n");
        printf("4. Delete book\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: add_book();      break;
            case 2: display_books(); break;
            case 3: search_book();   break;
            case 4: delete_book();   break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}

static void member_menu(void) {
    int choice;
    do {
        printf("\n=== Member Management ===\n");
        printf("1. Add member\n");
        printf("2. Display all members\n");
        printf("3. View borrowed books\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: add_member();        break;
            case 2: display_members();   break;
            case 3: view_member_books(); break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}

static void transaction_menu(void) {
    int choice;
    do {
        printf("\n=== Transactions ===\n");
        printf("1. Issue book\n");
        printf("2. Return book\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: borrow_book(); break;
            case 2: return_book(); break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}

/* ── Entry point ── */

int main(void) {
    int choice;

    printf("====================================\n");
    printf("   Welcome to Library Management    \n");
    printf("====================================\n");

    do {
        printf("\n=== Main Menu ===\n");
        printf("1. Book management\n");
        printf("2. Member management\n");
        printf("3. Issue / Return book\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: book_menu();        break;
            case 2: member_menu();      break;
            case 3: transaction_menu(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);

    return 0;
}
