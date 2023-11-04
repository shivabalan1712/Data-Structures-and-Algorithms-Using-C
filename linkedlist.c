#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*temp,*newnode;
int n,i,loc,flag;

void disp();

void insertatbeg()
{
	int item;
	newnode=(struct node *)malloc(sizeof(struct node *));
	printf("\nEnter number of Elements to be inserted:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	printf("\nEnter the Data:");
	scanf("%d",&item);
	newnode->data=item;
	newnode->next=head;
	head=newnode;
	}
	disp();
}

void insertatend()
{
	newnode=(struct node *)malloc(sizeof(struct node *));
	printf("\nEnter the number of elements to be added at the end:");
	scanf("%d",&n);
	for (i=0;i<=n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			newnode->next=NULL;
			head=newnode;
		}
		else 
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=NULL;
		}
	}
	disp();
}

void insert()
{
	newnode=(struct node *)malloc(sizeof(struct node *));
	printf("\nEnter the Data:");
	scanf("%d",&newnode->data);
	printf("Enter the location to insert:");
	scanf("%d",&loc);
	temp=head;
	for(i=0;1<loc-1;i++)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("\nCan't Insert");
		}
	}
	newnode->next=temp->next;
	temp->next=newnode;
	disp();
}

void delatbeg()
{
	if(head==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		newnode=head->next;
		head=newnode;
		disp();
	}
}
void delatend()
{
	newnode=head;
	if(head==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		if(head->next==NULL)
		{
			head=NULL;
			free(head);
			disp();
		}
		else
		{
			while(newnode->next!=NULL)
			{
				temp=newnode;
				newnode=newnode->next;
			}
			temp->next=NULL;
			free(newnode);
			disp();
		}
	}
}

void del()
{
	if(head==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=head;
		printf("\nEnter the position to be deleted:");
		scanf("%d",&loc);
		for (i=0;i<loc-1;i++)
		{
			temp=temp->next;
		}
		newnode=temp->next;
		temp->next=newnode->next;
		free(newnode);
		disp();
	}
}
void search()
{
	printf("\nEnter the value to be Searched");
	scanf("%d",&n);
	newnode=head;
	if(newnode==NULL)
	{
		printf("\nThe list id empty");
	}
	else
	{
		while(newnode->next!=NULL)
		{
			if(newnode->data==n)
			{
				printf("\nData found at the index:%d",i);
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
			i++;
			newnode=newnode->next;
		}
		if(flag==1)
		{
			printf("\nData not found");
		}
	}
}


void disp()
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		printf("\nLinked list elements are:");
		while(ptr!=NULL)
		{
			
			printf(" %d ",ptr->data);
			ptr=ptr->next;
		}
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n\nList operations \n\n 1.Insert at begining \n 2.Insert at last\n 3.Insert at position\n 4.Delete at begining\n 5.Delete at last\n 6.Delete at pos\n 7.Search\n 8.Display\n 9.Exit\n");
		printf("\n\n Enter your option : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insertatbeg();
				break;
			case 2:
				insertatend();
				break;
			case 3:
				insert();
				break;
			case 4:
				delatbeg();
				break;
			case 5:
				delatend();
				break;
			case 6:
				del();
				break;
			case 7:
				search();
				break;
				disp();
			case 8:
				disp();
				break;
			case 9:
				exit(1);
				break;
			default:
				printf("Enter only correct value !");
				break;
		}
	}while(ch!=9);
}