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

struct Tree *createTree(int arr[], int i, int n) {
    if(arr[i] == -1 || i > n) {
        return NULL;
    }
    else{
        struct Tree *root = createNode(arr[i]);
        root->left = createTree(arr, 2*i+1, n);
        root->right = createTree(arr, 2*i+2, n);
        return root;
    }
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
    if (root == NULL)
        return -1;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

     return (lHeight > rHeight ? lHeight : rHeight) + 1;
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
    keynode->data = f->data;
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
    printf("enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Tree *root = createTree(arr,0,n);

    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    

    printf("\nInorder: ");
    inorder(root);

    deleteroot(root, key);
    printf("\nInorder: ");
    inorder(root);

    
    
}

