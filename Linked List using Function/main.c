// Linked List using function
#include <stdio.h>
#include <stdlib.h>
// Single linked list
typedef struct lklist
{
    int info;
    struct lklist *next;
} node;
// globle variable decleration
node *temp = NULL;
// function prototyping
void insertAtBeg(node **head, int data);
void insertAtEnd(node **head, int data);
void insertAfterSpecific(node **head, int data); // here data variable use to pass element after which we want to insert the element
void traversing(node *head);
int main()
{

    int n = 0, data = 0;
    node *head = NULL;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert at begning\n");
        printf("2 for insert at end\n");
        printf("3 for insert after specific element\n");
        printf("5 for traversing\n");
        printf("13 for exit\n");
        scanf("%d", &n);
        if (n == 13)
        {
            exit(1);
        }
        switch (n)
        {
        case 1:
            printf("Enter the element you want to insert\n");
            scanf("%d", &data);
            insertAtBeg(&head, data); // function calling
            break;
        case 2:
            printf("Enter the element you want to insert\n");
            scanf("%d", &data);
            insertAtEnd(&head, data); // function calling
            break;
        case 3:
            printf("Enter element after which you want to insert the element\n");
            scanf("%d", &data);
            insertAfterSpecific(&head, data);
            break;
        case 5:
            traversing(head); // calling
            break;
        default:
            printf("Enter the valid choice\n");
            break;
        }
    }
    return (1);
}
// function decleration of insert at begning
void insertAtBeg(node **head, int data)
{
    temp = (node *)(malloc(sizeof(node)));
    temp->info = data;
    temp->next = *head;
    *head = temp;
    printf("node insert successfully\n");
}
// function decleration of traversing
void traversing(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
}
// function decleration of insert at end
void insertAtEnd(node **head, int data)
{
    temp = (node *)(malloc(sizeof(node)));
    temp->info = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        printf("node insert successfully\n");
        return;
    }
    node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    printf("node insert successfully\n");
}
// function decleration for insert after specific element
void insertAfterSpecific(node **head, int data)
{
    if (*head == NULL)
    {
        printf("No element found\n");
    }
    node *ptr = *head;
    while (ptr != NULL)
    {
        if (ptr->info == data)
            break;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("no element found\n");
    }
    else
    {
        printf("Enter the element you want to insert\n");
        scanf("%d", &data);
        temp = (node *)(malloc(sizeof(node)));
        temp->info = data;
        temp->next = ptr->next;
        ptr->next = temp;
        printf("Node insert successfully\n");
    }
}