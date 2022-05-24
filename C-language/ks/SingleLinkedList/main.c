
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
    node *ptr = NULL;
    int data;
    int num = 0;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert at begning\n");
        printf("2 for traverse\n");
        printf("3 for insert at end\n");
        printf("4 for searching\n");
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
            ptr = head;
            while (ptr != NULL)
            {
                printf("%d ", ptr->info);
                ptr = ptr->next;
            }
            break;
        case 3:
            // O(n)
            printf("Enter the data you want to insert\n");
            scanf("%d", &data);
            temp = (node *)malloc(sizeof(node));
            temp->info = data;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = temp;
            }
            printf("Node Inserted sucessfully\n");
            break;
        case 4:
            printf("Enter the element yoy want to search\n");
            scanf("%d", &data);
            if (head == NULL)
            {
                printf("Element not found\n");
                break;
            }
            ptr = head;
            int flag = 0, count = 0;
            while (ptr != NULL)
            {
                count++;
                if (ptr->info == data)
                {
                    flag++;
                    break;
                }
                ptr = ptr->next;
            }
            if (flag == 1)
            {

                printf("Element found at node %d", count);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        default:
            break;
        }
    }
}
