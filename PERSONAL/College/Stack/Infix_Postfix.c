#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Required for isalnum()

#define MAX 100

char stack[MAX]; // FIXED: Changed to char
int top = -1;

void push(char value) {
    stack[++top] = value;
}

// FIXED: Pop now returns the character so we can move it to postfix
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// FIXED: Changed void to int
int precedentCheck(char op) {
    if (op == '^') { return 3; }
    if (op == '*' || op == '/' || op == '%') { return 2; }
    if (op == '+' || op == '-') { return 1; }
    return 0; // For '(' it returns 0 so it stays at the bottom
}

int main() {
    // FIXED: Changed to char arrays
    char infix[MAX] = "A+B*(C^D-E)^(F+G*H)-I"; 
    char postfix[MAX];
    
    int i = 0; // Index to read infix
    int j = 0; // Index to write postfix

    while (infix[i] != '\0') {
        char op = infix[i];

        // Rule 1: Letters and numbers go straight to output
        if (isalnum(op)) {
            postfix[j] = op;
            j++;
        }
        // Rule 2: Open bracket pushes to stack
        else if (op == '(') {
            push(op);
        }
        // Rule 3: Close bracket pops everything until the open bracket
        else if (op == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j] = pop();
                j++;
            }
            pop(); // Discard the '(' from the stack
        }
        // Rule 4: Operators check precedence
        else {
            while (top != -1 && precedentCheck(stack[top]) >= precedentCheck(op)) {
                postfix[j] = pop();
                j++;
            }
            push(op);
        }
        i++;
    }

    // Finally: Pop any operators left in the stack at the end
    while (top != -1) {
        postfix[j] = pop();
        j++;
    }

    // Add null terminator to make postfix a valid string
    postfix[j] = '\0';

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}