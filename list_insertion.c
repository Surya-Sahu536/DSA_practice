/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
}*ptr,*new,*head;

void display(struct node *curr)
{
    for(;curr!=NULL;curr=curr->next)
        printf("%d  ",curr->val);
    printf("\n");
}

void insert(int pos,int elm,struct node *curr)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->val=elm;
    if(pos==1)
    {
        new->next=curr;
        head=new;
    }
    for(int i=1;i<=pos-1;i++,curr=curr->next)
    {
        if(curr->next==NULL)
        {
            printf("position not found\n");
            return;
        }
        if(i==pos-1)
        {
            new->next=curr->next;
            curr->next=new;
            printf("inserted successfully\n");
        }
    }
}

#include <stdio.h>

int main()
{
    int n,i,pos,elm;
    printf("Enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,ptr=new)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter node no %d  ",i+1);
        scanf("%d",&(new->val));
        new->next=NULL;
        if(i==0)
            head=new;
        else
            ptr->next=new;
    }
    display(head);
    printf("enter position and element  ");
    scanf("%d %d",&pos,&elm);
    insert(pos,elm,head);
    display(head);

    return 0;
}
