/*Problem Statement:
 Write an algorithm and a program to implement stack using linked list. he program should
 implement following queue operations:
 a)Create()
 b)Push()
 c)Pop()
 d)IsEmpty()
 e)IsFull()
 f)Size()
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
int size = 0;
void Create() {
    top = NULL;
    size = 0;
    printf("Stack created\n");
}
void Push(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = top;
    top = newNode;
    size++;
    printf("Stack: ");
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
    }
    struct Node *temp = top;
    printf("Element popped - %d\n", temp->data);
    top = top->next;
    free(temp);
    size--;
    printf("Stack after pop: ");
    struct Node *ptr = top;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void IsEmpty() {
    if (top == NULL) {
        printf("Stack is empty\n"); 
    }
    else {
        printf("Stack is not empty\n");
    }
}
void IsFull() {
    printf("Linked List stack has no fixed limit\n");
}
int Size() {
    return size;
}

int main() {
    int choice, val;
    printf("\nEnter your choice:\n1. Create stack\n2. Push\n3. Pop\n4. Size\n5. IsEmpty\n6. IsFull\n7. Exit\n");
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Create();
            break;
        case 2:
            scanf("%d", &val);
            Push(val);
            break;
        case 3:
            Pop();
            break;
        case 4:
            printf("Size = %d\n", Size());
            break;
        case 5:
            IsEmpty();
            break;
        case 6:
            IsFull();
            break;
        }
    } while (choice != 7);
    return 0;
}
