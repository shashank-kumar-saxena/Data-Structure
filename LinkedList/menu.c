#include <stdio.h>
#include <stdlib.h>
typedef struct lkList
{
    int info;
    struct lkList *next;
} node;
void main()
{
		int n = 0, data = 0;
		node *temp = NULL;
		node *head = NULL;
		clrscr();
	while (1)
	{
		printf("\nEnter your choice\n");
		printf("1 for insert an element\n");
		printf("2 for traversing\n");
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
			printf("Node insert successfully");
			break;
		 case 2:
			 temp=head;
			 if(temp==NULL)
			 {
			  printf("No data found\n");
			 }
			 while(temp!=NULL)
			 {
			 printf("Value of node is %d\n",temp->info);
			 temp=temp->next;
			 }
			break;
		default:
			printf("Enter the valid choice");
			break;
		}
	}
}
