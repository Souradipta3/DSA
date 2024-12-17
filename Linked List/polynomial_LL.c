#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int expo;
    struct node *next;
};

struct node *create(struct node *head, int coef, int expo)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coef = coef;
    temp->expo = expo;
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

struct node *input(struct node *head)
{
    int n, coe, exp;
    printf("Enter the no. of terms in the polynomial:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d coefficient:", i + 1);
        scanf("%d", &coe);
        printf("Enter the %d exponent:", i + 1);
        scanf("%d", &exp);
        head = create(head, coe, exp);
    }
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        struct node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d^%d", ptr->coef, ptr->expo);
            ptr = ptr->next;
            if (ptr != NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void poly_add(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    if (head1 == NULL && head2 == NULL)
    {
        printf("\nAddition is not possible!\n");
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = create(head3, ptr1->coef + ptr2->coef, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = create(head3, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = create(head3, ptr2->coef, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = create(head3, ptr1->coef, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = create(head3, ptr2->coef, ptr2->expo);
        ptr2 = ptr2->next;
    }
    printf("Added polynomial is =>\n");
    display(head3);
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter the first polynomial:\n");
    head1 = input(head1);
    display(head1);
    printf("Enter the second polynomial:\n");
    head2 = input(head2);
    display(head2);
    poly_add(head1, head2);
    return 0;
}
