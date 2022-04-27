#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coeff;
    int power;
    struct polynomial *next;
} node;
node *addRes = NULL;
node *head1 = NULL;
node *head2 = NULL;
node *temp = NULL;
int result;
// function prototype
void left(node *one); // here it is use to add left variable value
void main()
{
    void insertAtBeg(struct polynomial **, int, int);
    void traverse(node *);
    void addition(node *, node *);
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
            traverse(head1);
            break;
        case 2:
            traverse(head2);
            break;
        case 3:
            if (addRes == NULL)
            {
                addition(head1, head2);
                left(head1);
                left(head2);
            }
            if (addRes != NULL)
            {
                printf("The Addition of tho polynomial \n");
                traverse(addRes);
            }
        default:
            break;
        }
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
    int c = 0;          // here variable c is use as a counter
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