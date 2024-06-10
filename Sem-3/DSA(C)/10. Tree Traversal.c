#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    printf("%d ", node->data);

    printInorder(node->right);
}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);

    printPreorder(node->left);

    printPreorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    printf("%d ", node->data);
}

int main()
{

    
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int choice;
    printf("Choose a tree traversal technique:\n");
    printf("1. Inorder traversal\n");
    printf("2. Preorder traversal\n");
    printf("3. Postorder traversal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Inorder traversal of binary tree is: ");
            printInorder(root);
            break;
        case 2:
            printf("Preorder traversal of binary tree is: ");
            printPreorder(root);
            break;
        case 3:
            printf("Postorder traversal of binary tree is: ");
            printPostorder(root);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    getchar();
    return 0;
}
