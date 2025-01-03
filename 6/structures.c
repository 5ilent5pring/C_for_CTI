#include <stdio.h>
#include <string.h>

#define MAX_IOCS 10

struct IOC {
    char type[20];
    char value[50];
};

void addIOC(struct IOC iocs[MAX_IOCS], int *iocCount) {
    printf("Enter the type of IOC (IP/Hash/Domain): ");
    fgets(iocs[*iocCount].type, 20, stdin);
    strtok(iocs[*iocCount].type, "\n");

    printf("Enter the value of the IOC: ");
    fgets(iocs[*iocCount].value, 50, stdin);
    strtok(iocs[*iocCount].value, "\n");

    (*iocCount)++;
}

void displayIOCs(struct IOC iocs[MAX_IOCS], int iocCount) {
    printf("List of IOCs:\n");
    for (int i = 0; i < iocCount; i++) {
        printf("%d. Type: %s, Value: %s\n", i + 1, iocs[i].type, iocs[i].value);
    }
}

int main() {
    struct IOC iocs[MAX_IOCS];
    int iocCount = 0, choice;

    do {
        printf("1. Add an IOC\n");
        printf("2. Display IOCs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (iocCount < MAX_IOCS) {
                    addIOC(iocs, &iocCount);
                } else {
                    printf("IOC list is full!\n");
                }
                break;
            case 2:
                displayIOCs(iocs, iocCount);
                break;
            case 3:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
