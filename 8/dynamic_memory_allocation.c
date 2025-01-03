#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IOC {
    char type[20];
    char value[50];
};

struct IOC *addIOC(struct IOC *iocs, int *iocCount, int *capacity) {
    if (*iocCount == *capacity) {
        *capacity *= 2;
        iocs = realloc(iocs, (*capacity) * sizeof(struct IOC));
        if (iocs == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter the type of IOC (IP/Hash/Domain): ");
    fgets(iocs[*iocCount].type, 20, stdin);
    strtok(iocs[*iocCount].type, "\n");

    printf("Enter the value of the IOC: ");
    fgets(iocs[*iocCount].value, 50, stdin);
    strtok(iocs[*iocCount].value, "\n");

    (*iocCount)++;
    return iocs;
}

void displayIOCs(struct IOC *iocs, int iocCount) {
    if (iocCount == 0) {
        printf("No IOCs to display.\n");
    } else {
        printf("List of IOCs:\n");
        for (int i = 0; i < iocCount; i++) {
            printf("%d. Type: %s, Value: %s\n", i + 1, iocs[i].type, iocs[i].value);
        }
    }
}

int main() {
    int capacity = 2, iocCount = 0, choice;
    struct IOC *iocs = malloc(capacity * sizeof(struct IOC));
    if (iocs == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\nCyber Threat Intelligence Tool\n");
        printf("1. Add an IOC\n");
        printf("2. Display IOCs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                iocs = addIOC(iocs, &iocCount, &capacity);
                break;
            case 2:
                displayIOCs(iocs, iocCount);
                break;
            case 3:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    free(iocs);
    return 0;
}
