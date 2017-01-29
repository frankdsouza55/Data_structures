//C program on doubly linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next, *prev;
}*start=NULL;

struct node * make_node(int a)
{
    struct node *newnode1;
    newnode1=(struct node*)malloc(sizeof(struct node));
    newnode1->data=a;
    newnode1->next=newnode1->prev=NULL;
    return newnode1;
}
int count()
{
    struct node *temp=start;
    int n=0;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        n++;
    }
    return n;
}
void insert(int a)
{
    int ch,n,c=0,pos;
    struct node *newnode,*temp1,*temp2;
    newnode=make_node(a);
    printf("\n\t1:Insert at front\n\t2:Insert at end\n\t3:Insert at specified position\n\tChoice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: if(start==NULL)
                    start=newnode;
                else
                {
                    newnode->next=start;
                    start->prev=newnode;
                    start=newnode;
                }
                break;
        case 2: if(start==NULL)
                    start=newnode;
                else if(start->next==NULL)
                {
                    start->next=newnode;
                    newnode->prev=start;
                }
                else
                {
                    temp1=start;
                    while(temp1->next!=NULL)
                        temp1=temp1->next;
                    temp1->next=newnode;
                    newnode->prev=temp1;
                }
                break;
        case 3: n=count();
                printf("\n\tEnter the position : ");
                scanf("%d",&pos);
                if(pos>0&&pos<n)
                {
                    temp1=temp2=start;
                    while(c<pos)
                    {
                        temp1=temp2;
                        temp2=temp2->next;
                        c++;
                    }
                    temp1->next=newnode;
                    newnode->prev=temp1;
                    newnode->next=temp2;
                    temp2->prev=newnode;
                }
                else
                    printf("\n\tInvalid position");
                break;
    }
}
void delete_node()
{
    int ch,n,c=0,pos;
    struct node *temp1=start,*temp2;
    printf("\n\t1:Delete from front\n\t2:Delete from end\n\t3:Delete at specified position\n\tChoice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: if(start==NULL)
                    printf("\n\tDeletion not possible");
                else if(start->next==NULL)
                {
                    free(temp1);
                    start=NULL;
                }
                else
                {
                    start=start->next;
                    start->prev=NULL;
                    free(temp1);
                }
                break;
        case 2: if(start==NULL)
                    printf("\n\tDeletion not possible");
                else if(start->next==NULL)
                {
                    free(temp1);
                    start=NULL;
                }
                else
                {
                    while(temp1->next!=NULL)
                        temp1=temp1->next;
                    temp1->prev->next=NULL;
                    free(temp1);
                }
                break;
        case 3: n=count();
                printf("\n\tEnter the position : ");
                scanf("%d",&pos);
                if(pos>0&&pos<n)
                {
                    temp1=temp2=start;
                    while(c<pos)
                    {
                        temp1=temp2;
                        temp2=temp2->next;
                        c++;
                    }
                    temp1->next=temp2->next;
                    temp2->next->prev=temp1;
                    free(temp2);
                }
                else
                    printf("\n\tInvalid position");
                break;
    }
}
void reverse()
{
    struct node *q=start,*r=NULL;
    if(start==NULL)
        printf("\nList is empty");
    else
    {
        while(q!=NULL)
        {
            r=q->prev;
            q->prev=q->next;
            q->next=r;
            q=q->prev;
        }
        start=r->prev;
        printf("\nLinked list reversed\n");
    }
}
void display()
{
    struct node *temp=start;
    if(start== NULL)
        printf("\nLinked list is empty");
    else
    {
        printf("\nLinked list is \n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int c,a;
    do
    {
        printf("\n\n1:Insert\n2:Delete\n3:Display\n4:Reverse\n0:Exit\nChoice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1: printf("\nEnter the data : ");
                scanf("%d",&a);
                insert(a);
                break;
        case 2: delete_node();
                break;
        case 3: display();
                break;
        case 4: reverse();
                break;
        case 0: return 0;
        default: printf("\nInvalid choice");
        }
    }while(c);
}
