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
}*head,*new,*ptr,*last,*temp;

void display(struct node *curr)
{
    for(;curr->next!=head;curr=curr->next)
        printf("%d ",curr->val);
    printf("%d ",curr->val);
}

void delete(int pos,struct node *curr)
{
    if(pos==1)
    {
        temp=curr;
        if(curr->next==curr)
        {
            head=NULL;
        }
        else
        {
            for(last=head;last->next!=head;last=last->next);
            head=head->next;
            last->next=head;
        }
        free(temp);
        printf("\ndeleted successfully\n");
        return;
    }
    for(int j=1;j<=pos-1;j++,curr=curr->next)
    {
        /*if(curr->next->next==head&&j==pos-1)
        {
            temp=curr->next;
            curr->next=head;
            free(temp);
            printf("\ndeleted successfully\n");
            return;
        }*/
        if(j==pos-1)
        {
            temp=curr->next;
            curr->next=curr->next->next;
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
        if(i==0)
            head=new;
        else
            ptr->next=new;
        if(i==n-1)
            new->next=head;
    }
    display(head);
    printf("\nenter the position  ");
    scanf("%d",&pos);
    delete(pos,head);
    display(head);

    return 0;
}
