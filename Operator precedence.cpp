#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double evaluateExpression(char **expression);
double parseTerm(char **expression);
double parseFactor(char **expression);
double parseNumber(char **expression);

// Function to evaluate the entire expression
double evaluateExpression(char **expression) {
    double value = parseTerm(expression);
    while (**expression == '+' || **expression == '-') {
        char op = **expression;
        (*expression)++;
        double term = parseTerm(expression);
        if (op == '+')
            value += term;
        else
            value -= term;
    }
    return value;
}

// Handle multiplication and division
double parseTerm(char **expression) {
    double value = parseFactor(expression);
    while (**expression == '*' || **expression == '/') {
        char op = **expression;
        (*expression)++;
        double factor = parseFactor(expression);
        if (op == '*')
            value *= factor;
        else
            value /= factor;
    }
    return value;
}

// Handle numbers and parentheses
double parseFactor(char **expression) {
    double value = 0.0;
    if (**expression == '(') {
        (*expression)++;  // Skip '('
        value = evaluateExpression(expression);
        if (**expression == ')') {
            (*expression)++;  // Skip ')'
        } else {
            printf("Error: Missing closing parenthesis.\n");
            exit(1);
        }
    } else if (isdigit(**expression)) {
        value = strtod(*expression, expression);
    } else {
        printf("Error: Invalid character '%c' in expression.\n", **expression);
        exit(1);
    }
    return value;
}

int main() {
    char expression[100];
    printf("Enter a mathematical expression (e.g., (3+2)*4-2): ");
    scanf("%s", expression);

    char *exprPtr = expression;
    double result = evaluateExpression(&exprPtr);

    if (*exprPtr != '\0') {
        printf("Error: Unexpected character '%c' at end of expression.\n", *exprPtr);
        return 1;
    }

    printf("The result is: %.2f\n", result);
    return 0;
}
