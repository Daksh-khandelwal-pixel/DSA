#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack to store strings
char stack[MAX][MAX];
int top = -1;

// Push a string onto the stack
void push(char str[])
{
    top++;
    strcpy(stack[top], str);
}

// Pop a string from the stack
void pop(char str[])
{
    strcpy(str, stack[top]);
    top--;
}

int main()
{
    char postfix[MAX];

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    // Read the postfix expression one character at a time
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char symbol = postfix[i];

        // If the character is an operand (A-Z, a-z, 0-9)
        if (isalnum(symbol))
        {
            // Convert the character into a string
            char operand[2];
            operand[0] = symbol;
            operand[1] = '\0';

            // Store it in the stack
            push(operand);
        }
        else
        {
            // Operator found

            char right[MAX];
            char left[MAX];
            char expression[MAX];

            // Pop the two operands
            pop(right);      // Topmost operand
            pop(left);       // Next operand

            // Create a new infix expression
            sprintf(expression, "(%s%c%s)", left, symbol, right);

            // Push the new expression back
            push(expression);
        }
    }

    printf("\nInfix Expression = %s\n", stack[top]);

    return 0;
}