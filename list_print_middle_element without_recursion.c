/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
}*ptr,*newnode,*head;

void display(struct node *curr)
{
    for(;curr!=NULL;curr=curr->next)
        printf("%d ",curr->val);
}

void middle_elm(struct node *curr)
{
    struct node *slow,*fast;
    if(curr->next==NULL)
        printf("\nmiddle element is %d",curr->val);
    for(fast=curr,slow=curr;fast!=NULL && fast->next!=NULL;slow=slow->next,fast=fast->next->next)
    {
        if(fast->next->next==NULL)
            printf("\nmiddle elements are %d and %d ", slow->val, slow->next->val);
        else if(fast->next->next->next==NULL)
            printf("\nmiddle element is %d ",slow->next->val);
    }
}

int main()
{
    int n,i;
    printf("enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,ptr=newnode)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("memory not allocated");
            exit(0);
        }
        printf("enter node no %d  ",i+1);
        scanf("%d",&(newnode->val));
        newnode->next=NULL;
        if(i==0)
            head=newnode;
        else
            ptr->next=newnode;
    }
    
    display(head);
    middle_elm(head);

    return 0;
}
