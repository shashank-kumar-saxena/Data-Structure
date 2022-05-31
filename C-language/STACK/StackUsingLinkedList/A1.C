#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
    int info;
    struct st *next;
}stack;
void push(stack **tos,int data);
void pop(stack **tos);
stack *temp=NULL;
void main()
{
        stack *tos=NULL;
    int n,data;
    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1 for push\n");
        printf("2 for pop\n");
        printf("3 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter the element you want to insert\n");
            scanf("%d",&data);
            push(&tos,data);
            break;
            case 2:
            pop(&tos);
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Enter the valid choice\n");
        }
    }
}
void push(stack **tos,int data)
{
    temp=(stack *)(malloc(sizeof(stack)));
    if(temp==NULL)
    {
        printf("Stack Overflow");
        return;
    }
    temp->info=data;
    temp->next=*tos;
    *tos=temp;
    printf("Node inserted successfully\n");
}
void pop(stack **tos)
{
    if(*tos==NULL)
    {
        printf("No ELement found\n");
        return;
    }
    printf("%d\nElement poped",(*tos)->info);
    *tos=(*tos)->next;
}
