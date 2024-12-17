#include<stdio.h> 
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* addatend(struct node*head,int data,int pos,int num)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*ptr;
	temp->data=data;
	temp->next=NULL;
	ptr=head;
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	if (pos==(num-1))
	{
		temp->next=head;
	}
	return head;
}
int main()
{
	int num,i;
	struct node*head= (struct node*)malloc(sizeof(struct node));
	head=NULL;
	printf("enter no of nodes you want in a circulalry single linked list");
	scanf("%d",&num);
	if (num==0)
	{
		printf("list is empty");
	}
	else
	{
		struct node*temp= (struct node*)malloc(sizeof(struct node));
		struct node*ptr;
		printf("enter the data of the first node");
		int val;
		scanf("%d",&val);
		temp->data=val;
		temp->next=NULL;
		head=temp;
		for(i=1;i<num;i++)
		{
			int data;
			printf("enter the value of the %d th node",i+1);
			scanf("%d",&data);
			head=addatend(head,data,i,num);
		}
		ptr=head;
	//	while(ptr->next != head)
	//	{
	//	   printf("%d  ",ptr->data);
	//	   ptr=ptr->next;
	//	} 
	//	printf("%d",ptr->data);
	int count=0;
	while (count<2)
	{
		if (ptr->next == head)
		{
			count++;
		}
		printf("%d  ",ptr->data);
		ptr=ptr->next;
	}
}
	return 0;
}