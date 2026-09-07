#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(int value){
    stack[++top] = value;
}

int pop(){
    if(top == -1){ return -1;}
    return stack[top--];
}

int main(){
    char postfix[MAX] = "53*4-";
    char infix[MAX]; 

    for(int i = 0;postfix[i] != '\0';i++){
        char op = postfix[i];
        // Rule 1 if it is an integer push in stack
        if(isdigit(op)){
            push(op-'0');
        }
        // Rule 2 if it is operator pop last 2 and do the oeprations
        else{
            int op1 = pop();
            int op2 = pop();
            int result =0;
            switch (op)
            {
            case '+': result= op2+op1; break;
            case '-': result= op2-op1; break;
            case '*': result= op2*op1; break;
            case '/': result= op2/op1; break;
            
            default:
                break;
            }
            push(result);
        }
    }
    // Rule 3: The final remaining number is the answer
    printf("Final Answer: %d\n", stack[top]);
}