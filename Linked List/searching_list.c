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

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->link;
    }
}

void search(struct node* head, int item)
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
        {
            printf("The element is found in the index number %d.\n",ptr->link);
            return;
        }
        ptr=ptr->link;
    }
    printf("The element is not present in the list.\n");
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
    display(head);
    int item;
    printf("Enter the element to be searched:");
    scanf("%d",&item);
    search(head,item);
    return 0;
}
 