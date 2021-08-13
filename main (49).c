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
}*head,*ptr,*new,*temp,*last;

void display(struct node *curr)
{
    for(;curr->next!=head;curr=curr->next)
        printf("%d ",curr->val);
    printf("%d ",curr->val);
}

void swap(int pos,struct node *curr)
{
    if(pos==1)
    {
        temp=head->next;
        for(last=curr;last->next!=head;last=last->next);
        head->next=head->next->next;
        last->next=temp;
        temp->next=head;
        head=temp;
        return;
        
    }
    for(int j=1;j<pos;j++,curr=curr->next)
    {
        if(curr->next->next==head&&j==pos-1)
        {
            temp=curr->next;
            curr->next=curr->next->next;
            temp->next=temp->next->next;
            curr->next->next=temp;
            head=temp;
            printf("\nswapped successfully\n");
            return;
        }
        if(j==pos-1)
        {
            temp=curr->next;
            curr->next=curr->next->next;
            temp->next=temp->next->next;
            curr->next->next=temp;
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
        if(i==0)
            head=new;
        else
            ptr->next=new;
        if(i==n-1)
            new->next=head;
    }
    display(head);
    printf("\nenter the position to be swapped  ");
    scanf("%d",&pos);
    swap(pos,head);
    display(head);

    return 0;
}
