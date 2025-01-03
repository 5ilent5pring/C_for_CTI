#include <stdio.h>
#define MAX_IOCS 10

void addIOC(char iocs[MAX_IOCS][50], int *iocCount) {
    printf("Enter the IOC: ");
    fgets(iocs[*iocCount], 50, stdin);
    (*iocCount)++;
}

void displayIOCs(char iocs[MAX_IOCS][50], int iocCount) {
    printf("List of IOCs:\n");
    for (int i = 0; i < iocCount; i++) {
        printf("%d. %s", i + 1, iocs[i]);
    }
}

int main() {
    char iocs[MAX_IOCS][50];
    int iocCount = 0, choice;

    do {
        printf("1. Add an IOC\n");
        printf("2. Display IOCs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            addIOC(iocs, &iocCount);
        } else if (choice == 2) {
            displayIOCs(iocs, iocCount);
        }
    } while (choice != 3);

    return 0;
}
