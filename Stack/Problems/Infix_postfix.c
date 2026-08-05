#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

int precedent(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

int isRightAssociative(char c) {
    return c == '^';
}

void InfixtoPostfix(char infix[MAX], Stack *stack) {

    char postfix[MAX];
    int i, j = 0;

    stack->top = -1;

    for (i = 0; infix[i] != '\0'; i++) {

        char c = infix[i];

        // Operand -- variables
        if (isalnum(c)) {
            postfix[j++] = c;
        }

        // Left Parenthesis
        else if (c == '(') {
            stack->arr[++stack->top] = c;
        }

        // Right Parenthesis
        else if (c == ')') {

            while (stack->top != -1 &&
                   stack->arr[stack->top] != '(') {

                postfix[j++] = stack->arr[stack->top--];
            }

            stack->top--;      // Remove '('
        }

        // Operator
        else {

            while (stack->top != -1 &&
                   stack->arr[stack->top] != '(' &&
                   (precedent(stack->arr[stack->top]) > precedent(c) ||
                   (precedent(stack->arr[stack->top]) == precedent(c)
                   && !isRightAssociative(c)))) {

                postfix[j++] = stack->arr[stack->top--];
            }

            stack->arr[++stack->top] = c;
        }
    }

    // Pop remaining operators
    while (stack->top != -1) {
        postfix[j++] = stack->arr[stack->top--];
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {

    char infix[MAX];
    Stack stack;

    printf("----------- Infix -> Postfix -----------\n");
    printf("Enter Expression: ");

    scanf("%s", infix);

    InfixtoPostfix(infix, &stack);

    return 0;
}