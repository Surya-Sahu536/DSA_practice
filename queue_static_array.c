/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

#define n 100
int que[n];
int front=0;
int rear=0;

void enqueue()
{
    int elm;
    printf("\nenter element  ");
    scanf("%d",&elm);
    if(rear==n)
    {
        printf("overflow");
        return;
    }
    if(front==0&&rear==0)
        front=1;
    rear++;
    que[rear]=elm;
}

void dequeue()
{
    if(front==0)
    {
        printf("underflow");
        return;
    }
    if(front==rear)
    {    
        front=1;
        rear=1;
    }
    else
        front++;
}

int peek()
{
    if(front==0)
        return '\0';
    else 
        return que[front];
}

int isempty()
{
    if(front==0&&rear==0)
        return 1;
    else
        return 1;
}

void display()
{
    for(int i=rear;i>=front;i--)
        printf("%d",que[i]);
}



int main()
{
    int ch,chk,elm;
    do
    {
    printf("\nenter \n1 to insert into queue\n2 to delete from queue\n3 to peek from queue\n4 to check queue is empty\n0 to exit\n");
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
            break;
        case 5:
            display();
            break;
        default:
            printf("wrong choice");
            
    }
    }while(ch!=0);

    return 0;
}
