/*Problem Statement:
 Design an algorithm and a program to implement stack using array. The program should
 implement following stack operations:
 a) Create() - create an empty stack 
 b) Push(k) - push an element k into the stack
 c) Pop() - pop an element from the stack snd return it
 d) IsEmpty() - check if stack is empty or not
 e) Size() - finds the size of the stack
 f) Print() - prints the contents of stack
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>
#include <stdlib.h>
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
      printf("%d pushed onto the stack\n", x);
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
      printf("%d popped from the stack\n", x);
   }
   return x;
}
int size(struct stack *st) {
   return st->top + 1;
}
int isEmpty(struct stack *st) {
   return st->top == -1;
}
void display(struct stack st){
   printf("Stack elements:\n");
   for (int i = st.top; i >= 0; i--) {
      printf("%d\n", st.s[i]);
   }
}
int main() {
   struct stack st;
   create(&st);
   int ch, value;
   printf("\nPress:\n1. Push\n2. Pop\n3. Calculate Size\n4. Display\n5. Exit\n");
   do {
      
      scanf("%d", &ch);
      switch (ch) {
      case 1:
         printf("Enter a value to push: ");
         scanf("%d", &value);
         push(&st, value);
         break;
      case 2:
         pop(&st);
         break;
      case 3:
         printf("Current stack size: %d\n", size(&st));
         break;
      case 4:
         display(st);
         break;
      case 5:
         printf("Exiting...\n");
         break;
      default:
         printf("Invalid Input. Please try again.\n");
      }
   } while (ch != 5);
   free(st.s);
   return 0;
}