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

void printNode(struct Node *head) {
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

void removeDuplicates(struct Node **head, struct Node **tail) {
    if (*head == NULL)
        return;

    struct Node *current = *head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node *duplicate = current->next;
            current->next = duplicate->next;

            if (duplicate->next != NULL)
                duplicate->next->prev = current;
            else
                *tail = current;

            free(duplicate);
            size--;
        } else {
            current = current->next;
        }
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

   
    insertEnd(&head, &tail, 10);
    insertEnd(&head, &tail, 20);
    insertEnd(&head, &tail, 20);
    insertEnd(&head, &tail, 30);
    insertEnd(&head, &tail, 30);
    insertEnd(&head, &tail, 40);
    insertEnd(&head, &tail, 40);
    insertEnd(&head, &tail, 50);

    printf("Original list:\n");
    printNode(head);

    removeDuplicates(&head, &tail);

    printf("After removing duplicates:\n");
    printNode(head);

    return 0;
}
