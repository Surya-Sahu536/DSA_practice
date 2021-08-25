/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

struct queue
{
    int val;
    int prior;
    struct queue *next;
}*new,*front,*rear,*temp;

void enqueue()
{
    new=(struct queue*)malloc(sizeof(struct queue));
    printf("Enter priority and the element  ");
    scanf("%d %d",&(new->prior),&(new->val));
    new->next=NULL;
    if(front==NULL)
    {
        front=new;
        rear=new;
        return;
    }
    if((front->prior)<(new->prior))
        {
            new->next=front;
            front=new;
            return;
        }
    for(temp=front;temp!=NULL;temp=temp->next)
    {
        
        if((temp->next->prior)<(new->prior))
        {
            new->next=temp->next;
            temp->next=new;
            printf("enqued successfully");
            return;
        }
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("underflow");
        return;
    }
    temp=front;
    front=front->next;
    free(temp);
}

int isempty()
{
    if(front==NULL)
        return 1;
    return 0;
}

int peek()
{
    if(front==NULL)
    {
        printf("no elements found");
        return '\0';
    }
    return front->val;
}

void display()
{
    for(temp=front;temp!=NULL;temp=temp->next)
        printf("%d\(%d\) ",temp->val,temp->prior);
}

int main()
{
    int n;
    int chk,ch,elm;
    front=NULL;
    rear=NULL;
    do
    {
        printf("\nenter \n1 to insrt \n2 to delete \n3 to peek \n4 to check empty or not \n5 to display \n0 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                elm=peek();
                break;
            case 4:
                chk=isempty();
                if(chk==1)
                    printf("empty");
                else
                    printf("not empty");
                break;
            case 5:
                display();
                break;
            case 0:
                break;
            default:
                printf("wrong choice");
        }
    }while(ch!=0);

    return 0;
}
