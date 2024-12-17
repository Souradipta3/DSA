#include<stdio.h>
#include<stdlib.h>

//creating node like structure
struct NODE{
	int data;
	struct NODE *link;
};
struct NODE *FIRST = NULL;
struct NODE *LAST = NULL;
struct NODE *TEMP, *CURR;

//FUNCTION 1 FOR node creation
void creatList(int input){
	TEMP = (struct NODE*)malloc(sizeof(struct NODE));
	TEMP->data = input;
	TEMP->link = NULL;
	if(FIRST == NULL){
		FIRST = TEMP;
	}
	else{
		CURR = FIRST;
		while(CURR->link !=NULL){
			CURR = CURR->link;
		}
		CURR-> link = TEMP;
	}	
}

//function 2 for node display
void display(){
	struct NODE* CURR=FIRST;
	while(CURR != NULL){
		printf("Data : %d", CURR ->data);
		CURR = CURR->link;
	}
}

// main function
int main(){
	int a;
	printf("Enter value of a node :");
	scanf("%d", &a);
	creatList(a);
	display();
}
