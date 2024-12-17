#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insertAtBeginning(node **lnp, int value);
void insertAtEnd(node **lnp, int value);
void displayList(node *lnp);
int searchinList(node *lnp, int value);
int josephusWinner(node *lnp, int n);

int main()
{
    node *lnp = NULL;
    int value;
    int n;
    do
    {
        int choice;
        printf("Enter Your Choice : \n 1.Insert at Beginning , \n 2.Insert at End , \n 3. Display , \n 4. Search  , \n 5. Play Josephus Game \n 6. Exit .\n Choice :");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d", &value);
            insertAtBeginning(&lnp, value);
            break;
        case 2:
            printf("Enter value to insert : ");
            scanf("%d", &value);
            insertAtEnd(&lnp, value);
            break;
        case 3:
            displayList(lnp);
            break;
        case 4:
            printf("Enter value to insert : ");
            scanf("%d", &value);
            searchinList(lnp, value);
            break;

        case 5:
            printf("Enter The Josephus beginning index : ");
            scanf("%d", &n);
            josephusWinner(lnp, n);
        case 6:
            exit(1);
            break;
        default:
            printf("Invalid Choice !");
            break;
        }
    } while (1);
}

void insertAtBeginning(node **lnp, int value)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = value;
    if (*lnp == NULL)
    {
        *lnp = p;
        p->next = *lnp;
        printf("%d is inserted in Null Linked List !\n", value);
        return;
    }
    p->next = (*lnp)->next;
    (*lnp)->next = p;
    printf("%d is inserted in Beginning !\n", value);
}
void insertAtEnd(node **lnp, int value)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = value;
    if (*lnp == NULL)
    {
        *lnp = p;
        p->next = *lnp;
        printf("%d is inserted in Null Linked List !\n", value);
        return;
    }
    p->next = (*lnp)->next;
    (*lnp)->next = p;
    (*lnp) = p;
    printf("%d is inserted in End !\n", value);
}
void displayList(node *lnp)
{
    node *temp;
    if ((lnp) == NULL)
    {
        printf("Linked List is Empty !\n");
        return;
    }

    temp = (lnp)->next;
    printf("Following Linked List is : \n");
    do
    {
        printf(" %d->", (temp)->data);
        (temp) = (temp)->next;
    } while (temp != lnp->next);
    printf(" %d\n", (temp)->data);
}
int searchinList(node *lnp, int value)
{
    node *temp = lnp->next;
    int count = 0;
    if (lnp == NULL)
    {
        printf("Linked List is Empty !");
        return 0;
    }
    do
    {
        if (temp->data == value)
        {
            printf("%d value is found in Node number %d \n", value, count);
            return count;
        }
        temp = temp->next;
        count++;
    } while (temp != lnp->next);
}

int josephusWinner(node *lnp, int n)
{
    if (lnp == NULL)
    {
        printf("Linked List is Empty !");
    }
    while (lnp->next != lnp)
    {
        node *p = lnp->next;
        node *q = lnp;
        int i = 1;
        while (i < n)
        {
            q = p;
            p = p->next;
            i++;
        }
        if (p != lnp)
        {
            q->next = p->next;
            p->next = NULL;
            free(p);
            p = NULL;
        }
        else
        {
            q->next = p->next;
            lnp = q;
            p->next = NULL;
            free(p);
            p = NULL;
        }
    }
    printf("Winner is node %d\n", lnp->data);
}