/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
}*ptr,*head,*temp;

void display(struct node *curr)
{
    for(;curr!=NULL;curr=curr->next)
        printf("%d  ",curr->val);
    printf("\n");
}

void swap(int pos,struct node *curr)
{
    struct node *swp=NULL;
    if(pos==1)
    {
        head=curr->next;
        curr->next=curr->next->next;
        head->next=curr;
        printf("swapped successfully\n");
    }
    for(int i=1;i<pos;i++,curr=curr->next)
    {
        if(curr->next==NULL)
        {
            printf("no element exist on that position\n");
            return;
        }
        if(curr->next->next==NULL)
        {
            printf("last node cant be swapped\n");
            return;
        }
        if(i==pos-1)
        {
            swp=curr->next->next;
            curr->next->next=curr->next->next->next;
            swp->next=curr->next;
            curr->next=swp;
            printf("swapped successfully\n");
        }
    }
    
    
}

int main()
{
    int n,i,pos;
    printf("Enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,temp=ptr)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter node no %d :  ",i+1);
        scanf("%d",&(ptr->val));
        ptr->next=NULL;
        if(i==0)
            head=ptr;
        else
            temp->next=ptr;
    }
    display(head);
    printf("\nEnter position of element to be swapped  ");
    scanf("%d",&pos);
    swap(pos,head);
    display(head);

    return 0;
}
