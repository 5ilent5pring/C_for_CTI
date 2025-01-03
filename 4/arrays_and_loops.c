#include <stdio.h>
#define MAX_IOCS 10

int main() {
    char iocs[MAX_IOCS][50];
    int iocCount = 0, choice;

    do {
        printf("1. Add an IOC\n");
        printf("2. Display IOCs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        if (choice == 1 && iocCount < MAX_IOCS) {
            printf("Enter the IOC: ");
            fgets(iocs[iocCount], 50, stdin);
            iocCount++;
        } else if (choice == 2) {
            printf("List of IOCs:\n");
            for (int i = 0; i < iocCount; i++) {
                printf("%d. %s", i + 1, iocs[i]);
            }
        }
    } while (choice != 3);

    return 0;
}
