#import <stdio.h>
#import <float.h>

int main () {
    char operator;
    double result, x, y;

    printf("Zadej znamenko [+, -, *, /]: ");
    scanf(" %c", &operator);

    printf("Zadej dve cislice: ");
    scanf(" %lf %lf", &x, &y);

    switch (operator) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            printf("Neplatne znamenko.\n");
            return 1;
    }
        printf("%.2lf\n", result);
    return 0;
}