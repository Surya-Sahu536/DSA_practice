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
}*head,*ptr,*new,*ptr2,*temp_head;

void display(struct node *curr)
{
    for(;curr->next!=head;curr=curr->next)
        printf("%d ",curr->val);
    printf("%d \n",curr->val);
}

void rev(struct node *curr)
{
    temp_head=head;
    for(ptr=curr->next->next,ptr2=curr->next;ptr!=head;curr=curr->next,ptr=ptr->next)
    {
       
        if(ptr->next==head)
        {   
            head=ptr;
            temp_head->next=ptr;
            ptr2->next=curr;
            ptr->next=ptr2;
            printf("%d %d",ptr2->next->val,ptr->next->next->val);
            return;
        }
        //ptr->next=curr->next;
        ptr2->next=curr;
        ptr2=ptr;
        
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
    rev(head);
    display(head);

    return 0;
}