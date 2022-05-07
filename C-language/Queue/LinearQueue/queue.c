#include <stdio.h>
#include <stdlib.h>
typedef struct queueList
{
    int data[10];
    int front, rear;
} queue;
int i;
void enqueue(int data, queue *q);
void dequeue(queue *q);
void traverse(queue q);
void main()
{
    queue q;
    q.front = -1;
    q.rear = -1;
    int n = 0, data;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert\n");
        printf("2 for delete\n");
        printf("3 for traverse\n");
        printf("4 for exit\n");
        scanf("%d", &n);
        if (n == 4)
        {
            exit(0);
        }
        switch (n)
        {
        case 1:
            printf("Enter the element you want to insert\n");
            scanf("%d", &data);
            enqueue(data, &q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            traverse(q);
        default:
            break;
        }
    }
}
void enqueue(int data, queue *q)
{
    if (q->rear == -1)
    {
        (q->front)++;
        (q->rear)++;
    }
    else if (q->rear == 9 && q->front != 0)
    {
        int len = q->front - q->rear;
        for (i = 0; i < len; i++)
        {
            q->data[i] = q->data[q->rear];
            
        }
    }
    else if (q->rear > 9 && q->front == 0)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        q->data[q->rear] = data;
        (q->rear)++;
        printf("Data Insert Successfully");
    }
}
void dequeue(queue *q)
{
    if (q->front == -1)
    {
        printf("Underflow\n");
        return;
    }
    if (q->front < 9)
    {
        q->front++;
        printf("data delete successfully");
    }
    else
    {
        if (q->rear == q->front)
        {
            q->front = -1;
            q->rear = -1;
            printf("Underflow\n");
        }
    }
}
void traverse(queue q)
{
    if (q.rear == -1)
    {
        printf("No Element Found\n");
    }
    printf("The elements are\n");
    for (int i = q.front; i < q.rear; i++)
    {
        printf("%d ", q.data[i]);
    }
}