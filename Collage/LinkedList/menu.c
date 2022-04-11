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
		node *end=NULL;
		int count=0;
		clrscr();
	while (1)
	{
		printf("\nEnter your choice\n");
		printf("1 for insert an element\n");
		printf("2 for traversing\n");
		printf("3 for insert at end\n");
		printf("4 for search the element\n");
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
			  break;
			 }
			 while(temp!=NULL)
			 {
			 printf("%d ",temp->info);
			 temp=temp->next;
			 }
			break;
			case 3:
			   printf("Enter the element you want to insert at end\n");
			   scanf("%d",&data);
			   end=(node *)(malloc(sizeof(node)));
			   end->info=data;
			   temp=head;
			   while(temp->next!=NULL)
			   {
			   temp=temp->next;
			   }
			   if(temp->next==NULL)
			   {
			   temp->next=end;
			   end->next=NULL;
			   printf("Node insert successfully\n");
			   }
			   break;
			   case 4:
			   temp=head;
			   count=0;
			   printf("Enter the data you want to search\n");
			   scanf("%d",&data);
			   while(temp!=NULL)
			   {
				if(temp->info==data)
				{
				 count=1;
				 break;

				}
				temp=temp->next;
			   }
			   if(count==1)
				{
				 printf("Element found\n");
				}
				else
				{
				 printf("Element not found\n");
				}
				break;
		default:
			printf("Enter the valid choice");
			break;
		}
	}
}