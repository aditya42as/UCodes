#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *create(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp; 
}

void insertEnd(struct Node **head, struct Node **tail, int val) {
    struct Node *newNode = create(val);
    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }
   else {
        (*tail)->next = newNode;
        struct Node *temp = *tail;
        *tail = (*tail)->next;
        (*tail)->prev = temp;
        return;
    }
}

void printNode(struct Node *head, struct Node *tail) {
    if(head == NULL && tail == NULL) {
        printf("No Nodes found");
    }
    else {
        struct Node *temp = head;
        printf("\n\nFrom Left to Right: ");
        while(temp != NULL) {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("\nFrom Right to Left: ");
        struct Node *temp1 = tail;
        while(temp1 != NULL) {
            printf("%d", temp1->data);
            temp1 = temp1->prev;
        }
        printf("\n");
    }
}

void reverse(struct Node **head, struct Node **tail) {
    if(*head == NULL && *tail == NULL) {
        printf("Linked List is Empty\n");
    }
    struct Node *temp = NULL;
    struct Node *curr = *head;
    while(curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp != NULL) {
        *head = temp->prev;
        *tail = (*head);
        while((*tail)->next != NULL) {
            *tail = (*tail)->next;
        }

    }
    struct Node *temp1 = *head;
    printf("Reversed Linked List: ");
    while(temp1 != NULL) {
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int k, ch;
    printf("Press:\n1.insertEnd\n2.Reverse\n3.Exit\n");
    do{
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &k);
                insertEnd(&head, &tail, k);
                break;
            case 2:
                reverse(&head, &tail);
                break;
            case 3:
                printf("Program Exited\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }

    }while(ch != 3);
    return 0;
}