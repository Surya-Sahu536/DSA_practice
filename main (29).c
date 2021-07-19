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

void swap_2_elements(int pos,int pos2,struct node *curr)
{
    struct node *curr2;
    int temp,j;
    if(curr->next==NULL)
        printf("\nonly 1 element is present");
    for(int i=0;i<pos&&curr!=NULL;i++,curr=curr->next)
    {
        //if(i!=pos-1)
         //   curr=curr->next;
        if(i==pos-1)
        {
            for(j=i+1,curr2=curr->next;j<pos2&&curr2!=NULL;j++,curr2=curr2->next)
            {
                if(j==pos2-1)
                {
                     printf("\nswapped successfully %d %d\n",curr->val,curr2->val);
                    temp=curr->val;
                    curr->val=curr2->val;
                    curr2->val=temp;
                    printf("\nswapped successfully %d %d\n",curr->val,curr2->val);
                }
            }
        }
    }
}

int main()
{
    int n,i,pos1,pos2;
    printf("enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,ptr=newnode)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("memory not allocated");
            exit(0);
        }
        printf("enter node no %d  ",i+1);
        scanf("%d",&(newnode->val));
        newnode->next=NULL;
        if(i==0)
            head=newnode;
        else
            ptr->next=newnode;
    }
    
    display(head);
    printf("\nenter positions to be swapped  ");
    scanf("%d %d",&pos1,&pos2);
    swap_2_elements(pos1,pos2,head);
    display(head);

    return 0;
}
