// by shashank
#include <stdio.h>
#include <stdlib.h>
typedef struct lklist
{
    int info;
    struct lklist *next;
} node;
node *temp = NULL;
void insertAtBeg(node **head, int data);
void insertAtEnd(node *head, int data);
void traversing(node *head);
int main()
{

    int n = 0, data = 0;
    node *head = NULL;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert at begning\n");
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
            insertAtBeg(&head, data);
            break;
        case 5:
            traversing(head);
            break;
        default:
            printf("Enter the valid choice\n");
            break;
        }
    }
    return (1);
}
void insertAtBeg(node **head, int data)
{
    temp = (node *)(malloc(sizeof(node)));
    temp->info = data;
    temp->next = *head;
    *head = temp;
    printf("node insert successfully\n");
}
void traversing(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
}
