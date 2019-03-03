/**************循环链表方法1****************/
#include<stdio.h>
#include<stdlib.h>
#define Error 0
#define OK 1
typedef int ElemType;
typedef int Status;

struct  node
{
	ElemType data;
	struct node* next;
}Node;

typedef struct node* CLinkList;

Status Init_LinkList(CLinkList *head)
{
	*head=(CLinkList)malloc(sizeof(node));
	if(!(*head))
		return Error;
	else
		(*head)->data=1;
		(*head)->next=(*head);
	    return OK;
}

Status IsLinkListEmpty(CLinkList head)
{
	return head->next==head;
}

void CreateLinkListEnd(CLinkList *head,int n)
{
	CLinkList p,rear;
	rear=(*head);
	for(int i=2;i<=n;++i)
	{
		p=(CLinkList)malloc(sizeof(node));
		p->data=i;
       rear->next=p;
       rear=p;
	}
	rear->next=(*head);
}

void ClearList(CLinkList *head)
{
	CLinkList p,q;
	p=(*head)->next;
	while(p!=(*head))
	{
		q=p;
		p=p->next;
		free(q);
	}
	(*head)->next=(*head);
}



int ListLength(CLinkList head)
{
	int i=0;
	CLinkList p;
	p=head->next;
	while(p!=head)
	{
		p=p->next;
		++i;
	}
	return i;
}

CLinkList GetListElem(CLinkList head,int n)
{
	CLinkList p=head->next;
	int i=1;
    while(p!=head&&i<n)
    {
    	p=p->next;
    	++i;
    }
    return p;
}

CLinkList GetListElemPrevious(CLinkList head,int n)
{
	CLinkList p=head;
	int i=1;
	while(p->next!=head&&i<n-1)
	{
		p=p->next;
		++i;
	}
    return p;
}

void ListPrint(CLinkList head)
{
	CLinkList p=head;
	while(p->next!=head)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("%d", p->data);
}

void ListElemDelete(CLinkList p)
{
      CLinkList pTemp;
      pTemp=p->next;
      p->next=pTemp->next;
      free(pTemp);
      p=p->next;
}



void kill(CLinkList head,int n)
{
	CLinkList pTemp=NULL,p=head;
	while(p->next!=p)
	{
		for(int i=1;i<n-1;++i)
                p=p->next;
         printf("%d->", p->next->data);
         pTemp=p->next;
         p->next=p->next->next;
         free(pTemp);
         p=p->next;
	}
	printf("%d->\n", p->data);
	free(p);

}

int main()
{
	CLinkList head,p;
	int nLength=41;
	const int n=3;
	Status i=Init_LinkList(&head);
     if(i){

		CreateLinkListEnd(&head,nLength);
		ListPrint(head);
		printf("\n");
		p=GetListElemPrevious(head,3);
		printf("%d\n", p->next->data);
		kill(head,n);
		printf("\n");
	}
        
	return 0;
}

