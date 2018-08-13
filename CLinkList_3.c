#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
	int data;
	struct  node* next;	
}CLinkList;

CLinkList *head,*rear;

CLinkList *Initlist()   
{
	    head=(CLinkList*)malloc(sizeof(CLinkList));
	    rear=head;
	    rear->next=head;
	    return head;
}

CLinkList *createlist(int n)
{
	   CLinkList *p;
	   head=(CLinkList*)malloc(sizeof(CLinkList));
	   rear=head;
	   rear->next=head;
	   for(int i=1;i<=n;++i)
	   {
	   	        p=(CLinkList*)malloc(sizeof(CLinkList));
	   	        scanf("%d",&p->data);
	   	        rear->next=p;
	   	        rear=p;
	   }
	   p->next=head;
	   return head;
}



void insertlist(CLinkList *head,int n)
{
	CLinkList *p=head,*q=NULL;
	int i=1;
	while(p->next!=head&&i<n)
	{
		p=p->next;
		++i;
	}
	q=(CLinkList*)malloc(sizeof(CLinkList));
	scanf("%d",&q->data);
	q->next=p->next;
	p->next=q;
}



void deletelist(CLinkList *head,int n)
{
	CLinkList *p=head,*q=NULL;
	int i=1;
	while(p->next!=head&&i<n)
	{
		p=p->next;
		++i;
	}
	q=p->next;
	p->next=q->next;
	free(q);
	p=p->next;
}

void clearlist(CLinkList *head)
{
	CLinkList *p=head,*q=NULL;
	while(p->next!=head)
	{
		q=p;
		free(q);
		p=p->next;
	}
	head->next=head;
}

void printlist(CLinkList *head)
{
	CLinkList *p=head->next;
	while(p->next!=head)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}

int main()
{
	CLinkList *head=NULL;
	printf("--------------------------------------\n" );
	head=createlist(6);
	printlist(head);
	printf("--------------------------------------\n" );
	insertlist(head,3);
	printlist(head);
	printf("--------------------------------------\n" );
	deletelist(head,5);
	printlist(head);
	printf("--------------------------------------\n" );
	clearlist(head);
	return 0;
}








