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
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->prev = *tail;
        newNode->next = *head;
        (*tail)->next = newNode;
        (*head)->prev = newNode;
        *tail = newNode;
    }
    size++;
}

void insertFront(struct Node **head, struct Node **tail, int val) {
    struct Node *newNode = create(val);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->next = *head;
        newNode->prev = *tail;
        (*head)->prev = newNode;
        (*tail)->next = newNode;
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
        (*head)->prev = *tail;
        (*tail)->next = *head;
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
        (*tail)->next = *head;
        (*head)->prev = *tail;
    }
    free(temp);
    size--;
}

void printNode(struct Node *head) {
    if (head == NULL) {
        printf("No nodes found\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int ch, val;

    printf("Press:\n1.Insert at End\n2.Insert at Front\n3.Delete From Front\n4.Delete From End\n5. Exit\n");
    do{
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertEnd(&head, &tail, val);
                printNode(head);
                break;
            case 2:
                printf("Enter the calue to insert: ");
                scanf("%d", &val);
                insertFront(&head, &tail, val);
                printNode(head);
                break;
            case 3:
                deleteFront(&head, &tail);
                printNode(head);
                break;
            case 4:
                deleteEnd(&head, &tail);
                printNode(head);
                break;
            case 5:
                printf("Program Ended\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(ch != 5);

    return 0;
}
