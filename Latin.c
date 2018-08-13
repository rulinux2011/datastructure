#include<stdio.h>
#include<stdlib.h>
typedef struct  node
{
	int data;
	struct node* next;	
}CLinkList;

CLinkList *head,*rear;

CLinkList *createlist(int n)
{
	head=(CLinkList*)malloc(sizeof(node));
	rear=head;
	rear->next=head;
	CLinkList *p;
	int i=1;
	while(i<=n)
	{
		p=(CLinkList*)malloc(sizeof(node));
		p->data=i++;
		rear->next=p;
		rear=p;
	}
	p->next=head->next;
	free(head);
	return p->next;
}

int main()
{
	int n;
	scanf("%d",&n);
	head=createlist(n);
	for(int i=1;i<=n;++i)
	{
		CLinkList *p=head;
		for(int j=1;j<=n;++j)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
		head=head->next;
	}
	return 0;
}



