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
    struct node *prev;
}*head,*tail,*new,*ptr,*temp;

void display(struct node *curr)
{
    for(;curr!=NULL;curr=curr->next)
        printf("%d ",curr->val);
}

void display_rev(struct node *curr)
{
    printf("\n");
    for(;curr!=NULL;curr=curr->prev)
        printf("%d ",curr->val);
}

void swap(int pos,struct node *curr)
{
    if(pos==1)
    {
        if(head==tail)
        {
            printf("last node can not be swapped\n");
            return;
        }
        head=curr->next;
        curr->next=curr->next->next;
        head->next=curr;
        head->prev=NULL;
        curr->prev=head;
        if(curr->next==NULL)
            tail=curr;
        else
            curr->next->prev=curr;
    }
    for(int j=1;j<=pos-1;j++,curr=curr->next)
    {
        if(curr->next==NULL)
        {
            printf("position not found\n");
            return;
        }
        if(curr->next->next==NULL&&j==pos-1)
        {
            printf("last node can not be swapped\n");
            return;
        }
        if(j==pos-1)
        {
            temp=curr->next;
            curr->next=curr->next->next;
            temp->next=curr->next->next;
            curr->next->next=temp;
            curr->next->prev=curr;
            temp->prev=curr->next;
            
            if(temp->next==NULL)
                tail=temp;
            else
                temp->next->prev=temp;
        }
    }
    
}

int main()
{
    int n,i,pos;
    printf("Enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,ptr=new)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter node no %d  ",i+1);
        scanf("%d",&(new->val));
        new->next=NULL;
        new->prev=NULL;
        tail=new;
        if(i==0)
        {
            head=new;
        }
        else
        {
            ptr->next=new;
            new->prev=ptr;
        }
    }
    printf("enter the position to be swapped  ");
    scanf("%d",&pos);
    swap(pos,head);
    display(head);
    display_rev(tail);

    return 0;
}
