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
void insertAtBeg(node **head, int data);              // case 1
void insertAtEnd(node **head, int data);              // case 2
void insertAfterSpecific(node **head, int data);      // case 3      // here data variable use to pass element after which we want to insert the element
void insertAtSpecificPosition(node **head, int data); // case 4 // here data variable use to pass position where we want to insert element
void traversing(node *head);                          // case 5
void deleteSpecific(node **head, int data);           // case 6 // here data variable use to provide a element that we want to delete
void deleteSpecificPosition(node **head, int data);   // case 7 //here data variable use to provide a position which element you want to delete
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
        printf("4 for insert at specific element\n");
        printf("5 for traversing\n");
        printf("6 for delete a element\n");
        printf("7 for delete a element at specific element\n");
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
        case 4:
            printf("Enter the position where you want to insert the element");
            scanf("%d", &data);
            insertAtSpecificPosition(&head, data);
            break;
        case 5:
            traversing(head); // calling
            break;
        case 6:
            printf("Enter the element you want to delete\n");
            scanf("%d", &data);
            deleteSpecific(&head, data);
            break;
        case 7:
            printf("Enter the position of element which you want to delete\n");
            scanf("%d", &data);
            deleteSpecificPosition(&head, data);
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
// function decleration for insert element at specific position
void insertAtSpecificPosition(node **head, int data)
{
    node *ptr = *head;
    data--;
    while (data > 1 && ptr != NULL)
    {
        ptr = ptr->next;
        data--;
    }
    if (ptr != NULL)
    {
        printf("Enter the element that you want to insert\n");
        scanf("%d", &data);
        temp = (node *)(malloc(sizeof(node)));
        temp->info = data;
        temp->next = ptr->next;
        ptr->next = temp;
        printf("node insert successfully\n");
    }
    else
    {
        printf("Enter the vaid position\n");
    }
}
// function decleration for delete a particular element
void deleteSpecific(node **head, int data)
{
    if (*head == NULL)
    {
        printf("no element found\n");
    }
    node *ptr = *head;
    if (ptr->info == data)
    {
        ptr = *head;
        *head = ptr->next;
        free(ptr);
        printf("Node delete successfully\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            if (data == (ptr->next)->info)
            {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                printf("Node insert successfully\n");
                break;
            }
            ptr = ptr->next;
        }
        if (ptr == NULL)
            printf("no element found\n");
    }
}
// function decleration of delete a specific element with the help of position
void deleteSpecificPosition(node **head, int data)
{
    data--;
    node *ptr = *head;
    if (ptr == NULL)
    {
        printf("No data present\n");
        return;
    }
    if (ptr->next == NULL)
    {
        free(head);
        *head = NULL;
        printf("data delete successfully\n");
        return;
    }
    while (data > 0 && ptr != NULL)
    {
        data--;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("no data found or limit exceed\n");
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        printf("data delete successfully\n");
    }
}