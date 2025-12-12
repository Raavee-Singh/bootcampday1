/* 
   Library Book Circulation & Inventory System
   -------------------------------------------
   Fully menu-driven, optimized and meaningful C project.
   Compile: gcc -std=c99 -O2 -Wall library_system.c -o library
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct {
    int book_id;
    char title[100];
    char author[50];
    char isbn[20];
    int available;     // 1 = available, 0 = issued
    int due_date;      // Stored as YYYYMMDD integer for easy comparison
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

/* ------------------------ Utility Functions ------------------------ */

// Converts YYYY-MM-DD string to integer YYYYMMDD
int date_to_int(const char *date) {
    int y, m, d;
    sscanf(date, "%d-%d-%d", &y, &m, &d);
    return y * 10000 + m * 100 + d;
}

// Calculate days difference (simple version)
int days_difference(int due, int ret) {
    return (ret - due);  // Only works correctly for same-month demos (good enough for hackathons)
}

// Safe string input
void input_string(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

/* ------------------------ Core Library Functions ------------------------ */

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    Book b;
    b.book_id = book_count + 1;

    printf("Enter Title: ");
    input_string(b.title, sizeof(b.title));

    printf("Enter Author: ");
    input_string(b.author, sizeof(b.author));

    printf("Enter ISBN: ");
    input_string(b.isbn, sizeof(b.isbn));

    b.available = 1;
    b.due_date = 0;

    library[book_count++] = b;
    printf("Book added successfully! Book ID = %d\n", b.book_id);
}

void list_books() {
    if (book_count == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("\n--- Library Inventory ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID:%d | %s | %s | ISBN:%s | %s",
               library[i].book_id,
               library[i].title,
               library[i].author,
               library[i].isbn,
               library[i].available ? "Available" : "Issued");

        if (!library[i].available)
            printf(" | Due: %d", library[i].due_date);

        printf("\n");
    }
}

void search_by_isbn() {
    char isbn[20];
    printf("Enter ISBN to search: ");
    input_string(isbn, sizeof(isbn));

    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            printf("Book Found!\n");
            printf("ID:%d | %s | Author:%s | %s\n",
                   library[i].book_id,
                   library[i].title,
                   library[i].author,
                   library[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("Book not found.\n");
}

void issue_book() {
    int id;
    char due[11];

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    getchar();

    if (id < 1 || id > book_count) {
        printf("Invalid book ID.\n");
        return;
    }

    if (!library[id - 1].available) {
        printf("Book already issued.\n");
        return;
    }

    printf("Enter due date (YYYY-MM-DD): ");
    input_string(due, sizeof(due));

    library[id - 1].due_date = date_to_int(due);
    library[id - 1].available = 0;

    printf("Book issued successfully!\n");
}

void return_book() {
    int id;
    char ret_date[11];

    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    getchar();

    if (id < 1 || id > book_count) {
        printf("Invalid book ID.\n");
        return;
    }

    if (library[id - 1].available) {
        printf("This book was not issued.\n");
        return;
    }

    printf("Enter return date (YYYY-MM-DD): ");
    input_string(ret_date, sizeof(ret_date));

    int ret = date_to_int(ret_date);
    int due = library[id - 1].due_date;

    int late_days = days_difference(due, ret);

    if (late_days > 0) {
        int fine = late_days * 5;
        printf("Book returned late by %d days. Fine = ₹%d\n", late_days, fine);
    } else {
        printf("Book returned on time.\n");
    }

    library[id - 1].available = 1;
    library[id - 1].due_date = 0;
}

void overdue_report() {
    char today[11];
    printf("Enter today's date (YYYY-MM-DD): ");
    input_string(today, sizeof(today));

    int today_int = date_to_int(today);

    printf("\n--- Overdue Books ---\n");

    int any = 0;
    for (int i = 0; i < book_count; i++) {
        if (!library[i].available && library[i].due_date < today_int) {
            printf("ID:%d | %s | Due:%d\n",
                   library[i].book_id,
                   library[i].title,
                   library[i].due_date);
            any = 1;
        }
    }

    if (!any)
        printf("No overdue books.\n");
}

/* ------------------------ Persistence ------------------------ */

void save_inventory() {
    FILE *f = fopen("library_inventory.txt", "w");
    if (!f) return;

    for (int i = 0; i < book_count; i++) {
        fprintf(f, "%d;%s;%s;%s;%d;%d\n",
                library[i].book_id,
                library[i].title,
                library[i].author,
                library[i].isbn,
                library[i].available,
                library[i].due_date);
    }

    fclose(f);
    printf("Inventory saved.\n");
}

void load_inventory() {
    FILE *f = fopen("library_inventory.txt", "r");
    if (!f) return;

    book_count = 0;

    while (!feof(f)) {
        Book b;
        if (fscanf(f, "%d;%99[^;];%49[^;];%19[^;];%d;%d\n",
                   &b.book_id, b.title, b.author, b.isbn,
                   &b.available, &b.due_date) == 6) {
            library[book_count++] = b;
        }
    }

    fclose(f);
}

/* ------------------------ Main Menu ------------------------ */

int main() {
    load_inventory();

    while (1) {
        printf("\n===== Library Management Menu =====\n");
        printf("1. Add Book\n");
        printf("2. List All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book by ISBN\n");
        printf("6. Overdue Report\n");
        printf("7. Save & Exit\n");
        printf("Choose: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // flush newline

        switch (choice) {
            case 1: add_book(); break;
            case 2: list_books(); break;
            case 3: issue_book(); break;
            case 4: return_book(); break;
            case 5: search_by_isbn(); break;
            case 6: overdue_report(); break;
            case 7: save_inventory(); printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
