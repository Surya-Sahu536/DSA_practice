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
}*head,*ptr,*new;

void display(struct node *curr)
{
    for(;curr!=NULL;curr=curr->next)
        printf("%d ",curr->val);
}

void reverse(struct node *curr)
{
    struct node *temp;
    if(curr==NULL||curr->next==NULL)
    {
        head=curr;
        return;
    }
    reverse(curr->next);
    curr->next->next=curr;
    curr->next=NULL;
   
}

int main()
{
    int n,i;
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
    reverse(head);
    printf("\nreversed successfully\n");
    display(head);

    return 0;
}
