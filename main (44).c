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

void rev(struct node *curr)
{
    tail=head;
    temp=NULL;
    for(;curr!=NULL;curr=curr->prev)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
    }
    if(temp!=NULL)
        head=temp->prev;
    printf("\nreversed successfully\n");
    
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
    display(head);
    display_rev(tail);
    rev(head);
    display(head);
    display_rev(tail);

    return 0;
}
