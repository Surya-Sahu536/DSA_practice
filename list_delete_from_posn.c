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
    for(;curr!=0;curr=curr->next)
        printf("%d  ",curr->val);
    printf("\n");
}

void delet(int pos,struct node *curr)
{
    struct node *temp;
    if(pos==1)
    {
        head=curr->next;
        free(curr);
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
            temp=curr->next;
            curr->next=curr->next->next;
            free(temp);
            printf("deleted successfully\n");
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
    printf("enter position   ");
    scanf("%d",&pos);
    delet(pos,head);
    display(head);

    return 0;
}
