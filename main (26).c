/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
}*ptr,*newnode,*head;

void display(struct node *curr)
{
    for(;curr!=NULL;curr=curr->next)
        printf("%d ",curr->val);
}

void check_sorted(struct node *curr)
{
    int flag=1;
    for(;curr->next!=0;curr=curr->next)
        if(curr->next->val<curr->val)
        {
            flag=0;
            printf("\nlist not in sorted manner\n");
            break;
        }
    if(flag==1)
        printf("\nlist in sorted manner\n");
}

int main()
{
    int n,i;
    printf("enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,ptr=newnode)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter node no %d  ",i+1);
        scanf("%d",&(newnode->val));
        newnode->next=NULL;
        if(i==0)
            head=newnode;
        else
            ptr->next=newnode;
    }
    
    display(head);
    check_sorted(head);

    return 0;
}
