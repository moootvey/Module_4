#include <stdio.h>
#include <stdlib.h>

extern int multiply(int a, int b);
extern int division(int a, int b);

int main() {
    int ch;
    printf("1) Multiply\n2) Division\nEnter another number to exit the program\n");
    printf("Enter num of func: ");
    scanf("%d", &ch);
    int a, b;
    int result;
    switch (ch) {
        case 1:
            printf("\nEnter first number: ");
            scanf("%d", &a);
            printf("Enter second number: ");
            scanf("%d", &b);
            result = multiply(a, b);
            printf("Multiplication result: %d\n", result);
            exit(EXIT_SUCCESS);
        case 2:
            printf("\nEnter first number: ");
            scanf("%d", &a);
            printf("Enter second number: ");
            scanf("%d", &b);
            result = division(a, b);
            printf("Division result: %d\n", result);
            exit(EXIT_SUCCESS);
        default:
            printf("Exiting...");
            exit(EXIT_SUCCESS);
    }
}
