#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data);
}

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
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        return head;
    }
}

struct node *delete(struct node* head)
{
    int target;
    printf("\nEnter the node to be deleted:");
    scanf("%d",&target);
    struct node *ptr=head;
    while(ptr->data!=target)
    {
        ptr=ptr->next;
    }
    struct node *q=ptr->next;
    q->prev=ptr->prev;
    ptr->prev->next=q;
    ptr->prev=NULL;
    ptr->next=NULL;
    free(ptr);
    return head;
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
        head = create(head,data);
    }
    display(head);
    delete(head);
    display(head);
    return 0;
}
