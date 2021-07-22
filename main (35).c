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


static int i=0;
void kth(int k,struct node *curr)
{
    struct node *temp;
    //static int i=1;
    if(curr==NULL)
        return;
    kth(k,curr->next);
    if(++i==k)
        printf("\n%d th node from last is %d\n",k,curr->val);
   
}

int main()
{
    int n,i,k;
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
    printf("\nenter k value  ");
    scanf("%d",&k);
    kth(k,head);
    //display(head);

    return 0;
}
