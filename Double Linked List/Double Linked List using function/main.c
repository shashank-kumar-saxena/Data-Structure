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
void insertAtEnd(node **head, node **tail, int data);
void insertAfterSpecificElement(node *head, node **tail, int data);
void traverseFromBegning(node *head);
void traverseFromEnd(node *tail);
void main()
{
    int n = 0, data = 0;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert at begning\n");
        printf("2 for insert at end\n");
        printf("3 for insert after specific element\n");
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
        case 2:
            printf("Enter the data you want to insert\n");
            scanf("%d", &data);
            insertAtEnd(&head, &tail, data);
            break;
        case 3:
            printf("Enter the element after which you want to insert the element\n");
            scanf("%d", &data);
            insertAfterSpecificElement(head, &tail, data);
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
void insertAtEnd(node **head, node **tail, int data)
{
    temp = (node *)(malloc(sizeof(node)));
    temp->info = data;
    temp->next = NULL;
    if (*head == NULL)
    {

        temp->prev = NULL;
        *head = temp;
        *tail = temp;
    }
    else
    {
        temp->prev = *tail;
        (*tail)->next = temp;
        *tail = temp;
        printf("Node Insert successfully\n");
    }
}
void insertAfterSpecificElement(node *head, node **tail, int data)
{
    if (head == NULL)
    {
        printf("No data Found\n");
        return;
    }
    while (head != NULL)
    {
        if (head->info == data)
        {
            break;
        }
    }
    if (head == NULL)
    {
        printf("Element not found");
        return;
    }
    else
    {
        printf("Enter the data you want to insert\n");
        scanf("%d", &data);
        temp = (node *)(malloc(sizeof(node)));
        temp->info = data;
        temp->prev = head;
        temp->next = head->next;
        if (head->next == NULL)
        {
            head->next = temp;
            (*tail) = temp;
            printf("Node Insert Successfully\n");
            return;
        }
        head->next = temp;
        (temp->next)->prev = temp;
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
