#include <stdio.h>
#include <stdlib.h>
#define size 3

typedef struct circular_queue
{
    int front;
    int rear;
    int arr[size];
} cq;

void enque(cq *q)
{
    if ((q->rear + 1) % size == q->front)
    {
        printf("OVERFLOW!\n");
    }
    else
    {
        int value;
        printf("Enter the value for enque:\n");
        scanf("%d", &value);
        q->rear = (q->rear + 1) % size;
        q->arr[q->rear] = value;
    }
}

int deque(cq *q)
{
    if (q->rear == q->front)
    {
        printf("UNDERFLOW!\n");
        return -9999;
    }
    else
    {
        int value;
        q->front = (q->front + 1) % size;
        value = q->arr[q->front];
        return value;
    }
}

int main()
{
    cq *q = (cq *)malloc(size * sizeof(cq));
    q->front = 0;
    q->rear = 0;
    int choice;

    while (1)
    {
        printf("Enter 1 for enque.\n");
        printf("Enter 2 for deque.\n");
        printf("Enter 3 for exit.\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enque(q);
            break;
        case 2:
            printf("The deque value is: %d\n", deque(q));
            break;
        case 3:
            exit(0);

        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
