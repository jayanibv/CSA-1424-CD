#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[100];
int i = 0;

// Function prototypes
void E();
void EPrime();
void T();
void TPrime();
void F();

void E() {
    T();
    EPrime();
}

void EPrime() {
    if (input[i] == '+') {
        i++;
        T();
        EPrime();
    }
}

void T() {
    F();
    TPrime();
}

void TPrime() {
    if (input[i] == '*') {
        i++;
        F();
        TPrime();
    }
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            printf("Error: Missing closing parenthesis\n");
        }
    } else if (isalnum(input[i])) {
        i++; // Accept identifier or constant
    } else {
        printf("Error: Invalid character\n");
    }
}

int main() {
    printf("Enter the expression: ");
    scanf("%s", input);

    E(); // Start parsing from the start symbol

    if (input[i] == '\0') {
        printf("Expression is valid according to the grammar\n");
    } else {
        printf("Error: Expression is invalid\n");
    }

    return 0;
}
