//C program on singly linked list
#include<stdio.h>
#include<malloc.h>
struct node * find_end(int *);
void add_node();
void remove_node();
void display_nodes();
void reverse_list();
void search_list(int);
void display_list();
void deallocate_mem();
struct node * new_node();

struct node
{

    int data;
    struct node *NEXT;

}*START=NULL;

int main()
{
    int choice;
    while(1)
     {
         printf("\nEnter a choice\n1>Add an node to list\n2>Remove a node\n3>Display data\n4>Reverse List\n5>Search data in list\n");
         printf("enter any other value to exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
            case 1: add_node();
                    break;
            case 2: remove_node();
                    break;
            case 3: display_list();
                    break;
            case 4: reverse_list();
                    break;
            case 5: if(!START)
                    printf("\nList is empty\n");
                    else
                    {
                        printf("\nEnter the data to search in list_> ");
                        scanf("%d",&choice);
                        search_list(choice);
                    }
                    break;
            default:deallocate_mem();
                    return 0;
        }
     }
}
struct node * find_end(int *b)
{
	static struct node *TEMP;
    for(TEMP=START , *b=0; TEMP->NEXT!=NULL ; TEMP=TEMP->NEXT , *b+=1);

    return TEMP;
}
struct node * new_node()
{
    int data;
    static struct node *NEW_NODE;
    printf("\nEnter the data_> ");
    scanf("%d",&data);
    NEW_NODE=(struct node *)malloc(sizeof(struct node));
    NEW_NODE->data=data;
    return NEW_NODE;
}
void add_node()
{
    struct node *TEMP1,*TEMP2,*NEW_NODE;
    int count,data,end,i,choice;

        printf("\nEnter choice\n1>Add at beginning\n2>Add at end\n3>Add at intermediate position\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: NEW_NODE=new_node();
                    if(!START)
                    {
						START=NEW_NODE;
						NEW_NODE->NEXT=NULL;
					}
                    else
					{
						NEW_NODE->NEXT=START;
						START=NEW_NODE;
					}
					printf("\nAddition successful\n");
                    break;
            case 2: NEW_NODE=new_node();
                    if(!START)
                        START=NEW_NODE;
                    else
                    {
                        TEMP1=find_end(&end);
                        TEMP1->NEXT=NEW_NODE;
                    }
                    NEW_NODE->NEXT=NULL;
                    printf("\nAddition successful\n");
                    break;
            case 3: printf("\nEnter index of new node\n");
                    scanf("%d",&count);
                    find_end(&end);
                    if(count<end && count>0)
                    {
                        NEW_NODE=new_node();
                        TEMP1=START;
                        for(i=0;i<count;i++)
                        {
                            TEMP2=TEMP1;
                            TEMP1=TEMP1->NEXT;
                        }
                        TEMP2->NEXT=NEW_NODE;
                        NEW_NODE->NEXT=TEMP1;
                        printf("\nAddition successful\n");
                    }
                    else
                        printf("\nOperation not possible\n");
                    break;
          default: printf("\nInvalid input\n");
        }
}
void remove_node()
{
    struct node *TEMP1,*TEMP2;
    int index,end,i,choice;
    TEMP1=START;
    if(!TEMP1)
        printf("\nList is empty\n");
    else
    {
        printf("Data before deletion :");
        display_nodes();
        printf("\nEnter choice\n1>From beginning\n2>From end\n3>From intermediate position\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: START=START->NEXT;
                    free(TEMP1);
                    printf("\nDeletion successful\n");
                    printf("Data after deletion :");
                    display_nodes();
                    break;
            case 2: if(TEMP1->NEXT==NULL)
                        {
                            free(TEMP1);
                            START=NULL;
                        }
                    else
                    {
                        while(TEMP1->NEXT!=NULL)
                        {
                            TEMP2=TEMP1;
                            TEMP1=TEMP1->NEXT;
                        }
                        free(TEMP1);
                        TEMP2->NEXT=NULL;
                    }
                    printf("\nDeletion successful\n");
                    printf("Data after deletion :");
                    display_nodes();
                    break;
            case 3: printf("\nEnter index of node to delete_> ");
                    scanf("%d",&index);
                    find_end(&end);
                    if(index>0 && index<end)
                    {
                        for(i=0 ; i<index ; i++)
                        {
                            TEMP2=TEMP1;
                            TEMP1=TEMP1->NEXT;
                        }
                        TEMP2->NEXT=TEMP1->NEXT;
                        free(TEMP1);
                        printf("\nDeletion successful\n");
                        printf("Data after deletion :");
                        display_nodes();
                    }
                    else
                        printf("\nOperation not possible\n");
                    break;
          default: printf("\nInvalid input\n");
        }
    }
}
void display_nodes()
{
    struct node *TEMP;
    int i;
    for(i=0 , TEMP=START ; TEMP!=NULL ; i++ , TEMP=TEMP->NEXT)
        {
            printf("\nNode : %d\t\tData : %d",i,TEMP->data);
        }

	printf("\n");
}
void reverse_list()
{
    struct node *P1,*P2,*LEAD;
    LEAD=START;
    P1=NULL;
    if(START==NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nList before reversing :\n");
        display_nodes();
        while(LEAD!=NULL)
        {
            P2=P1;
            P1=LEAD;
            LEAD=LEAD->NEXT;
            P1->NEXT=P2;
        }
        START=P1;
        printf("\nList after reversing :\n");
        display_nodes();
    }
}
void search_list(int data)
{
    struct node *TEMP;
    int i,f=0;
    for(i=0 , TEMP=START; TEMP!=NULL ; i++,TEMP=TEMP->NEXT)
        {
            if(data==TEMP->data)
                {
                    f=1;
                    break;
                }
        }
    if(f)
        printf("\nData found at position %d\n",i);
    else
        printf("\nData not found\n");
}
void display_list()
{
    int choice,i;
    struct node *TEMP;
    TEMP=START;
    if(!TEMP)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter choice\n1>Display first node\n2>Display last node\n3>Display node at selected index\n4>Display all nodes\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nnode : 0\t\tdata : %d\n",START->data);
                    break;
            case 2: TEMP=find_end(&choice);
                    printf("\nnode : %d\t\tdata : %d\n",choice-1,TEMP->data);
                    break;
            case 3: printf("\nEnter index of node to display_> ");
                    scanf("%d",&choice);
                    find_end(&i);
                    if(choice>=0 && choice<=i)
                    {
                        for(i=0;i<choice;i++)
                            TEMP=TEMP->NEXT;
                        printf("\nnode : %d\t\tdata : %d\n",choice,TEMP->data);
                    }
                    else
                        printf("\nIndex does not exist\n");
                    break;
            case 4: display_nodes();
                    break;
           default: printf("\nInvalid input\n");
        }
    }
}
void deallocate_mem()
{
    struct node *TEMP1,*TEMP2;
    TEMP1=START;
    if(TEMP1!=NULL)
    {
        while(TEMP1!=NULL)
        {
            TEMP2=TEMP1;
            TEMP1=TEMP1->NEXT;
            free(TEMP2);
        }
    }
}
