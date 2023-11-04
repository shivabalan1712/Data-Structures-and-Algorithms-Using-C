#include <stdio.h>
#include<stdlib.h>

int i,pos,ele,ch,r,n,max=10;
int ar[10];

void create()
{
	printf("\nEnter number of elements to be added : ");
	scanf("%d",&n);
	if(n>max)
	{
		printf("\nThe maximum size is 10 !");	
	}
	else {	
	for(i=0;i<n;i++)
	{
		printf("\nEnter element :");  
		scanf("%d",&ar[i]);
	}
	}
	disp();
}
void insert()
{
	printf("\nEnter the position to insert: ");
	scanf("%d",&pos);
	if(pos>=n)
	{
		printf("\n invalid location");
	}
	else{
	for (i=max-1;i>=pos-1;i--)
	{
		ar[i+1]=ar[i];
	}
	printf("\nEnter the element to insert:");
	scanf("%d",&ele);
	ar[pos-1]=ele;
	n++;}
	disp();
}
void disp()
{
	printf("\nElements are :");
	for (i=0;i<=n-1;i++)
	{
		printf(" %d ",ar[i]);
	}
}
void del()
{
	printf("\nEnter the position to be deleted: ");
	scanf("%d",&pos);
	if(pos>=n)
	{
		printf("\nInvalid location !");			
	}
	else {
	for (i=pos+1;i<n;i++)
	{
		ar[i-1]=ar[i];	
	}n--;
	}
	disp();
}
void makeempty()
{
	for(i=0;i<max;i++)
	{
		ar[i]=NULL;
		n--;
	}	
	printf("\nAll Elements are Removed");
}
void isempty()
{
	if(n==0){
		printf("\nThe array is Empty");
	}
	else { printf("\nThe array is not empty");
	}
}
void isfull()
{
	if(n==max)
	{printf("\nThe array is full");
	}
	else{printf("\nThe array is not full");
	}
}
void findelement()
{
	printf("\nEnter the Element to find:");
	scanf("%d",&ele);
	for(i=0;i<n;i++)
	{
		if(ar[i]==ele)
		{
			printf("\nValue is in the %d position",i);
		}
	}
}
void replace()
{
	printf("\nEnter the position to replace :");
	scanf("%d",&r);
	printf("\nEnter the element to replace :");
	scanf("%d",&ele);
	ar[r]=ele;
	disp();
}

int main()
{
	do{
	
	printf("\n\nList operations \n\n 1.Create \n 2.Insert\n 3.Delete\n 4.Make Empty\n 5.Is full\n 6.Is empty\n 7.Find an element\n 8.Replace an element\n 9.Display\n\n");
	printf("\n\n Enter your option : ");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			create();
			break;
		case 2:
			insert();
			break;
		case 3:
			del();
			break;
		case 4:
			makeempty();
			break;
		case 5:
			isfull();
			break;
		case 6:
			isempty();
			break;
		case 7:
			findelement();
			break;
		case 8:
			replace();
			break;
		case 9:
			disp();
		case 10:
			exit(1);
		default:
			printf("Enter only correct value !");
			break;
	}
}while(ch!=10);
	return 0;
}