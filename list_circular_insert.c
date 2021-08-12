/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next;
}*head,*new,*ptr,*last;

void display(struct node *curr)
{
    for(;curr->next!=head;curr=curr->next)
        printf("%d ",curr->val);
    printf("%d ",curr->val);
}

void insert(int pos,int elm,struct node *curr)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->val=elm;
    new->next=NULL;
    if(pos==1)
    {
        head=new;
        head->next=curr;
        if(curr->next==curr)
        {
            curr->next=head;
        }
        else
        {
            for(last=curr;last->next!=curr;last=last->next);
            last->next=head;
        }
        printf("\ninserted successfully\n");
        return;
    }
    for(int j=1;j<pos;j++,curr=curr->next)
    {
        if(curr->next==head&&j==pos-1)
        {
            curr->next=new;
            new->next=head;
            printf("\ninserted successfully\n");
            return;
        }
        if(j==pos-1)
        {
            new->next=curr->next;
            curr->next=new;
            printf("\ninserted successfully\n");
            return;
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
        if(i==0)
            head=new;
        else
            ptr->next=new;
        if(i==n-1)
            new->next=head;
    }
    display(head);
    printf("\nenter the position and element ");
    scanf("%d %d",&pos,&elm);
    insert(pos,elm,head);
    display(head);

    return 0;
}
