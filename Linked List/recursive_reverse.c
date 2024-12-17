#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *create(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
        return head;
    }
}

struct node *reversall(struct node *head, struct node *next, struct node *prev)
{
    if (next == NULL)
    {
        head = prev;
        return head;
    }
    head = next->link;
    reversall(head, prev, next);
    next->link = prev;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    head = reversall(head, next, prev);
    return head;
}

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    int n;
    struct node *head = NULL;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    int data;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data of the nodes:");
        scanf("%d", &data);
        head = create(head, data);
    }
    printf("Before reversing the list...\n");
    display(head);
    head = reverse(head);
    printf("After reversing the list...\n");
    display(head);
    return 0;
}
