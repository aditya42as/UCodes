/*Problem Statement:
Design an algorithm and write a program to implement circular queue. Circular queue is a queue
 in which last position of queue is connected with first position of queue to make a circle. The
 program should implement following operations:
 a) Create() - create a queue of specific size
 b)EnQueue(k) - insert an element k into the queue
 c) DeQueue() - delete an element from the queue
 d)IsEmpty() - check if queue is empty or not
 e) Front() - return front item from queue
 f) Rear() - return rear item from queue
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

void reverse(char *str) {
    int n = strlen(str);
    struct stack st;
    create(&st);
    for(int i=0; i<n; i++) {
        push(&st, str[i]);
    }
    for(int i=0; i<n; i++) {
        str[i] = pop(&st);
    }
}

void reverseRec(char *str, int l, int r) {
    if(l >= r) return;
    char temp = str[l];
    str[l] = str[r];
    str[r] = temp;
    reverseRec(str, l+1, r-1);
}

int main() {
    int t;
    printf("Test Cases: ");
    scanf("%d", &t);
    int c = 0;
    while(c != t) {
        char str[100];
        printf("Enter string: ");
        scanf("%s", str);
        reverse(str);
        printf("Reversed string: %s\n", str);
        reverseRec(str, 0, strlen(str)-1);
        printf("Reversed string with recursion: %s\n", str);
        c++;
    }
    return 0;
}
