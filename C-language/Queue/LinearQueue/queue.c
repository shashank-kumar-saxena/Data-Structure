#include <stdio.h>
#include <stdlib.h>
typedef struct typeQueue
{
    int a[10];
    int front;
    int rear;
} queue;
void main()
{
    void enqueue(queue *, int);
    void dequeue(queue *);
    void traverse(queue);
    queue q;
    int n = 0, data;
    q.front = q.rear = -1;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1 for insert an element\n");
        printf("2 for delete an element\n");
        printf("3 for travere in list\n");
        printf("4 for exit\n");
        scanf("%d", &n);
        if (n == 4)
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
            dequeue(&q);
            break;
        case 3:
            traverse(q);
            break;
        default:
            break;
        }
    }
}
void enqueue(queue *q, int data)
{
    if (q->front == 0 && q->rear == 9)
    {
        printf("Overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->front > 0 && q->rear == 9)
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            q->a[i - q->front] = q->a[i];
        }
        q->rear = q->rear - q->front;
        q->front = 0;
        (q->rear)++;
    }
    else
    {
        (q->rear)++;
    }
    q->a[q->rear] = data;
    printf("Element Inserted");
}
void dequeue(queue *q)
{
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
        printf("Underflow");
        return;
    }
    (q->front)++;
    printf("Element deleted");
}
void traverse(queue q)
{
    if (q.front == q.rear)
    {
        printf("No Element Found\n");
        return;
    }
    int i = 0;
    for (i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.a[i]);
    }
}
