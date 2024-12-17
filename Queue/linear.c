#include <stdio.h>
#include <stdlib.h>
#define size 3

struct queue
{
    int arr[size];
    int front;
    int rear;
};

void enque(struct queue *q)
{
    if (q->rear == size - 1)
    {
        printf("OVERFLOW!\n");
    }
    else
    {
        int value;
        printf("Enter the value to be inserted:\n");
        scanf("%d", &value);
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int deque(struct queue *q)
{
    int value;
    if (q->front == q->rear + 1)
    {
        printf("UNDERFLOW!\n");
        return -9999;
    }
    else
    {
        value = q->arr[q->front];
        q->front++;
        return value;
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(size * sizeof(struct queue));
    q->front = 0;
    q->rear = -1;
    int choice;

    while (1)
    {
        printf("Press 1 for insert.\n");
        printf("Press 2 for retrieve.\n");
        printf("Press 3 for exit.\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enque(q);
            break;

        case 2:
            printf("The retrieved value is %d.\n", deque(q));
            break;

        case 3:
            exit(0);

        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
