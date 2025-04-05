#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char *nonTerminal, char *production) {
    char alpha[50], beta[50], newNonTerminal[5];
    int i = 0, j = 0, flag = 0;

    // Check for left recursion
    if (production[0] == *nonTerminal) {
        flag = 1;

        // Separate alpha (recursive part) and beta (non-recursive part)
        i = 1;
        while (production[i] != '|' && production[i] != '\0') {
            alpha[j++] = production[i++];
        }
        alpha[j] = '\0';

        if (production[i] == '|') i++; // Skip '|'

        j = 0;
        while (production[i] != '\0') {
            beta[j++] = production[i++];
        }
        beta[j] = '\0';

        // Generate new non-terminal
        sprintf(newNonTerminal, "%s'", nonTerminal);

        // Print transformed rules
        printf("%s -> %s%s\n", nonTerminal, beta, newNonTerminal);
        printf("%s -> %s%s | e\n", newNonTerminal, alpha, newNonTerminal);
    }

    // If no left recursion, just print the original rule
    if (!flag) {
        printf("%s -> %s\n", nonTerminal, production);
    }
}

int main() {
    char nonTerminal[5], production[50];

    // Input grammar rule
    printf("Enter Non-terminal: ");
    scanf("%s", nonTerminal);
    printf("Enter Production (use | for alternates): ");
    scanf("%s", production);

    // Eliminate Left Recursion
    eliminateLeftRecursion(nonTerminal, production);

    return 0;
}
