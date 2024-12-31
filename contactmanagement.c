#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100
struct Contact {
    char name[50];
    char phone[15];
};
void addContact(struct Contact *contacts, int *count) {
    if (*count < MAX_CONTACTS) {
        printf("\nEnter Name: ");
        getchar(); 
        fgets(contacts[*count].name, 50, stdin);
        contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; 

        printf("Enter Phone: ");
        fgets(contacts[*count].phone, 15, stdin);
        contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; 
        
        (*count)++;
        printf("\nContact added successfully!\n");
    } else {
        printf("\nContact list is full!\n");
    }
}
void displayContacts(struct Contact *contacts, int count) {
    if (count == 0) {
        printf("\nNo contacts to display.\n");
        return;
    }
    
    printf("\nList of Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("\nContact %d\n", i+1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0; 
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                printf("\nExiting... Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
