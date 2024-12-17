#include <stdio.h>
#include <stdlib.h>
#define size 5

struct stack
{
    int arr[size];
    int top_a, top_b;
};

void push(struct stack *stk, int flag)
{
    if ((stk->top_a) + 1 == (stk->top_b))
    {
        printf("OVERFLOW\n");
        return;
    }
    int val;
    printf("Enter the value to be pushed:\n");
    scanf("%d", &val);
    if (flag == 1)
    {
        (stk->top_a)++;
        stk->arr[stk->top_a] = val;
    }
    else if (flag == 2)
    {
        (stk->top_b)--;
        stk->arr[stk->top_b] = val;
    }
}

int pop(struct stack *stk, int flag)
{
    if ((flag == 1 && stk->top_a == -1) || (flag == 2 && stk->top_b == 5))
    {
        return -9999;
    }
    int val;
    if (flag == 1)
    {
        val = stk->arr[stk->top_a];
        (stk->top_a)--;
    }
    else if (flag == 2)
    {
        val = stk->arr[stk->top_b];
        (stk->top_b)++;
    }
    return val;
}

int main()
{
    struct stack stk;
    stk.top_a = -1;
    stk.top_b = size - 1;
    int choice, value, flag;
    while (1)
    {
        printf("Press 1 for above push.\n");
        printf("Enter 2 for bottom push.\n");
        printf("Enter 3 for bottom pop.\n");
        printf("Enter 4 for above pop.\n");
        printf("Enter 5 for exit.\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            flag = 0;
            push(&stk, flag);
            break;
        case 2:
            flag = 1;
            push(&stk, flag);
            break;
        case 3:
            flag = 0;
            pop(&stk, flag);
            if (value == -9999)
            {
                printf("UNDERFLOW\n");
                break;
            }
            printf("The popped value is %d\n", value);
            break;
        case 4:
            flag = 1;
            pop(&stk, flag);
            if (value = -9999)
            {
                printf("UNDERFLOW\n");
                break;
            }
            printf("The popped value is %d\n", value);
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice!\n");
        }
    }
    return 0;
}
