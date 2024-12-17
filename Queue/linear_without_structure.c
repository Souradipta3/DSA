#include <stdio.h>
#include <stdlib.h>
#define size 3
int front = 0;
int rear = -1;

void enque(int arr[size])
{
    if (rear == size - 1)
    {
        printf("OVERFLOW!\n");
    }
    else
    {
        int value;
        printf("Enter the value for enque:");
        scanf("%d", &value);
        rear++;
        arr[rear] = value;
    }
}

int deque(int arr[size])
{
    if (rear + 1 == front)
    {
        printf("UNDERFLOW!\n");
    }
    else
    {
        int value;
        value = arr[front];
        front++;
        return value;
    }
}

int main()
{
    
    int arr[size];
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
            enque(arr);
            break;

        case 2:
            printf("The retrieved value is %d.\n", deque(arr));
            break;

        case 3:
            exit(0);

        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}