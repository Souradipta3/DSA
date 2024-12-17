#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        return head;
    }
}

void sorting(struct node *head)
{
    int temp;
    struct node *before = head;
    struct node *after;
    while (before->next != NULL)
    {
        after=before->next;
        while (after != NULL)
        {
            if (before->data > after->data)
            {
                temp = before->data;
                before->data = after->data;
                after->data = temp;
            }
            after = after->next;
        }
        before = before->next;
    }
}

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("ELEMENT => %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int n, data;
    struct node *head = NULL;
    printf("Enter the number of node/s:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data of the %d node/s:", i + 1);
        scanf("%d", &data);
        head = create(head, data);
    }
    printf("Before Sorting...\n");
    display(head);
    sorting(head);
    printf("After Sorting...\n");
    display(head);
    return 0;
}
