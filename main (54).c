/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

struct stack
{
    int val;
    struct stack *next;
}*top,*new,*temp;

void push()
{
    new=(struct stack*)malloc(sizeof(struct stack));
    printf("enter the element  ");
    scanf("%d",&(new->val));
    new->next=NULL;
    if(top==NULL)
    {
        top=new;
        printf("g");
        return;
    }
    new->next=top;
    top=new;
}

void pop()
{
    if(top==NULL)
    {
        printf("underflow");
        return;
    }
    temp=top;
    top=top->next;
    free(temp);
}

int peek()
{
    if(top==NULL)
    {
        printf("no elements found");
        return '\0';
    }
    return top->val;
}

int isempty()
{
    if(top==NULL)
        return 1;
    return 0;
}

void display()
{
    for(temp=top;temp!=NULL;temp=temp->next)
        printf("%d ",temp->val);
}

int main()
{
    int ch,chk,elm;
    top=NULL;
    do
    {
        printf("\nenter \n1 to push\n2 to pop\n3 to peek\n4 to check empty or not\n5 to display\n0 to exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
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
