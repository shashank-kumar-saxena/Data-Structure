#include <stdio.h>
#include <stdlib.h>
typedef struct queueType
{
    int a[10];
    int front, rear;
} queue;
int i;
void main()
{
    void enqueue(queue *, int);
    void dequeue(queue *);
    void traverse(queue);
    queue q;
    int n, data;
    q.front = q.front = -1;
    while (1)
    {
        printf("Enter your choice\n");
        printf("1 for insert an element\n");
        printf("2 for delete an element\n");
        printf("3 for exit\n");
        scanf("%d", &n);
        if (n == 3)
        {
            exit(1);
        }
        switch (n)
        {
        case 1:
            printf("Enter the data you want to insert\n");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:

            break;
        default:
            break;
        }
    }
}
void enqueue(queue *q, int data)
{
    if (q->front == q->rear || (q->rear) + 1 == q->front)
    {
        printf("Overflow");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else if (q->front > 0 && q->rear == 9)
    {
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->a[q->rear] = data;
}
void delete (queue *q)
{
    if (q->front == q->rear)
    {
        printf("Underflow");
        return;
    }
    else if (q->front == 9)
    {
        q->front = 0;
    }
    else
    {
        q->front++;
    }
}
void traverse(queue q)
{
    if (q.rear > q.front)
    {
        for (i = q.front; i < 10; i++)
        {
            printf("%d", q.a[i]);
        }
    }
}