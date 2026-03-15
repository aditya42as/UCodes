#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *createNode(int x) {
    struct Tree *newNode = malloc(sizeof(struct Tree));
    if (!newNode) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tree *createBST(struct Tree *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = createBST(root->left, data);
    } else {
        root->right = createBST(root->right, data);
    }
    return root;
}

void inorder(struct Tree *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int bothchild(struct Tree *root) {
    if (root == NULL) {
        return 0;
    } 
    int count = 0;
    if (root->left && root->right) {
        count = 1;
    } 
    return count + bothchild(root->left) + bothchild(root->right);
}

int countLeaves(struct Tree *root) {
    if (root == NULL){
        return 0;
    }
    if (!root->left && !root->right) {
        return 1;
    } 
    return countLeaves(root->left) + countLeaves(root->right);
}

struct Tree *findMin(struct Tree *root) {
    if (!root) {
        return NULL;
    }
    while (root->left) {
        root = root->left;
    }
    return root;
}

struct Tree *inorderPredecessor(struct Tree *root, int key) {
    struct Tree *pred = NULL;
    struct Tree *cur = root;
    while (cur) {
        if (cur->data < key) {
            pred = cur;
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return pred;
}

int main() {
    int n, data;
    struct Tree *root = NULL;

    int choice;
     printf("\n1. Create Tree\n2. Count nodes with both children\n3. Count leaf nodes\n4. Find smallest info\n5. Inorder predecessor\n6. Exit\nPress: ");
    do {
       
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter no. of nodes in tree: ");
                if (scanf("%d", &n) != 1) break;
                printf("Enter value of each node:\n");
                for (int i = 0; i < n; i++) {
                    if (scanf("%d", &data) != 1) break;
                    root = createBST(root, data);
                }
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            }

            case 2: {
                int count = bothchild(root);
                printf("Nodes having both children: %d\n", count);
                break;
            }

            case 3: {
                int leaves = countLeaves(root);
                printf("Total leaf nodes: %d\n", leaves);
                break;
            }

            case 4: {
                struct Tree *minNode = findMin(root);
                if (minNode)
                    printf("Smallest value in BST: %d\n", minNode->data);
                else
                    printf("Tree is empty\n");
                break;
            }

            case 5: {
                int key;
                printf("Enter key: ");
                if (scanf("%d", &key) != 1) break;
                struct Tree *pred = inorderPredecessor(root, key);
                if (pred)
                    printf("Inorder predecessor of %d is %d\n", key, pred->data);
                else
                    printf("No inorder predecessor exists for %d\n", key);
                break;
            }

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again\n");
        }
    } while (choice != 6);

    return 0;
}
