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

struct Tree *createBST(struct Tree *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = createBST(root->left, data);
    } else {
        root->right = createBST(root->right, data);
    }
    return root;
}

void inorder(struct Tree* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Tree* minValueNode(struct Tree* node) {
    struct Tree* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

struct Tree* deleteNode(struct Tree* root, int key) {
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Tree* temp = root->left;
            free(root);
            return temp;
        }
        struct Tree* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    int n;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    struct Tree *root = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data); 
        root = createBST(root, data);
    }
    int key;
    printf("Ente the node to delete:");
    scanf("%d", &key);
    inorder(root);
    printf("\n");
    root = deleteNode(root, key);
    inorder(root);
    printf("\n");
    return 0;
}