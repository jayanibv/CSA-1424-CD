#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char identifier[50];
    char type[20];
    int address;
} Symbol;

Symbol symbolTable[MAX];
int count = 0;

void insertSymbol(char *identifier, char *type, int address) {
    strcpy(symbolTable[count].identifier, identifier);
    strcpy(symbolTable[count].type, type);
    symbolTable[count].address = address;
    count++;
    printf("Symbol inserted: %s\n", identifier);
}

void searchSymbol(char *identifier) {
    for (int i = 0; i < count; i++) {
        if (strcmp(symbolTable[i].identifier, identifier) == 0) {
            printf("Symbol found: %s, Type: %s, Address: %d\n",
                   symbolTable[i].identifier, symbolTable[i].type, symbolTable[i].address);
            return;
        }
    }
    printf("Symbol not found: %s\n", identifier);
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("Identifier\tType\tAddress\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t%d\n", symbolTable[i].identifier, symbolTable[i].type, symbolTable[i].address);
    }
}

int main() {
    int choice;
    char identifier[50], type[20];
    int address;

    while (1) {
        printf("\n1. Insert Symbol\n2. Search Symbol\n3. Display Symbol Table\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Identifier: ");
            scanf("%s", identifier);
            printf("Enter Type: ");
            scanf("%s", type);
            printf("Enter Address: ");
            scanf("%d", &address);
            insertSymbol(identifier, type, address);
            break;

        case 2:
            printf("Enter Identifier to search: ");
            scanf("%s", identifier);
            searchSymbol(identifier);
            break;

        case 3:
            displaySymbolTable();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
