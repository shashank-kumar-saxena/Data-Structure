#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
	int coeff;
	int power;
	struct polynomial *next;
} node;
node *addRes = NULL; // use to point addition link list
node *head1 = NULL;	 // use to point first polynomial
node *head2 = NULL;	 // use to point second polynomial
node *temp = NULL;	 // use to create a node
node *ptr = NULL;	 // use for traverse in left function
node *mul = NULL;	 // use to point multiplication node
int result, t2 = 0, p2;
// function prototype
void left(node *one);  // here it is use to add left variable value
void sort(node *temp); // use for sort the polynomial
void main()
{
	// function prototyping
	void insertAtBeg(struct polynomial **, int, int);
	void traverse(node *);
	void addition(node *, node *);
	void multi(node *, node *);
	int c, p, i, n;
	printf("Enter the terms in first polynomial\n");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Enter the cofficent and power of %dth\n", i);
		scanf("%d%d", &c, &p);
		insertAtBeg(&head1, c, p);
	}
	printf("Enter the terms in second polynomial\n");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Enter the cofficent and power of %dth\n", i);
		scanf("%d%d", &c, &p);
		insertAtBeg(&head2, c, p);
	}
	while (1)
	{
		printf("\nEnter your choice\n");
		printf("1 for view 1st polynomial\n");
		printf("2 for view 2nd polynomial\n");
		printf("3 for addition\n");
		printf("4 for multipication\n");
		printf("5 for exit\n");
		scanf("%d", &n);
		if (n == 5)
			exit(1);
		switch (n)
		{
		case 1:

			sort(head1);
			traverse(head1);
			break;
		case 2:

			sort(head2);
			traverse(head2);
			break;
		case 3:
			if (addRes == NULL)
			{
				addition(head1, head2);
				left(head1);
				left(head2);
				sort(addRes);
			}
			if (addRes != NULL)
			{
				printf("The Addition of tho polynomial \n");
				traverse(addRes);
			}
			break;
		case 4:
			if (mul == NULL)
			{
				multi(head1, head2);
				sort(mul);
			}
			if (mul != NULL)
			{
				printf("The multiplication is \n");
				traverse(mul);
			}
			break;
		default:
			printf("Enter the valid choice\n");
			break;
		}
	}
}
void sort(node *t)
{
	while (t != NULL)
	{
		for (ptr = t; ptr != NULL; ptr = ptr->next)
		{
			if ((t->power) < (ptr->power))
			{
				t2 = t->coeff;
				t->coeff = ptr->coeff;
				ptr->coeff = t2;
				p2 = t->power;
				t->power = ptr->power;
				ptr->power = p2;
			}
		}
		t = t->next;
	}
}
void insertAtBeg(struct polynomial **head, int c, int p)
{
	temp = (node *)(malloc(sizeof(node)));
	temp->coeff = c;
	temp->power = p;
	temp->next = (*head);
	*head = temp;
	printf("Value Inserted Successfully\n");
}
void traverse(node *head)
{
	if (head == NULL)
	{
		printf("No Data Found");
	}
	while (head != NULL)
	{
		if (head->coeff > 0)
		{
			printf("%dX^%d", head->coeff, head->power);
			if (head->next != NULL)
			{
				printf("+");
			}
		}
		else
		{
			printf("%dX^%d", head->coeff, head->power);
		}
		head = head->next;
	}
}
void addition(node *one, node *two)
{
	result = 0;
	// staring of while
	while (one != NULL)
	{
		two = head2;
		while (two != NULL)
		{
			if (one->power == two->power)
			{
				result = one->coeff + two->coeff;
				temp = (node *)(malloc(sizeof(node)));
				temp->coeff = result;
				temp->power = two->power;
				temp->next = addRes;
				addRes = temp;
			}
			two = two->next;
		}
		one = one->next;
	}
	// end of while
}
void left(node *one)
{
	// but till now some terms in first polynomial are left
	node *two = addRes; // now two use for traverse in partial obtained result so that left terms can be added
	int c = 0;			// here variable c is use as a counter
	while (one != NULL)
	{
		two = addRes;
		while (two != NULL)
		{
			if (one->power == two->power)
			{
				c++;
			}
			two = two->next;
		}
		if (c == 0)
		{
			temp = (node *)(malloc(sizeof(node)));
			temp->coeff = one->coeff;
			temp->power = one->power;
			temp->next = addRes;
			addRes = temp;
		}
		c = 0;
		one = one->next;
	}
}
// function for multiplication of two polynomial
void multi(node *head1, node *head2)
{
	while (head1 != NULL)
	{
		ptr = head2;
		while (ptr != NULL)
		{
			temp = (node *)(malloc(sizeof(node)));

			temp->coeff = (head1->coeff) * (ptr->coeff);
			if (head1->power != 0 && ptr->power != 0)
			{
				temp->power = (head1->power) * (ptr->power);
			}
			else
			{
				temp->power = (head1->power) + (ptr->power);
			}
			temp->next = mul;
			mul = temp;
			ptr = ptr->next;
		}
		head1 = head1->next;
	}
}