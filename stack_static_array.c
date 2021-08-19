/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

int arr[30];
int top=-1;

void push()
{
    int elm;
    printf("enter element to be pushed  ");
    scanf("%d",&elm);
    top++;
    arr[top]=elm;
}

void pop()
{
    int elm;
    if(top==-1)
    {
        printf("underflow\n");
        return;
    }
    top--;
}

int peek()
{
    int elm;
    if(top==-1)
    {
        printf("no element found");
        return 0;
    }
    return arr[top];
}

int isempty()
{
    if(top==-1)
        return 1;
    return 0;
}

void display()
{
    for(int i=0;i<=top;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int ch,elm,c;
    do
    {
        printf("\nenter \n1 to push into stack\n2 to pop\n3 to peek\n4 to check the stack is empty or not\n5 to display\n6 to exit\n");
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
                c=isempty();
                if(c==1)
                    printf("empty\n");
                else
                    printf("not empty\n");
                break;
            case 5:
                display();
                break;
            default:
                printf("operation not found\n");
                break;
        }
    }while(ch!=6);


    return 0;
}
