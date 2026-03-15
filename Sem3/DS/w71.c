/*Problem Statement:
 Write an algorithm and a program to implement singly linked list. The program should
 implement following operations:
 a)Create(k) - create a linked list with single node of value k
 b)InsertFront(k) - insert node of value k at the front of the linked list
 c)InsertEnd(k) - insert a node of value k at the end of the linked list
 d)InsertAnywhere(p) - insert a node at specific position p
 e)DeleteFront() - delete a node from the front of the linked list
 f)DeleteEnd() - delete a node from the end of the linked list
 g)DeleteAnywhere(p) - delete a node from a specific position p
 h)Size() - find the size of the linked list
 i) IsEmpty() - checks if the linked list is empty or not
 j)FindMiddle() - finds the middle element of the linked list
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void Create(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = NULL;
    head = newNode;
}
void InsertFront(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = head;
    head = newNode;
}

void InsertEnd(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void InsertAnywhere(int k, int p) {
    if (p == 1) {
        InsertFront(k);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < p - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position not valid!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void DeleteFront() {
    if (head == NULL) {
        return;
    }
    struct Node *temp = head;
    printf("Node deleted: %d\n", temp->data);
    head = head->next;
    free(temp);
}
void DeleteEnd() {
    if (head == NULL) {
        printf("Linked List is empty");
    }
    if (head->next == NULL) {
        printf("Node deleted – %d\n", head->data);
        free(head);
        head = NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Node deleted: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void DeleteAnywhere(int p) {
    if (head == NULL) {
        printf("Linked List is Empty");
    }
    if (p == 1) {
        DeleteFront();
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < p - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position not valid!\n");
    }
    struct Node *toDelete = temp->next;
    printf("Node deleted – %d\n", toDelete->data);
    temp->next = toDelete->next;
    free(toDelete);
}
int Size() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int IsEmpty() {
    return head == NULL;
}
void FindMiddle() {
    if (head == NULL) {
        printf("Linked List is Empty");
    }
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}
void PrintList() {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;
    printf("\nPress:\n1 InsertFront\n2 InsertEnd\n3 InsertAnywhere\n4 DeleteFront\n5 DeleteEnd\n6 DeleteAnywhere\n7 Size\n8 FindMiddle\n9 exit\n");
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scanf("%d", &val);
            InsertFront(val);
            PrintList();
            break;
        case 2:
            scanf("%d", &val);
            InsertEnd(val);
            PrintList();
            break;
        case 3:
            scanf("%d %d", &val, &pos);
            InsertAnywhere(val, pos);
            PrintList();
            break;
        case 4:
            DeleteFront();
            PrintList();
            break;
        case 5:
            DeleteEnd();
            PrintList();
            break;
        case 6:
            scanf("%d", &pos);
            DeleteAnywhere(pos);
            PrintList();
            break;
        case 7:
            printf("Size = %d\n", Size());
            break;
        case 8:
            FindMiddle();
            break;
        }
    } while (choice != 9);
    return 0;
}
