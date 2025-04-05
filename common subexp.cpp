#include <stdio.h>
#include <string.h>

void eliminateCommonSubexpression(char expressions[][50], int n) {
    char optimized[n][50];
    int optimizedCount = 0;

    printf("Original Expressions:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", expressions[i]);
    }

    for (int i = 0; i < n; i++) {
        int isCommon = 0;
        for (int j = 0; j < optimizedCount; j++) {
            if (strcmp(expressions[i], optimized[j]) == 0) {
                isCommon = 1;
                break;
            }
        }
        if (!isCommon) {
            strcpy(optimized[optimizedCount++], expressions[i]);
        }
    }

    printf("\nOptimized Expressions:\n");
    for (int i = 0; i < optimizedCount; i++) {
        printf("%s\n", optimized[i]);
    }
}

int main() {
    char expressions[5][50] = {
        "t1 = a + b",
        "t2 = c + d",
        "t3 = a + b", // Common subexpression
        "t4 = t1 * t2",
        "t5 = t1 + t2" // Common subexpression
    };

    int n = 5;

    eliminateCommonSubexpression(expressions, n);

    return 0;
}
