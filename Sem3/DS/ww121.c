#include <stdio.h>
#include <stdlib.h>

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

struct Tree *createTree(struct Tree *root, int data) {
    if(root == NULL) {
        root = createNode(data);
        return root;
    }
    root->left = createTree(root->left, data);
    root->right = createTree(root->right, data);
    return root;
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
struct Tree* deleteroot(struct Tree *root, int key){
    
    struct Tree *keynode = NULL;
    struct Tree *parent = NULL;
    struct Tree *queqe[1000];
    int rear = 0, front = 0;
    queqe[rear] = root;
    struct Tree *f = NULL;
    while(front <= rear){
        f =  queqe[front];
        front++;
        if(f->data == key) {
            keynode = f;
        }
        if(f->left) {
            parent = f;
            queqe[++rear] = f->left;
        }
        if(f->right) {
            parent = f;
            queqe[++rear] = f->right;
        }
    }
    if(keynode == NULL) {
        printf("Not found");
    }
    else{
        keynode->data == f->data;
    }
    
    if(parent->right == f) {
        parent->right = NULL;
    }    
    else if(parent->left == f) {
        parent->left = NULL;
    }
    return root;
}


int main() {
    int n;
    printf("enter no. of nodes in tree: ");
    scanf("%d", &n);

    int data;
    struct Tree *root = NULL;
    printf("enter value of each node: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = createTree(root, data);
    }

    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    

    printf("\nInorder: ");
    inorder(root);

    deleteroot(root, key);
    printf("\nInorder: ");
    inorder(root);

    
    
}
