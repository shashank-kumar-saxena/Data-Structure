
#include <stdio.h>
#include <stdlib.h>
typedef struct lkList
{
    int info;
    struct lkList *next;
} node;

void main()
{
    node *head = NULL;
    node *temp = NULL;
    int data;
    int num = 0;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert at begning\n");
        printf("2 for traverse\n");
        printf("5 for exit\n");
        scanf("%d", &num);
        if (num == 5)
        {
            exit(1);
        }
        switch (num)
        {
        case 1:
            // O(1) best case
            printf("Enter the data\n");
            scanf("%d", &data);
            temp = (node *)malloc(sizeof(node));
            temp->info = data;
            temp->next = head;
            head = temp;
            printf("Node Insert Successfully\n");
            break;
        case 2:
            // O(n)
            if (head == NULL)
            {
                printf("No element found\n");
                return;
            }
            printf("Data is\n");
            temp = head;
            while (temp != NULL)
            {
                printf("%d ", temp->info);
                temp = temp->next;
            }
            break;
        default:
            break;
        }
    }
}
