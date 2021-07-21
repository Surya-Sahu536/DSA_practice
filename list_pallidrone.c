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
}*head,*new,*ptr;
void display(struct node *curr)
{
    for(;curr!=NULL;curr=curr->next)
        printf("%d",curr->val);
}

int palln(struct node **left, struct node *rgt)
{
    if(rgt==NULL)
        return 1;
    int isp=palln(left,rgt->next);
    if(isp==0)
        return 0;
    int isp1=(rgt->val==(*left)->val);
    *left=(*left)->next;
    return isp1;
}

int main()
{
    int n,i,fg;
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
    fg=palln(&head,head);
    if(fg==0)
        printf("\nnot pallidrone");
    else
        printf("\npallidrone");

    return 0;
}
