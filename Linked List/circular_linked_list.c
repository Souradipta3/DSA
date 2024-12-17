#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("ELEMENT => %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *create(struct node *head, int pos, int num, int data)
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
        if (pos == num)
        {
            temp->next = head;
        }
        return head;
    }
}

int main()
{
    int n, data;
    struct node *head = NULL;
    printf("Enter the number of node/s:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the data of the %d node/s:", i);
        scanf("%d", &data);
        head = create(head, i, n, data);
    }
    traversal(head);
    return 0;
}
