#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

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
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->prev = *tail;
        newNode->next = *head;
        (*tail)->next = newNode;
        (*head)->prev = newNode;
        *tail = newNode;
    }
}

void printList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void splitList(struct Node *head, struct Node **head1, struct Node **tail1, struct Node **head2, struct Node **tail2, int pos) {
    if (head == NULL || pos <= 0)
        return;

    struct Node *temp = head;
    int count = 1;

    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }

    *head1 = head;
    *tail1 = temp;
    *head2 = temp->next;
    *tail2 = head->prev;

    (*tail1)->next = *head1;
    (*head1)->prev = *tail1;
    (*tail2)->next = *head2;
    (*head2)->prev = *tail2;
}

int main() {
    struct Node *head = NULL, *tail = NULL;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    insertEnd(&head, &tail, 10);
    insertEnd(&head, &tail, 20);
    insertEnd(&head, &tail, 30);
    insertEnd(&head, &tail, 40);
    insertEnd(&head, &tail, 50);
    insertEnd(&head, &tail, 60);

    printf("Original List: ");
    printList(head);

    int pos = 3;
    splitList(head, &head1, &tail1, &head2, &tail2, pos);

    printf("First List: ");
    printList(head1);

    printf("Second List: ");
    printList(head2);

    return 0;
}
