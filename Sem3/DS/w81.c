#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

int size = 0;

struct Node* create(int val) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertEnd(struct Node **head, struct Node **tail, int val) {
    struct Node *newNode = create(val);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
    size++;
}

void insertFront(struct Node **head, struct Node **tail, int val) {
    struct Node *newNode = create(val);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    size++;
}

void deleteFront(struct Node **head, struct Node **tail) {
    if (*head == NULL) {
        printf("No nodes found\n");
        return;
    }

    struct Node *temp = *head;
    if (*head == *tail) {
        *head = NULL;
        *tail = NULL;
    } else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    free(temp);
    size--;
}

void deleteEnd(struct Node **head, struct Node **tail) {
    if (*head == NULL) {
        printf("No nodes found\n");
        return;
    }

    struct Node *temp = *tail;
    if (*head == *tail) {
        *head = NULL;
        *tail = NULL;
    } else {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }
    free(temp);
    size--;
}

void printNode(struct Node *head, struct Node *tail) {
    if (head == NULL) {
        printf("No nodes found\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    insertEnd(&head, &tail, 10);
    insertEnd(&head, &tail, 20);
    insertEnd(&head, &tail, 30);
    insertEnd(&head, &tail, 40);

    printNode(head, tail);

    deleteEnd(&head, &tail);
    printNode(head, tail);

    insertFront(&head, &tail, 5);
    printNode(head, tail);

    deleteFront(&head, &tail);
    printNode(head, tail);

    return 0;
}
