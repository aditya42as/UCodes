#include <stdio.h>
#include <stdlib.h>

struct Node {
    int pid;
    int burst;
    int rem;
    int completion;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int pid, int burst) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->pid = pid;
    n->burst = burst;
    n->rem = burst;
    n->completion = 0;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void insertEnd(struct Node **head, struct Node **tail, int pid, int burst) {
    struct Node *n = createNode(pid, burst);
    if (*head == NULL) {
        *head = n;
        *tail = n;
        n->next = n;
        n->prev = n;
    } else {
        n->prev = *tail;
        n->next = *head;
        (*tail)->next = n;
        (*head)->prev = n;
        *tail = n;
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("No processes\n");
        return;
    }
    struct Node *t = head;
    printf("PID\tBurst\n");
    do {
        printf("%d\t%d\n", t->pid, t->burst);
        t = t->next;
    } while (t != head);
}

void roundRobin(struct Node **head, struct Node **tail, int quantum) {
    if (*head == NULL) {
        printf("No processes to schedule\n");
        return;
    }

    int time = 0;
    struct Node *curr = *head;

    while (*head != NULL) {
        if (curr->rem > 0) {
            if (curr->rem <= quantum) {
                time += curr->rem;
                curr->rem = 0;
                curr->completion = time;

                struct Node *del = curr;

                if (del->next == del) {
                    *head = NULL;
                    *tail = NULL;
                    free(del);
                    curr = NULL;
                    break;
                } else {
                    curr = del->next;
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                    if (del == *head) *head = del->next;
                    if (del == *tail) *tail = del->prev;
                    free(del);
                }
            } else {
                curr->rem -= quantum;
                time += quantum;
                curr = curr->next;
            }
        } else {
            curr = curr->next;
        }
    }

    printf("Scheduling completed at time %d\n", time);
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int choice, burst, pid = 1;
    int quantum = 10;

    printf("\n1. Add Process\n2. Display Processes\n3. Run Round Robin (10 sec)\n4. Exit\nEnter choice: ");
    do {
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter burst time for process %d: ", pid);
                scanf("%d", &burst);
                insertEnd(&head, &tail, pid, burst);
                pid++;
                break;

            case 2:
                display(head);
                break;

            case 3:
                if (head == NULL) {
                    printf("No processes to schedule\n");
                    break;
                }
                roundRobin(&head, &tail, quantum);
                break;

            case 4:
                while (head != NULL) {
                    struct Node *next = head->next;
                    free(head);
                    if (next == head) break;
                    head = next;
                }
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }while(choice != 4);
}
