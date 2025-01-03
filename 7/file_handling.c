#include <stdio.h>
#include <string.h>

#define MAX_IOCS 10

struct IOC {
    char type[20];
    char value[50];
};

void saveIOCsToFile(struct IOC iocs[MAX_IOCS], int iocCount) {
    FILE *file = fopen("iocs.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < iocCount; i++) {
        fprintf(file, "%s,%s\n", iocs[i].type, iocs[i].value);
    }

    fclose(file);
    printf("IOCs saved to file successfully.\n");
}

void loadIOCsFromFile(struct IOC iocs[MAX_IOCS], int *iocCount) {
    FILE *file = fopen("iocs.txt", "r");
    if (file == NULL) {
        printf("No file found to load IOCs.\n");
        return;
    }

    *iocCount = 0;
    while (fscanf(file, "%[^,],%[^\n]\n", iocs[*iocCount].type, iocs[*iocCount].value) != EOF) {
        (*iocCount)++;
    }

    fclose(file);
    printf("IOCs loaded from file successfully.\n");
}

int main() {
    struct IOC iocs[MAX_IOCS];
    int iocCount = 0, choice;

    loadIOCsFromFile(iocs, &iocCount);

    do {
        printf("1. Add an IOC\n");
        printf("2. Display IOCs\n");
        printf("3. Save IOCs to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (iocCount < MAX_IOCS) {
                    printf("Enter the type of IOC: ");
                    fgets(iocs[iocCount].type, 20, stdin);
                    strtok(iocs[iocCount].type, "\n");

                    printf("Enter the value of IOC: ");
                    fgets(iocs[iocCount].value, 50, stdin);
                    strtok(iocs[iocCount].value, "\n");

                    iocCount++;
                } else {
                    printf("IOC list is full!\n");
                }
                break;
            case 2:
                for (int i = 0; i < iocCount; i++) {
                    printf("%d. Type: %s, Value: %s\n", i + 1, iocs[i].type, iocs[i].value);
                }
                break;
            case 3:
                saveIOCsToFile(iocs, iocCount);
                break;
            case 4:
                printf("Exiting and saving IOCs.\n");
                saveIOCsToFile(iocs, iocCount);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
