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

void printNode(struct Node *head) {
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

void concatenate(struct Node **head1, struct Node **tail1, struct Node **head2, struct Node **tail2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        *tail1 = *tail2;
        return;
    }
    if (*head2 == NULL) {
        return;
    }
    (*tail1)->next = *head2;
    (*head2)->prev = *tail1;
    (*tail2)->next = *head1;
    (*head1)->prev = *tail2;
    *tail1 = *tail2;
}

int main() {
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    
    int ch, val;

    printf("Press:\n1.InsertEnd in first list\n2.InsertEnd in second list\n3.Concatenate\n4. Exit\n");
    do{
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertEnd(&head1, &tail1, val);
                printf("First Circular List: ");
                printNode(head1);
                break;
            case 2:
                printf("Enter the calue to insert: ");
                scanf("%d", &val);
                insertEnd(&head2, &tail2, val);
                printf("Second Circular List: ");
                printNode(head2);
                break;
            case 3:
                concatenate(&head1, &tail1, &head2, &tail2);
                printf("Concatenated List: ");
                printNode(head1);
                break;
            case 4:
                printf("Program Ended\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(ch != 4);
    return 0;
}
