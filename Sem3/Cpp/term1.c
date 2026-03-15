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

void insertNth(struct Node **head, int k, int pos) {
    if(pos < 1) {
        printf("No nodes in linked list.");
        return;
    }
    struct Node *newNode = createNode(k);
    if(pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for(int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
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
    int ch, val, pos;
    printf("1.Insert at back\n2.Insert Anywhere\n3. Exit\nPress: ");
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
            printf("Enter Value to insert in Linked List: ");
            scanf("%d", &val);
            printf("Enter position to insert at: ");
            scanf("%d", &pos);
            insertNth(&head,val,pos);
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