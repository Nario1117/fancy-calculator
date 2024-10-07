#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    printf("Tell me a formula with - and + operators:\n");
    char formula[1000];
    fgets(formula, 1000, stdin);
    formula[strlen(formula) - 1] = '\0';
    strcat(formula, "+");


    int num1 = 0;
    int num2 = 0;
    char operation = '+';
    bool num1Defined = false;
    bool num2Defined = false;

    for (int i = 0; i < strlen(formula); ++i) {
        char symbol = formula[i];

        switch (symbol) {
            case ' ':
                break;
            case '+':
            case '-':
                if (num1Defined && num2Defined) {
                    if (operation == '+') {
                        num1 += num2;
                    } else if (operation == '-') {
                        num1 -= num2;
                    }
                    num2 = 0;
                    num2Defined = false;
                }
                operation = symbol;
                num1Defined = true;
                break;
            default:
                if (symbol >= '0' && symbol <= '9') {
                    if (!num1Defined) {
                        num1 = num1 * 10 + (symbol - '0');
                    } else {
                        num2 = num2 * 10 + (symbol - '0');
                        num2Defined = true;
                    }
                } else {
                    printf("\nUnknown symbol: \"%c\"\n", symbol);
                }
                break;
        }
    }

    printf("Result: %d", num1);
    return 0;
}
