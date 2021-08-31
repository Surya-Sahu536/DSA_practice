/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct tree
{
    struct tree *left;
    int val;
    struct tree *right;
}*root,*ptr,*new,*curr;

void insert()
{
    int ch;
    new=(struct tree*)malloc(sizeof(struct tree));
    printf("enter element  ");
    scanf("%d",&(new->val));
    new->left=NULL;
    new->right=NULL;
    if(root==NULL)
    {
        root=new;
        return;
    }
    curr=root;
    while(1)
    {
        printf("enter 0 to insert to left or 1 to right of   %d  :  ",curr->val);
        scanf("%d",&ch);
        if(ch==0)
        {
            if(curr->left==NULL)
            {
                curr->left=new;
                return;
            }
            curr=curr->left;
        }
        else
        {
            if(curr->right==NULL)
            {
                curr->right=new;
                return;
            }
            curr=curr->right;
        }
    }
}

void inorder(struct tree *curr)
{
    if(curr!=NULL)
    {
        inorder(curr->left);
        printf("%d ",curr->val);
        inorder(curr->right);
    }
}

void preorder(struct tree *curr)
{
    if(curr!=NULL)
    {
        printf("%d ",curr->val);
        preorder(curr->left);
        preorder(curr->right);
    }
}

void postorder(struct tree *curr)
{
    if(curr!=NULL)
    {
        postorder(curr->left);
        postorder(curr->right);
        printf("%d ",curr->val);
    }
}

int main()
{
    int ch=1;
    while(ch!=0)
    {
        printf("\nenter \n1 to insert \n2 to inorder \n3 to preorder \n4 to postorder \n0 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 0:
                break;
            default:
                printf("wrong choice");
            
        }
    }

    return 0;
}
