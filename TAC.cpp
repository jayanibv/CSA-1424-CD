#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempVarCount = 1;

void generateTAC(char *expression) {
    char resultVar[10];
    char op1[10] = "", op2[10] = "", op[2] = "";
    int i = 0, j = 0;

    printf("\nThree Address Code:\n");

    // Read first operand
    while (expression[i] != '\0' && isalnum(expression[i])) {
        op1[j++] = expression[i++];
    }
    op1[j] = '\0';

    while (expression[i] != '\0') {
        j = 0;

        // Read operator
        if (strchr("+-*/", expression[i])) {
            op[0] = expression[i++];
            op[1] = '\0';
        } else {
            printf("Error: Unexpected character '%c'\n", expression[i]);
            return;
        }

        // Read next operand
        while (expression[i] != '\0' && isalnum(expression[i])) {
            op2[j++] = expression[i++];
        }
        op2[j] = '\0';

        // Generate temporary variable for result
        snprintf(resultVar, sizeof(resultVar), "t%d", tempVarCount++);
        printf("%s = %s %s %s\n", resultVar, op1, op, op2);

        // Use result as next operand
        strcpy(op1, resultVar);
    }
}

int main() {
    char expression[100];

    printf("Enter the arithmetic expression (e.g., a+b*c): ");
    scanf("%s", expression);

    generateTAC(expression);

    return 0;
}
