#include <stdio.h>
#include <stdlib.h>
typedef struct queueList
{
    int data[10];
    int front, rear;
} queue;
int i;
void enqueue(int data, queue *q);
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
        printf("3 for exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the element you want to insert\n");
            scanf("%d", &data);
            enqueue(data, &q);
            break;

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
    if (q->rear != 9)
    {
        q->data[q->rear] = data;
        (q->rear)++;
    }
    if (q->rear == 9 && q->front >= 0)
    {
        q->rear = q->front;
        q->front = 0;
        int len=q->rear;
        for (i = 0; i < len; i++)
        {
            q->data[(q->front)]=q->data[(q->rear)++];
        }
    }
    if (q->rear == 9 && q->front == -1)
    {
        printf("Overflow\n");
    }
}