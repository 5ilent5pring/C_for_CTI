#include <stdio.h>

void displayMenu() {
    printf("1. Add an IOC\n");
    printf("2. Display IOCs\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Add IOC selected.\n");
    } else if (choice == 2) {
        printf("Display IOCs selected.\n");
    } else {
        printf("Exiting system.\n");
    }

    return 0;
}
