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
tree *_delete(tree **root, int data, tree *Proot);
tree *_minimumElement(tree *root);
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
        printf("5 for delete an node\n");
        printf("6 for find minimum Element\n");
        printf("7 for exit\n");
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
        case 5:
            printf("Enter the element you want to delete\n");
            scanf("%d", &data);
            _delete(&root, data, NULL);
            break;
        case 6:
            printf("The Minimum Element is %d", (_minimumElement(root))->info);
            break;
        default:
            break;
        }
    }
}
tree *_minimumElement(tree *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return (root);
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
tree *_delete(tree **root, int data, tree *Proot)
{
    if (data > (*root)->info)
    {
        _delete((*root)->right, data, (*root));
    }
    else if (data < (*root)->info)
    {
        _delete((*root)->left, data, (*root));
    }
    else
    {
        tree *ptr = (*root);
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            if (Proot->left != NULL)
            {
                Proot->left = NULL;
            }
            else
            {
                Proot->right = NULL;
            }
        }
        else if ((*root)->left != NULL && (*root)->right != NULL)
        {
        }
        else
        {
            tree *ptr2 = NULL;
            if ((*root)->left != NULL)
            {
                ptr2 = (*root)->left;
            }
            else if ((*root)->right != NULL)
            {
                ptr2 = (*root)->right;
            }
            if (Proot->info <= ptr2->info)
            {
                Proot->right = ptr2;
            }
            else
            {
                Proot->left = ptr2;
            }
        }
    }
}