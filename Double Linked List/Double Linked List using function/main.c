#include <stdio.h>
#include <stdlib.h>
// node decleration
typedef struct lklist
{
    struct lklist *prev;
    int info;
    struct lklist *next;
} node;
// global variable decleration
node *temp = NULL;
node *head = NULL;
node *tail = NULL;
// function decleration
void insertAtBegning(node **head, node **tail, int data);
void traverseFromBegning(node *head);
void traverseFromEnd(node *tail);
void main()
{
    int n = 0, data = 0;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert at begning\n");
        printf("5 traverse from begning\n");
        printf("6 for traverse from Ending\n");
        printf("13 for exit\n");
        scanf("%d", &n);
        if (n == 13)
        {
            exit(1);
        }
        switch (n)
        {
        case 1:
            printf("Enter the data you want to insert\n");
            scanf("%d", &data);
            insertAtBegning(&head, &tail, data);
            break;
        case 5:
            traverseFromBegning(head);
            break;
        case 6:
            traverseFromEnd(tail);
            break;
        default:
            printf("Enter the valid choice\n");
            break;
        }
    }
}
void insertAtBegning(node **head, node **tail, int data)
{
    temp = (node *)(malloc(sizeof(node)));
    temp->info = data;
    temp->prev = NULL;
    if (*head == NULL)
    {
        temp->next = NULL;
        *head = temp;
        *tail = temp;
        printf("Node Insert Successfully\n");
    }
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
        printf("Node Insert Successfully\n");
    }
}
void traverseFromBegning(node *head)
{
    if (head == NULL)
    {
        printf("No Element found\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
}
void traverseFromEnd(node *tail)
{
    if (tail == NULL)
    {
        printf("No Element found\n");
        return;
    }
    while (tail != NULL)
    {
        printf("%d ", tail->info);
        tail = tail->prev;
    }
}