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
}*head,*tail,*ptr,*new,*temp;

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

void delete(int pos,struct node *curr)
{
    if(head==tail)
    {
        temp=head;
        head=tail=NULL;
        free(temp);
        printf("\ndeleted successfully\n");
    }
    if(pos==1)
    {
        temp=curr;
        head=curr->next;
        head->prev=NULL;
        free(temp);
        printf("\ndeleted successfully\n");
    }
    for(int i=1;i<=pos;i++,curr=curr->next)
    {
        
        if(curr->next==NULL)
        {
            printf("position not found \n");
            return;
        }
        if(curr->next->next==NULL&&i==pos-1)
        {
            temp=curr->next;
            curr->next=NULL;
            tail=curr;
            free(temp);
            printf("\ndeleted successfully\n");
            return;
        }
        if(i==pos-1)
        {
            temp=curr->next;
            curr->next=curr->next->next;
            curr->next->prev=curr;
            free(temp);
            printf("\ndeleted successfully\n");
            return;
        }
    }
}

int main()
{
    int n,i,j,pos;
    printf("Enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,ptr=new)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter node no %d  ",i+1);
        scanf("%d",&(new->val));
        new->next=NULL;
        new->prev=NULL;
        if(i==0)
        {
            head=new;
            tail=new;
        }
        else
        {
            ptr->next=new;
            new->prev=ptr;
            tail=new;
        }
    }
    display(head);
    display_rev(tail);
    printf("\nEnter position to be deleted ");
    scanf("%d",&pos);
    delete(pos,head);
    display(head);
    display_rev(tail);
    return 0;
}
