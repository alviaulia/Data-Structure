#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct Stack {
    double data[MAX];
    int top;
};

void push(struct Stack *s, double value);
double pop(struct Stack *s);
double evaluate_expression(char *expr);

int main() {
    char expr[MAX];
    double result;

    printf("Masukkan soal operasi matematika: ");
    fgets(expr, MAX, stdin);

    result = evaluate_expression(expr);

    printf("Hasil: %f\n", result);

    return 0;
}

void push(struct Stack *s, double value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!");
    } else {
        s->top++;
        s->data[s->top] = value;
    }
}

double pop(struct Stack *s) {
    double value;

    if (s->top == -1) {
        printf("Stack Underflow!");
        return -1;
    } else {
        value = s->data[s->top];
        s->top--;
        return value;
    }
}

double evaluate_expression(char *expr) {
    struct Stack num_stack, op_stack;
    double num1, num2, result;
    char *token, *delim = " \t\n";
    char op;

    num_stack.top = op_stack.top = -1;

    token = strtok(expr, delim);

    while (token != NULL) {
        if (*token >= '0' && *token <= '9') {
            push(&num_stack, atof(token));
        } else if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
            while (op_stack.top != -1 && op_stack.data[op_stack.top] != '(' && ((op_stack.data[op_stack.top] == '*' || op_stack.data[op_stack.top] == '/') || (*token == '+' || *token == '-'))) {
                num2 = pop(&num_stack);
                num1 = pop(&num_stack);
                op = pop(&op_stack);

                switch (op) {
                    case '+':
                        result = num1 + num2;
                        break;
                    case '-':
                        result = num1 - num2;
                        break;
                    case '*':
                        result = num1 * num2;
                        break;
                    case '/':
                        result = num1 / num2;
                        break;
                    default:
                        printf("Invalid operator!");
                        return -1;
                }

                push(&num_stack, result);
            }

            push(&op_stack, *token);
        } else if (*token == '(') {
            push(&op_stack, *token);
        } else if (*token == ')') {
            while (op_stack.top != -1 && op_stack.data[op_stack.top] != '(') {
                num2 = pop(&num_stack);
                num1 = pop(&num_stack);
                op = pop(&op_stack);

                switch (op) {
                    case '+':
                        result = num1 + num2;
                        break;
                    case '-':
                        result = num1 - num2;
                        break;
                    case '*':
                        result = num1 * num2;
                        break;
                    case '/':
                        result = num1 / num2;
                        break;
                    default:
                        printf("Invalid operator!");
                        return -1;
                }

                push(&num_stack, result);
            }

            if (op_stack.data[op_stack.top] == '(') {
                pop(&op_stack);
            }
        }

        token = strtok(NULL, delim);
    }

    while (op_stack.top != -1) {
        num2 = pop(&num_stack);
num1 = pop(&num_stack);
op = pop(&op_stack);
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator!");
            return -1;
    }

    push(&num_stack, result);
}

return pop(&num_stack);
}

