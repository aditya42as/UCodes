/*Problem Statement:
Given an expression string consisting of opening and closing brackets “{“,”}”,”(“,”)”,”[“,”]”,
 design an algorithm and a program to check whether this expression has balanced paranthesis or
 not.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack {
   int size;
   char *s;
   int top;
};
void create(struct stack *st) {
   printf("Enter the size of the stack: ");
   scanf("%d", &st->size);
   st->top = -1;
   st->s = (char *)malloc(st->size * sizeof(char));
}
void push(struct stack *st, char x) {
   if (st->top == st->size - 1) {
      printf("Stack overflow\n");
   }
   else {
      st->top++;
      st->s[st->top] = x;
   }
}
char pop(struct stack *st) {
   char x = -1;
   if (st->top == -1) {
      printf("Stack underflow\n");
   }
   else {
      x = st->s[st->top];
      st->top--;
   }
   return x;
}
int isEmpty(struct stack *st) {
    return st->top == -1;
}
int isBalanced(char *exp, struct stack *st) {
    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(st, exp[i]);
        else {
            if(isEmpty(st)) return 0;
            char top = pop(st);
            if((exp[i] == ')' && top != '(') ||
               (exp[i] == '}' && top != '{') ||
               (exp[i] == ']' && top != '['))
                return 0;
        }
    }
    return isEmpty(st);
}

int main() {
    struct stack st;
    create(&st);
    int t;
    printf("Test Cases: ");
    scanf("%d", &t);
    int c = 0;
    while(c != t) {
        char exp[100];
        printf("Enter the string: ");
        scanf("%s", exp);
        
        if(isBalanced(exp, &st)) {
            printf("Balanced\n");
        }
        else {
            printf("Not Balanced\n");
        }
        free(st.s);
        c++;
    }
    return 0;
}
