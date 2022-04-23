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
void insertAtBegning(node **head, node **tail, int data);           // case 1 // for insert element at the starting of the linked list
void insertAtEnd(node **head, node **tail, int data);               // case 2 //for insert element at the end of the linked list
void insertAfterSpecificElement(node *head, node **tail, int data); // case 3 // for insert element after a specific element
void insertAtSpecificElement(node *head, node **tail, int data);    // case 4 // for insert element at specific position
void traverseFromBegning(node *head);                               // traversing from starting
void traverseFromEnd(node *tail);                                   // traversing from last
void main()
{
    int n = 0, data = 0;
    while (1)
    {
        //--------------MENU------------
        printf("\nEnter your choice\n");
        printf("1 for insert at begning\n");
        printf("2 for insert at end\n");
        printf("3 for insert after specific element\n");
        printf("4 for insert at specific position\n");
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
            insertAtBegning(&head, &tail, data); // calling
            break;
        case 2:
            printf("Enter the data you want to insert\n");
            scanf("%d", &data);
            insertAtEnd(&head, &tail, data); // calling
            break;
        case 3:
            printf("Enter the element after which you want to insert the element\n");
            scanf("%d", &data);                            // here data varible use for search the element after which we want to insert the element
            insertAfterSpecificElement(head, &tail, data); // calling
            break;
        case 4:
            printf("Enter the position where you want to inset the element\n");
            scanf("%d", &data);
            if (data == 1)
            {
                printf("Enter the data you want to insert\n");
                scanf("%d", &data);                  // here data variable use to take the actual value that we want to insert;
                insertAtBegning(&head, &tail, data); // calling
            }
            else
            {
                insertAtSpecificElement(head, &tail, data); // function calling
            }
            break;
        case 5:
            traverseFromBegning(head); // calling
            break;
        case 6:
            traverseFromEnd(tail); // calling
            break;
        default:
            printf("Enter the valid choice\n");
            break;
        }
    }
}
// function decleration of insert a element at the starting of the linked list
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
// insert a element at the end of the linked list
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
// insert a element after a specific element
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
        head = head->next;
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
// function decleration of insert at element at specific position
void insertAtSpecificElement(node *head, node **tail, int data)
{
    if (head == NULL)
    {
        printf("No data Found\n");
        return;
    }
    data--;
    while (data > 1 && head != NULL)
    {
        data--;
        head = head->next;
    }
    if (head == NULL)
    {
        printf("Enter a valid position\n");
    }
    else
    {
        temp = (node *)(malloc(sizeof(node)));
        printf("Enter the data you want to insert\n");
        scanf("%d", &data);
        temp->info = data;
        temp->prev = head;
        temp->next = head->next;
        head->next = temp;
        if (temp->next == NULL)
        {
            *tail = temp;
        }
        else
        {
            (temp->next)->prev = temp;
        }
        printf("Node insert successfully\n");
    }
}
// function decleration of traversing from begning
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
// function decleration of traversing from end
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
