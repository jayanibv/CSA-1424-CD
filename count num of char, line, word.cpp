#include <stdio.h>

int main() {
    char c;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Enter text (press Ctrl+D to end input on Linux/Mac or Ctrl+Z on Windows):\n");

    while ((c = getchar()) != EOF) {
        characters++;

        if (c == '\n') {
            lines++;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            if (inWord) {
                words++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    // If the last word doesn't end with a space or newline
    if (inWord) {
        words++;
    }

    printf("\nNumber of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    return 0;
}
