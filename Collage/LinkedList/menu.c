#include <stdio.h>
#include <stdlib.h>
#include <process.h>
typedef struct lkList
{
    int info;
    struct lkList *next;
} node;
void main()
{
    while (1)
    {
        int n = 0, data = 0;
        node *temp = NULL;
        node *head = NULL;
        printf("\nEnter your choice\n");
        printf("1 for insert an element at begning\n");
        printf("13 for exit\n");
        scanf("%d", &n);
        if (n == 13)
            exit(1);
        switch (n)
        {
        case 1:
            printf("Enter the data you want to be insert\n");
            scanf("%d", &data);
            temp = (node *)malloc(sizeof(node));
            if (temp == NULL)
            {
                printf("Can't assign value\n");
                break;
            }
            temp->info = data;
            temp->next = head;
            head = temp;
            printf("Node insert successfully at begning");
            break;

        default:
            break;
        }
    }
}
