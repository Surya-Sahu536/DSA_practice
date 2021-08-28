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
    slow=curr;
    for(fast=curr;fast!=NULL;slow=slow->next,fast=fast->next->next)
    {
        printf(" -%d %d %d- ",fast->val,fast->next->next->val,fast->next->next->val);
        if(fast->next->next==NULL)
        {
            printf("\nmiddle nodes are %d and %d ",slow->val,slow->next->val);
            break;
        }
        if(fast->next->next->next==NULL)
        {
            printf(" -%d %d %d- ",fast->val,fast->next->next->val,fast->next->next->val);
            
        }
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
