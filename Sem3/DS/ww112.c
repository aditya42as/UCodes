

#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *createNode(int x)
{
    struct Tree *newNode = malloc(sizeof(struct Tree));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tree *createBST(struct Tree *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = createBST(root->left, data);
    }
    else
    {
        root->right = createBST(root->right, data);
    }
    return root;
}
struct Tree *deleteNode(struct Tree *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left = NULL)
        {
            root->right = NULL;
        }
        return NULL;
    }
    if (root->left && root->right == NULL || root->left == NULL && root->right)
    {
        struct Tree *temp = NULL;
        if (root->left)
        {
            temp = root->left;
            free(root);
        }
        else
        {
            temp = root->right;
        }
        return root;
    }
}

void inorder(struct Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder(struct Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int search(struct Tree *root, int key)
{
    if (root = NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
    return 0;
}

int main()
{
    int n;
    printf("enter no. of nodes in tree: ");
    scanf("%d", &n);

    int data;
    struct Tree *root = NULL;
    printf("enter value of each node: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = createBST(root, data);
    }

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nPreorder: ");
    preorder(root);

    // search(root, key);

    if (search(root, key))
    {
        printf("\nKey Found");
    }
    else
    {
        printf("\nKey not found");
    }
}
