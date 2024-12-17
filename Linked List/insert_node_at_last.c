#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node *create(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
      head=temp;
    return head;
    }
    else
    {
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
    }
}

struct node *insert_at_last(struct node *head,int newdata)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=newdata;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}


void display(struct node *head)
{
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        printf("ELEMENT => %d\n",ptr->data);
        ptr=ptr->next;
    }
}


void newdisplay(struct node *head)
{
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        printf("ELEMENT => %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    int n,data,newdata;
    struct node *head=NULL;
    printf("Enter the number of node/s:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data of the %d node/s:",i+1);
        scanf("%d",&data);
        head=create(head,data);
    }
    display(head);
    printf("Enter the new node data:");
    scanf("%d",&newdata);
    insert_at_last(head,newdata);
    newdisplay(head);
    return 0;
}
