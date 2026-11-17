#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 20

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[] = "23*5+"; // Equivalent to (2 * 3) + 5 = 11
    int i;


    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0'); // Convert char '2' to integer 2
        } 
        else {
            int val2 = pop(); // First popped is the RIGHT operand
            int val1 = pop(); // Second popped is the LEFT operand

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
        }
    }

    printf("Result: %d\n", pop());
    return 0;
}