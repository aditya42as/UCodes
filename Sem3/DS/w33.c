/*Problem Statement:
Given a string of opening and closing paranthesis, design an algorithm and a program to find the
 length of the longest valid paranthesis substring. Valid paranthesis substring is a string which
 contains balanced paranthesis.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/

#include <stdio.h>
#include <stdlib.h>
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
   }
   else {
      st->top++;
      st->s[st->top] = x;
   }
}
int pop(struct stack *st) {
   int x = -1;
   if (st->top == -1) {
      printf("Stack underflow\n");
   }
   else {
      x = st->s[st->top];
      st->top--;
   }
   return x;
}

int top(struct stack *st) {
    if (st->top == -1) {
        return -1;
    }
    return st->s[st->top];
}

int isEmpty(struct stack *st) {
    return st->top == -1;
}

int validParLen(char *expr)
{
    int length = strlen(expr);
    struct stack st;
    create(&st);

    push(&st, -1);

    int max = 0;

    for (int i = 0; i < length; i++)
    {
        if (expr[i] == '(')
        {
            push(&st, i);
        }
        else
        {
            pop(&st);

            if (isEmpty(&st))
            {
                push(&st, i);
            }
            else
            {
                int len = i - top(&st);

                if (len > max)

                    max = len;
            }
        }
    }
    return max;
}

int main()
{
    int t;
    printf("Test Cases: ");
    scanf("%d", &t);
    int c = 0;
    while(c != t) {
        char expr[100];
        printf("Enter an expression with parentheses: ");
        scanf("%s", expr);

        int res = validParLen(expr);
        printf("Length of longest valid parentheses substring: %d\n", res);
        c++;
    }

    return 0;
}
