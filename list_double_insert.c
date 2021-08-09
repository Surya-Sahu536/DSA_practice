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
}*head,*tail,*ptr,*new;

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

void insert(int pos,int elm,struct node *curr)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->val=elm;
    if(pos==1)
    {
        new->prev=NULL;
        new->next=curr;
        head=new;
        curr->prev=new;
    }
    for(int i=1;i<=pos;i++,curr=curr->next)
    {
        
        if(curr==NULL)
        {
            printf("position not found \n");
            return;
        }
        if(curr->next==NULL&&i==pos-1)
        {
            curr->next=new;
            new->next=NULL;
            new->prev=curr;
            tail=new;
            return;
        }
        if(i==pos-1)
        {
            new->next=curr->next;
            new->prev=curr;
            curr->next->prev=new;
            curr->next=new;
            printf("\ninserted successfully\n");
        }
    }
}

int main()
{
    int n,i,j,pos,elm;
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
    printf("\nEnter position and element to be inserted  ");
    scanf("%d %d",&pos,&elm);
    insert(pos,elm,head);
    display(head);
    display_rev(tail);
    return 0;
}
