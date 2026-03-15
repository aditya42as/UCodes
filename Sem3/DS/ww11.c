#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree* createNode(int x) {
    struct Tree *newNode = malloc(sizeof(struct Tree));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct Tree* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Tree* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    
}

void preorder(struct Tree* root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    
}

int height(struct Tree *root) {
    if(root == NULL) {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);

    return (lheight > rheight ? lheight : rheight) + 1;
}



int main() {
    int data;
    struct Tree *root = NULL;

    printf("Enter root data: ");
    scanf("%d", &data);
    root = createNode(data);

    struct Tree *queqe[100];
    int front = 0, rear = 0;
    queqe[rear] = root;

    while(front <= rear) {
        struct Tree *f = queqe[front];
        front++;

        printf("Enter left child %d: ", f->data);
        scanf("%d", &data);
        if(data != -1) {
            f->left = createNode(data);
            queqe[++rear] = f->left;
        }

        printf("Enter right child %d: ", f->data);
        scanf("%d", &data);
        if(data != -1) {
            f->right = createNode(data);
            queqe[++rear] = f->right;
            
        }
    }

    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nPreorder: ");
    preorder(root);

    int h = height(root);
    printf("\nHeight: %d", h);

    rear = 0, front  = 0;
    int level = 0, size = 0;
    int max = 0;
    int ans = 0;

    queqe[rear] = root;
    while(front <= rear) {
        level++;
        size = rear - front + 1;
        if(size > max) {
            max = size;
            ans = level;
        }

        for(int i = 0; i < size; i++) {
            struct Tree *f = queqe[front];
            front++;
            if(f->left) {
                queqe[++rear] = f->left;
            }
            if(f->right) {
                queqe[++rear] = f->right;
            }
        }
    }
    printf("\nLevel with max nodes: %d\nNo. of max nodes: %d\n", max, ans);

return 0;
}
