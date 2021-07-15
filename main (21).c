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
}*ptr,*head,*temp;

void search(int elm,struct node *curr)
{
    for(int pos=1;curr!=NULL;curr=curr->next,pos++)
        if(curr->val==elm)
            printf("\'%d\' element found at position pos %d  \n",elm,pos);
}
int main()
{
    int n,i,elm;
    printf("Enter the no of nodes  ");
    scanf("%d",&n);
    for(i=0;i<n;i++,temp=ptr)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter node no %d :  ",i+1);
        scanf("%d",&(ptr->val));
        ptr->next=NULL;
        if(i==0)
            head=ptr;
        else
            temp->next=ptr;
    }
    printf("Enter element to be searched  ");
    scanf("%d",&elm);
    search(elm,head);

    return 0;
}
