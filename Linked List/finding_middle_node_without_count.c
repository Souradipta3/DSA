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

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("ELEMENT => %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int middle(struct node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head->data;
    }
    if(head->next->next==NULL)
    {
        return head->next->data;
    }
    struct node *before=head;
    struct node *after=head->next;
    while(after!=NULL)
    {
        after=after->next;
        if(after!=NULL)
        {
            after=after->next;
        }
        before=before->next;
    }
    //printf("The middle node data is =>%d\n",before->data);
    return before->data;
}

int main()
{
    int n, data;
    //struct node *mid;
    struct node *head = NULL;
    printf("Enter the number of node/s:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data of the %d node/s:", i + 1);
        scanf("%d", &data);
        head = create(head, data);
    }
    display(head);
    //mid=middle(head);
    printf("The middle node is %d and the address is %u.\n",middle(head));
    return 0;
}