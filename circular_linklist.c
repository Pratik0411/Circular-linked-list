#include<stdlib.h>
#include<stdio.h>
struct Node* head = NULL;
struct Node* tail;
struct Node
{
    int data;
    struct Node *next;
};

void insertStart(struct Node**, struct Node**, int);
void insertLast(struct Node**, struct Node**, int);
void insord(struct Node**, int);
void delete(struct Node**, struct Node**, int);
void display(struct Node*, struct Node*);

int main()
{
	int pos,val,n;
	int op=0;
	while(op<6)
	{
		printf("\nEnter the choice for the operation\n1. Insertion at First\n2. Insertion at End\n3. Insertion at Ordered\n4. Delete a node\n5. Display\n6. Quite\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter value\n");
			scanf("%d",&val);
			insertStart(&head,&tail,val);
			break;

			case 2:
			printf("Enter value\n");
			scanf("%d",&val);
			insertLast(&head,&tail,val);
			break;

			case 3:
			printf("Enter value\n");
			scanf("%d",&val);
			insord(&head,val);
			break;

			case 4:
			printf("Enter node to be deleted\n");
			scanf("%d",&n); 
			delete(&head,&tail,n);
			break;

			case 5:
			display(head,tail);
			break;
		}
	}
}

void insertStart(struct Node** h,struct Node** t, int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp1=*h;
	struct Node* temp2=*t;
    	newnode->data = data;
	if(temp1==NULL)
	{
		newnode->next=newnode;
		*h=newnode;
		*t=newnode;
	}
	else
	{
		printf("in else");
		newnode->next=temp1;
		temp2->next=newnode;
		*h=newnode;
	}
}

void insertLast(struct Node** head,struct Node** tail, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp1=*head;
	struct Node* temp2=*tail;
	newNode->data = data;
	if(temp1==NULL)
	{
		newNode->next=newNode;
		*head = newNode;
		*tail=newNode;  
	}
	else
	{
		newNode->next=temp1;
		temp2->next=newNode;
		*tail=newNode;
	}
}

void insord(struct Node** head, int data)
{
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	if(*head==NULL)
	{
		*head=newnode;
	}
	else
	{
		struct Node* temp = *head; 
		while(temp->data<data-1 && temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

void delete(struct Node** head,struct Node** tail,int n)
{
	struct Node* temp=*head;
	struct Node* pred;
	while(--n)
	{
		pred=temp;
		temp=temp->next;
	}
	if(pred==NULL)
	{
		printf("empty");
	}
	else
	{
		struct Node* h=*head;
		struct Node* t=*tail;
		if(pred==*head)
		{
			*head=h->next;
			t->next=*head;
		}
		else if(temp==*tail)
		{
			*tail=pred;
		}
		else
		{
			pred->next=temp->next;
		}
	}
	pred->next=temp->next;
}

void display(struct Node* head,struct Node* tail)
{
	struct Node* h=head;
	struct Node* t=tail;
	do
	{
		printf("->%d",h->data);
		h=h->next;
	}
	while(h!=t->next);
	printf("\n");
}
