// Code By Shashank
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
		printf("1 for insert element at begning\n");
		printf("2 insert element at end\n");
		printf("3 for insert an element at a specific position\n");
		printf("4 for insert element after specific element\n");
		printf("5 for traversing\n");
		printf("6 for search the element\n");
		printf("7 for delete a specific element\n");
		printf("8 for delete a element at specific position\n");
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
			// Insert a element at specific position
			printf("Enter the position where you want to insert the node\n");
			scanf("%d", &data);
			data--;
			ptr = head;
			while (data >= 1 && ptr != NULL)
			{
				ptr = ptr->next;
				data--;
			}
			if (ptr != NULL)
			{
				printf("Enter the data you want to insert\n");
				scanf("%d", &data);
				temp = (node *)(malloc(sizeof(node)));
				temp->info = data;
				temp->next = ptr->next;
				ptr->next = temp;
				printf("Node Insert successfully\n");
			}
			else
			{
				printf("Limit Exceed\n");
			}
			break;
		case 4:
			// Insert node after a specific element
			printf("Enter the specific element after which you want to insert the element\n");
			scanf("%d", &data);
			ptr = head;
			if (ptr == NULL)
			{
				printf("No data found\n");
				break;
			}
			while (ptr != NULL)
			{
				if (data == ptr->info)
				{
					break;
				}
				ptr = ptr->next;
			}

			if (ptr == NULL)
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
		case 5:
			temp = head;
			while (temp != NULL)
			{
				printf("%d ", temp->info);
				temp = temp->next;
			}
			break;
		case 6:
			printf("Enter the element that you want to search\n");
			scanf("%d", &data);
			ptr = head;
			while (ptr != NULL)
			{
				if (ptr->info == data)
					break;
				ptr = ptr->next;
			}
			if (ptr == NULL)
			{
				printf("Element not found\n");
			}
			else
			{
				printf("Element found\n");
			}
			break;
		case 7:
			printf("Enter the element you want to delete\n");
			scanf("%d", &data);
			ptr = head;
			if (ptr->info == data)
			{
				temp = head;
				head = ptr->next;
				free(temp);
				printf("node delete successfully\n");
				break;
			}
			if (ptr->next != NULL)
				while (ptr->next != NULL)
				{
					if (data == (ptr->next)->info)
					{
						break;
					}
					ptr = ptr->next;
				}
			if (ptr != NULL)
			{
				temp = ptr->next;
				ptr->next = temp->next;
				free(temp);
				printf("Element delete successfully\n");
			}
			else
			{
				printf("Element not found\n");
			}
			break;
		case 8:
			printf("Enter position where you want to delete the element\n");
			scanf("%d", &data);
			ptr = head;
			if (ptr == NULL)
			{
				printf("No data present\n");
				return;
			}
			if (data == 1)
			{
				temp = head;
				head = ptr->next;
				free(temp);
				printf("Node delete successfully\n");
				break;
			}
			data--;
			while (data > 1 && ptr != NULL)
			{
				ptr = ptr->next;
				data--;
			}
			if (ptr != NULL)
			{
				temp = (ptr->next);
				if (ptr->next != NULL)
					ptr->next = (ptr->next)->next;
				free(temp);
				printf("node delete successully\n");
			}
			break;
		default:
			printf("Enter the valid choice\n");
			break;
		}
	}
}
