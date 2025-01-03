#include <stdio.h>
#define MAX_IOCS 10

struct IOC {
    char type[20];
    char value[50];
};

void addIOC(struct IOC iocs[MAX_IOCS], int *iocCount) {
    printf("Enter the IOC type: ");
    fgets(iocs[*iocCount].type, 20, stdin);
    printf("Enter the IOC value: ");
    fgets(iocs[*iocCount].value, 50, stdin);
    (*iocCount)++;
}

void displayIOCs(struct IOC iocs[MAX_IOCS], int iocCount) {
    for (int i = 0; i < iocCount; i++) {
        printf("%s: %s\n", iocs[i].type, iocs[i].value);
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

        if (choice == 1) {
            addIOC(iocs, &iocCount);
        } else if (choice == 2) {
            displayIOCs(iocs, iocCount);
        }
    } while (choice != 3);

    return 0;
}
