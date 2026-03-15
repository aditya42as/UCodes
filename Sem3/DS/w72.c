
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
int size = 0;
void Create() {
    front = NULL;
    rear = NULL;
    size = 0;
    printf("Queqe created\n");
}
void EnQueue(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
    printf("Queue - ");
    struct Node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void DeQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Element deleted - %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    size--;
    printf("Queue after deletion - ");
    struct Node *ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int IsEmpty(){
    return front == NULL;
}
int Size() {
    return size;
}

int main() {
    int choice, val;
    printf("\nPress:\n1 Create\n2 Enqueue\n3 Dequeue\n4 Size\n5 Empty\n6 Exit\n");
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Create();
            break;
        case 2:
            scanf("%d", &val);
            EnQueue(val);
            break;
        case 3:
            DeQueue();
            break;
        case 4:
            printf("Size = %d\n", Size());
            break;
        case 5:
            if(IsEmpty()) {
                printf("Queqe is empty\n");
            }
            else{
                printf("Queqe is Not empty\n");
            }
        }
    } while (choice != 6);
    return 0;
}
