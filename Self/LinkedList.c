#include <stdio.h>
#include <stdlib.h>
typedef struct ldList
{
    int info;
    struct ldList *next;
} node;
void main()
{
    int n = 0, data = 0;
    node *temp = NULL;
    node *head = NULL;
    node *ptr = NULL;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert node at begning\n");
        printf("2 insert element at the starting of linked list\n");
        printf("3 for traversing\n");
        printf("4 for insert an element after an element\n");
        printf("13 for exit\n");
        scanf("%d", &n);
        if (n == 13)
        {
            exit(1);
        }
        switch (n)
        {
        case 1:
            // this case use to enter node at begning
            printf("Enter the data your want to insert\n");
            scanf("%d", &data);
            // creating a node
            temp = (node *)(malloc(sizeof(node)));
            temp->info = data;
            temp->next = head;
            head = temp;
            printf("node inserted successfully\n");
            break;
        case 2:
            // Insert node at end of linked list
            printf("Enter the data you want to enter\n");
            scanf("%d", &data);
            temp = (node *)(malloc(sizeof(node)));
            temp->info = data;
            temp->next = NULL;
            ptr = head;
            if (ptr == NULL)
            {
                head = temp;
                break;
            }
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            break;
        case 3:
            temp = head;
            while (temp != NULL)
            {
                printf("%d ", temp->info);
                temp = temp->next;
            }
            break;
        case 4:
            printf("Enter the specific element where you want to insert the element\n");
            scanf("%d", data);
            ptr = head;
            if (ptr == NULL)
            {
                printf("No data found\n");
                break;
            }
            while (ptr->next != NULL)
            {
                if (data == ptr->info)
                {
                    break;
                }
                ptr = ptr->next;
            }
            if (ptr->next == NULL)
            {

                printf("Element not found\n");
            }
            else
            {
                printf("Enter the element that you want to insert\n");
                scanf("%d", &data);
                temp = (node *)(malloc(sizeof(node)));
                temp->info = data;
                temp->next = ptr->next;
                ptr->next = temp;
                printf("Node Insert successfully\n");
            }
            break;
        default:
            printf("Enter the valid choice\n");
            break;
        }
    }
}