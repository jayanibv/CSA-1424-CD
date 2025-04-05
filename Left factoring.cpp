#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char *nonTerminal, char *production) {
    char commonPrefix[50], remaining1[50], remaining2[50], newNonTerminal[5];
    int i = 0, j = 0;

    // Find common prefix
    while (production[i] != '\0' && production[i] != '|') {
        commonPrefix[j++] = production[i++];
    }
    commonPrefix[j] = '\0';

    // Split production into parts after common prefix
    if (production[i] == '|') i++;
    j = 0;
    while (production[i] != '\0') {
        remaining2[j++] = production[i++];
    }
    remaining2[j] = '\0';

    // Create new productions
    sprintf(newNonTerminal, "%s'", nonTerminal);
    printf("%s -> %s%s\n", nonTerminal, commonPrefix, newNonTerminal);
    printf("%s -> %s | e\n", newNonTerminal, remaining2);
}

int main() {
    char nonTerminal[5], production[50];

    // Input grammar rule
    printf("Enter Non-terminal: ");
    scanf("%s", nonTerminal);
    printf("Enter Production (use | for alternates): ");
    scanf("%s", production);

    // Eliminate Left Factoring
    eliminateLeftFactoring(nonTerminal, production);

    return 0;
}
