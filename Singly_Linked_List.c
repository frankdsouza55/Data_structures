//C program on singly linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;
struct node * make_node(int a)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=a;
    new_node->next=NULL;
    return new_node;
}
void insert_at_begininng(int a)
{
    struct node *newnode;
    newnode=make_node(a);
    if(start==NULL)
        start=newnode;
    else
    {
        newnode->next=start;
        start=newnode;
    }
}
void insert_at_end(int a)
{
    struct node *temp=start,*newnode;
    newnode=make_node(a);
    if(start==NULL)
        start=newnode;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
int count_nodes()
{
    int c=0;
    struct node *temp=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
void insert_at_pos(int a, int p)
{
    int n,count=0;
    struct node *temp1,*temp2,*newnode;
    newnode=make_node(a);
    n=count_nodes();
    if(p==0)
        insert_at_begininng(a);
    else if(p==n)
        insert_at_end(a);
    else if(p>0&&p<n)
    {
        temp1=temp2=start;
        while(count<p)
        {
            temp1=temp2;
            temp2=temp2->next;
            count++;
        }
        temp1->next=newnode;
        newnode->next=temp2;
    }
    else
        printf("\nInvalid position");
}
void delete_at_front()
{
    if(start==NULL)
        printf("\nList is empty, deletion not possible");
    else
    {
        struct node *temp=start;
        start=start->next;
        free(temp);
    }
}
void delete_at_end()
{
    struct node *temp1=start,*temp2=start;
    if(start==NULL)
        printf("\nList is empty, deletion not possible");
    else if(start->next==NULL)
        {
            start=NULL;
            free(temp1);
        }
    else
    {
        while(temp2->next!=NULL)
        {
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=NULL;
        free(temp2);
    }
}
void delete_at_pos(int p)
{
    int n,count=0;
    struct node *temp1,*temp2;
    n=count_nodes();
    if(start==NULL)
        printf("\nList is empty, deletion not possible");
    if(p==0)
        delete_at_front();
    else if(p==n-1)
        delete_at_end();
    else if(p>0&&p<(n-1))
    {
        temp1=temp2=start;
        while(count<p)
        {
            temp1=temp2;
            temp2=temp2->next;
            count++;
        }
        temp1->next=temp2->next;
        free(temp2);
    }
    else
        printf("\nInvalid position");
}
void display()
{
    struct node *temp=start;
    if(start==NULL)
        printf("\nList is empty");
    else
    {
        printf("\nstart-->");
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}
void reverse()
{
    struct node *q,*r,*s;
    q=start;
    r=NULL;
    while(q!=NULL)
    {
        s=r;
        r=q;
        q=q->next;
        r->next=s;
    }
    start=r;
    printf("\nLinked list reversed\n");
}
void search(int a)
{
    int pos=0;
    struct node *temp=start;
    while(temp->data!=a)
    {
        if(temp->data==a)
            break;
        temp=temp->next;
        pos++;
        if(temp==NULL)
            break;
    }
    if(temp==NULL)
        printf("\nElement not found");
    else
        printf("\nFound at position %d",pos);
}
void delete_specific(int a)
{
    int pos=0;
    struct node *temp=start;
    if(start==NULL)
        printf("\nList is empty, deletion not possible");
    else
    {
        while(temp->data!=a)
        {
            if(temp->data==a)
                break;
            temp=temp->next;
            pos++;
            if(temp==NULL)
                break;
        }
        if(temp==NULL)
            printf("\nElement not found");
        else
        delete_at_pos(pos);
    }
}
int main()
{
    int ch,a,p;
    do
    {
        printf("\n\n1:Insert at front\n2:Insert at end\n3:Insert at position");
        printf("\n4:Delete at front\n5:Delete at end\n6:Delete at position\n7:Delete specific element");
        printf("\n8:Display\n9:Search\n10:Reverse\n0:Exit");
        printf("\nChoice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the data : ");
                    scanf("%d",&a);
                    insert_at_begininng(a);
                    break;
            case 2: printf("\nEnter the data : ");
                    scanf("%d",&a);
                    insert_at_end(a);
                    break;
            case 3: printf("\nEnter the data and position : ");
                    scanf("%d %d",&a,&p);
                    insert_at_pos(a,p);
                    break;
            case 4: delete_at_front();
                    break;
            case 5: delete_at_end();
                    break;
            case 6: printf("\nEnter the position : ");
                    scanf("%d",&p);
                    delete_at_pos(p);
                    break;
            case 7: printf("\nEnter element to be deleted : ");
                    scanf("%d",&a);
                    delete_specific(a);
                    break;
            case 8: display();
                    break;
            case 9: printf("\nEnter element to be searched : ");
                    scanf("%d",&a);
                    search(a);
                    break;
            case 10:reverse();
                    break;
            case 0: return 0;
        }
    }while(ch);
}
