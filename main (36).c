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

void dplct(struct node *curr)
{
    struct node *temp,*itr;
    for(;(curr->next!=NULL)&&(curr!=NULL);curr=curr->next)
    {
        for(itr=curr;(itr->next!=NULL);)
        {
            if(curr->val==itr->next->val)
            {
                temp=itr->next;
                itr->next=itr->next->next;
                free(temp);
            }
            else
                itr=itr->next;
        }
    }
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
    dplct(head);
    printf("\nduplicate elements deleted successfully\n");
    display(head);

    return 0;
}
