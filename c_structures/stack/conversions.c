#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPR_SIZE 100

// stack type
struct Stack {
    int top;
    int items[MAX_EXPR_SIZE];
};

// stack operations
void push(struct Stack *stack, int x) {
    stack->items[++stack->top] = x;
}

int pop(struct Stack *stack) {
    return stack->items[stack->top--];
}

int peek(struct Stack stack) {
    return stack.items[stack.top];
}

int isEmpty(struct Stack stack) {
    return stack.top == -1;
}

// function to get the precedence of a operator
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// function to convert infix expression to postfix
void infixToPostfix(char* exp) {
    int i, j;
    struct Stack stack;
    stack.top = -1;

    for (i = 0, j = -1; exp[i]; ++i) {
        if (exp[i] == '(') {
            push(&stack, exp[i]);
        }
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                exp[++j] = pop(&stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression");
                return;
            }
            else {
                pop(&stack);
            }
        }
        else {
            while (!isEmpty(stack) && getPrecedence(exp[i]) <= getPrecedence(peek(stack))) {
                exp[++j] = pop(&stack);
            }
            push(&stack, exp[i]);
        }
    }
    while (!isEmpty(stack)) {
        exp[++j] = pop(&stack);
    }
    exp[++j] = '\0';
}

int main() {
    char exp[]="a+b-c*(b+a)";
    printf("Enter a valid infix expression: ");
    infixToPostfix(exp);
    printf("Postfix expression: %s\n", exp);
    return 0;
}
