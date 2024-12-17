#include <stdio.h>
#include <stdlib.h>
#define size 3
int front = 0;
int rear = 0;
 int arr[size];

void enque()
{
    if ((rear + 1) % size == front)
    {
        printf("OVERFLOW!\n");
    }
    else
    {
        int value;
        printf("Enter the value for enque:");
        scanf("%d", &value);
        rear = (rear + 1) % size;
        arr[rear] = value;
    }
}

void deque()
{
    if (rear == front)
    {
        printf("UNDERFLOW!\n");
    }
    else
    {
        int value;
        front = (front + 1) % size;
        value = arr[front];
        return;
    }
}

int main()
{
   
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
            enque();
            break;
        case 2:
            printf("The deque value is: %d\n", deque());
            break;
        case 3:
            exit(0);

        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
