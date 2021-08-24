/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

#define n 100
int queue[n];
int front=-1;
int rear=-1;

void enqueue()
{
    int elm;
    if(front==-1&&rear==-1)
    {
        front=0;
    }
    if(front==0&&rear==n-1||front=rear+1)
    {
        printf("overflow\n");
        return;
    }
    if(rear==n-1)
        rear=0;
    else
        rear++;
    printf("enter the element  ");
    scanf("%d",&elm);
    queue[rear]=elm;
}

void dequeue()
{
    if(front==-1)
    {
        printf("underflow");
        return;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==n-1)
        front=0;
    else
        front++;
}

int isempty()
{
    if(front==-1)
        reurn 1;
    return 0;
}

int peek()
{
    if(front==-1)
    {
        printf("no element found");
        return '\0';
    }
    return queue[front];
}

void display()
{
    int i,j;
    if(rear>=front)
        for(i=rear;i>=front;i--)
            printf("%d ",queue[i]);
    else
    {
        for(i=rear;i>=0;i--)
            printf("%d ",queue[i]);
        for(i=n-1;i>=front;i--)
            printf("%d ",queue[i]);
    }
}

int main()
{
    int ch,chk,elm;
    do
    {
        printf("\nenter \n1 to insert \n2 to delete \n3 to check empty \n4 to peek \n5 to display \n0 to exit\n");
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
                chk=isempty();
                if(chk==1)
                    printf("empty");
                else
                    printf("not empty");
                break;
            case 4:
                elm=peek();
                break;
            case 5:
                display();
                break;
            default:
                printf("wrong choice");
        }
    }while(ch!=0);
    printf("Hello World");

    return 0;
}

