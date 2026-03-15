#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int x) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void removeDuplicates(struct Node **head) {
    if (*head == NULL)
        return;

    struct Node *current = *head;

    while (current != NULL) {
        struct Node *temp = current;

        while (temp->next != NULL) {
            if (temp->next->data == current->data) {
                struct Node *duplicate = temp->next;
                temp->next = duplicate->next;
                free(duplicate);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void insertBack(struct Node **head, int k) {
    struct Node *newNode = createNode(k);
    newNode->data = k;
    newNode->next = NULL;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    else{
        struct Node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
}

void display(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int ch, val;
    printf("1. Insert Node\n2. Remove Duplicates\n3. Exit\nPress: ");
    do{
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter Value to insert in Linked List: ");
            scanf("%d", &val);
            insertBack(&head, val);
            display(head);
            break;
        case 2:
            printf("After Removing Dupicates.\n");
            removeDuplicates(&head);
            display(head);
            break;
        case 3:
            printf("Program Exited!\n");
            break;
        default:
            printf("Invalid Input. Try again.\n");
            break;
        }
    }while(ch != 3);
}
