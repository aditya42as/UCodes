/* Problem Statement:
Given an expression in the form of postfix representation, design an algorithm and a program to
 find result of this expression
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE) */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stack {
    int size;
    int *s;
    int top;
};

void create(struct stack *st) {
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void push(struct stack *st, int x) {
    if (st->top == st->size - 1) {
        printf("Stack overflow\n");
    } else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st) {
    int x = -1;
    if (st->top == -1) {
        printf("Stack underflow\n");
    } else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int evaluate(char *str)
{
    struct stack st;
    create(&st);

    int i = 0;
    int len = strlen(str);

    while (i < len) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            i++;
            continue;
        }

        if (isdigit((unsigned char)str[i])) {
            int num = 0;
            while (i < len && isdigit((unsigned char)str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            push(&st, num);
            continue;
        }

        char op = str[i];
        i++;

        int val2 = pop(&st);
        int val1 = pop(&st);

        switch (op) {
            case '+':
                push(&st, val1 + val2);
                break;
            case '-':
                push(&st, val1 - val2);
                break;
            case '*':
                push(&st, val1 * val2);
                break;
            case '/':
                if (val2 == 0) {
                    printf("Division by zero encountered — pushing 0 as result\n");
                    push(&st, 0);
                } else {
                    push(&st, val1 / val2);
                }
                break;
            default:
                break;
        }
    }

    return pop(&st);
}

int main()
{
    int t;
    printf("Test Cases: ");
    scanf("%d", &t);
    getchar();
    int c = 0;
    while (c != t) {
        char str[256];
        printf("Enter postfix expression: \n");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;
        printf("Result: %d\n", evaluate(str));
        c++;
    }
    return 0;
}
