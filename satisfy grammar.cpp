#include <stdio.h>
#include <string.h>

int checkGrammar(char *str) {
    int i = 0;

    // Check if the string starts with 'a's
    while (str[i] == 'a') {
        i++;
    }

    // The string must end with a single 'b'
    if (str[i] == 'b' && str[i + 1] == '\0') {
        return 1; // Valid string
    }

    return 0; // Invalid string
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (checkGrammar(input)) {
        printf("The string satisfies the grammar.\n");
    } else {
        printf("The string does not satisfy the grammar.\n");
    }

    return 0;
}
