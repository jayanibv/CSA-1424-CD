#include <iostream>
#include <cstring>
using namespace std;

void generateAssembly(char tac[][50], int n) {
    cout << "Generated Assembly Code:\n";
    for (int i = 0; i < n; i++) {
        char op1[10], op2[10], result[10];
        char op_char;

        // Correct parsing of TAC
        if (sscanf(tac[i], "%s = %s %c %s", result, op1, &op_char, op2) != 4) {
            cout << "Error parsing TAC line: " << tac[i] << endl;
            continue;
        }

        cout << "MOV R0, " << op1 << endl;
        switch (op_char) {
            case '+':
                cout << "ADD R0, " << op2 << endl;
                break;
            case '-':
                cout << "SUB R0, " << op2 << endl;
                break;
            case '*':
                cout << "MUL R0, " << op2 << endl;
                break;
            case '/':
                cout << "DIV R0, " << op2 << endl;
                break;
            default:
                cout << "Unknown operator: " << op_char << endl;
                return;
        }
        cout << "MOV " << result << ", R0\n";
    }
}

int main() {
    char tac[5][50] = {
        "t1 = a + b",
        "t2 = t1 * c",
        "t3 = t2 - d",
        "t4 = t3 / e"
    };

    int n = 4;

    cout << "Three-Address Code:\n";
    for (int i = 0; i < n; i++) {
        cout << tac[i] << endl;
    }

    cout << endl;
    generateAssembly(tac, n);

    return 0;
}
