#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int isBorrowed;
    char borrower[MAX_NAME_LENGTH];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter the name of the book: ");
    getchar();
    fgets(library[bookCount].name, MAX_NAME_LENGTH, stdin);
    library[bookCount].name[strcspn(library[bookCount].name, "\n")] = '\0'; 
    library[bookCount].isBorrowed = 0;
    strcpy(library[bookCount].borrower, "");

    bookCount++;
    printf("Book added successfully.\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nAvailable books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s", i + 1, library[i].name);
        if (library[i].isBorrowed) {
            printf(" (Borrowed by %s)", library[i].borrower);
        }
        printf("\n");
    }
}

void borrowBook() {
    char bookName[MAX_NAME_LENGTH], borrower[MAX_NAME_LENGTH];

    printf("Enter the name of the book to borrow: ");
    getchar(); 
    fgets(bookName, MAX_NAME_LENGTH, stdin);
    bookName[strcspn(bookName, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].name, bookName) == 0) {
            if (library[i].isBorrowed) {
                printf("Sorry, the book is already borrowed by %s.\n", library[i].borrower);
                return;
            }

            printf("Enter the name of the borrower: ");
            fgets(borrower, MAX_NAME_LENGTH, stdin);
            borrower[strcspn(borrower, "\n")] = '\0';

            library[i].isBorrowed = 1;
            strcpy(library[i].borrower, borrower);
            printf("Book borrowed successfully.\n");
            return;
        }
    }

    printf("Sorry, the book is not available in the library.\n");
}

void returnBook() {
    char bookName[MAX_NAME_LENGTH];

    printf("Enter the name of the book to return: ");
    getchar();
    fgets(bookName, MAX_NAME_LENGTH, stdin);
    bookName[strcspn(bookName, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].name, bookName) == 0) {
            if (!library[i].isBorrowed) {
                printf("The book was not borrowed.\n");
                return;
            }

            library[i].isBorrowed = 0;
            strcpy(library[i].borrower, "");
            printf("Book returned successfully.\n");
            return;
        }
    }

    printf("The book is not part of this library.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Exiting the Library Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}