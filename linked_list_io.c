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
};

int main()
{
    int n,i;
    struct node *ptr,*head,*temp;
    printf("Enter the no of nodes  ");
    scanf("%d",&n);
    head=(struct node*)malloc(n*sizeof(struct node));
    printf("enter the first node value  ");
    scanf("%d",&(head->val));
    head->next=NULL;
    temp=head;
    for(i=1;i<n;i++)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter node no %d :  ",i+1);
        scanf("%d",&(ptr->val));
        ptr->next=NULL;
        temp->next=ptr;
        temp=temp->next;
    }
    temp=head;
    for(i=0;i<n;i++)
    {
        printf("%d  ",temp->val);
        temp=temp->next;
    }

    return 0;
}
