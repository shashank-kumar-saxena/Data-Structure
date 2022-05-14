#include <stdio.h>
#include <conio.h>
typedef struct typeQueue
{
    int a[10];
    int front;
    int rear;
} queue;
void main()
{
    void enqueue(queue *, int);
    queue q;
    int n = 0, data;
    q.front = q.rear = -1;
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
    else if (q->front > 0 && q->rear == 0)
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            q->a[i - q->front] = q->a[i];
        }
        q->rear = q->front - q->rear;
        q->front = 0;
        (q->rear)++;
    }
    else
    {
        (q->rear)++;
    }
    q->a[q->rear] = data;
}