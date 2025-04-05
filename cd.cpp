#include <stdio.h>
#include <ctype.h>

int main() {
    char identifier[100];
    int i = 0, valid = 1;

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    // Check if first character is valid
    if (!(isalpha(identifier[0]) || identifier[0] == '_')) {
        valid = 0;
    } else {
        // Check remaining characters
        for (i = 1; identifier[i] != '\0'; i++) {
            if (!(isalnum(identifier[i]) || identifier[i] == '_')) {
                valid = 0;
                break;
            }
        }
    }

    if (valid)
        printf("Valid Identifier\n");
    else
        printf("Invalid Identifier\n");

    return 0;
}
