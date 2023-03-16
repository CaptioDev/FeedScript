#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// Function declarations
void print_menu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double square_root(double a);
double cube_root(double a);

// Main function
int main() {
double a, b, result;
char op;

print_menu();
printf("Enter an operation: ");
scanf("%c", &op);

switch (op) {
    case '+':
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);
        result = add(a, b);
        printf("Result: %lf\n", result);
        break;
    case '-':
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);
        result = subtract(a, b);
        printf("Result: %lf\n", result);
        break;
    case '*':
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);
        result = multiply(a, b);
        printf("Result: %lf\n", result);
        break;
    case '/':
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);
        result = divide(a, b);
        printf("Result: %lf\n", result);
        break;
    case '^':
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);
        result = power(a, b);
        printf("Result: %lf\n", result);
        break;
    case 's':
        printf("Enter a number: ");
        scanf("%lf", &a);
        result = square_root(a);
        printf("Result: %lf\n", result);
        break;
    case 'c':
        printf("Enter a number: ");
        scanf("%lf", &a);
        result = cube_root(a);
        printf("Result: %lf\n", result);
        break;
    default:
        printf("Invalid operator.\n");
        break;
}

return 0;
}

// Function implementations
void print_menu() {
printf("Calculator Menu:\n");
printf("+ : Addition\n");
printf("- : Subtraction\n");
printf("* : Multiplication\n");
printf("/ : Division\n");
printf("^ : Power\n");
printf("s : Square Root\n");
printf("c : Cube Root\n");
}

double add(double a, double b) {
return a + b;
}

double subtract(double a, double b) {
return a - b;
}

double multiply(double a, double b) {
return a * b;
}

double divide(double a, double b) {
if (b == 0) {
printf("Error: division by zero.\n");
exit(1);
}
return a / b;
}

double power(double a, double b) {
return pow(a, b);
}

double square_root(double a) {
if (a < 0) {
printf("Error: cannot calculate square root of negative number.\n");
exit(1);
}
