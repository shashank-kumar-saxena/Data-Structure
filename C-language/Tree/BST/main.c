#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
    struct bst *left;
    int info;
    struct bst *right;
} tree;
tree *temp = NULL, *ptr = NULL;
tree *_insertAtBST(tree *root, int data);
void inorder(tree *root);
void preorder(tree *root);
void postorder(tree *root);
void main()
{
    tree *root = NULL;
    int n, data;

    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert an element\n");
        printf("2 for Pre-order\n");
        printf("3 for In-order traversion\n");
        printf("4 for Post-order\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the data you want to insert\n");
            scanf("%d", &data);
            if (root == NULL)
                root = _insertAtBST(root, data);
            else
                _insertAtBST(root, data);
            printf("Data Insert successfully\n");
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        default:
            break;
        }
    }
}
tree *_insertAtBST(tree *root, int data)
{
    if (root == NULL)
    {
        temp = (tree *)(malloc(sizeof(tree)));
        temp->info = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (data < root->info)
        root->left = _insertAtBST(root->left, data);
    else if (data >= root->info)
        root->right = _insertAtBST(root->right, data);
    return root;
}
void preorder(tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        inorder(root->left);
        inorder(root->right);
    }
}
void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}
void postorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->info);
    }
}