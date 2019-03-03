#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define  OK  1
#define  Error 0
#define  TRUE  1
#define  FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node* next;
}Node;

typedef struct node* LinkList;

Status Init_LinkList(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	if(!(*L))
	   return Error;
	else
	   (*L)->next=NULL;
	   return OK;
}

Status IsLinkListEmpty(LinkList L)
{
	if(L->next)
	    return FALSE;
	else
	    return TRUE;
}

int ListLength(LinkList L)
{
	int i=0;
	LinkList p;
	p=L->next;
	while(p)
	{
		p=p->next;
		++i;
	}
	return i;	
}

void print_LinkList(LinkList L)
{
	LinkList p;
	p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void ClearList(LinkList *L)
{
	LinkList p,q;
	p=(*L)->next;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	(*L)->next=NULL;
}

void CreateLinkListHead(LinkList *L,int n)
{
	LinkList p;
	srand(time(0));
	for(int i=0;i<n;++i)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		p->next=(*L)->next;
		(*L)->next=p;
	}
}

void CreateLinkListEnd(LinkList *L,int n)
{
	LinkList p,pEnd;
	srand(time(0));
	pEnd=(*L);
	for(int i=0;i<n;++i)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		pEnd->next=p;
		pEnd=p;
	}
	pEnd->next=NULL;
}

LinkList GetMidNode(LinkList L)
{
	LinkList p1,p2;
	p1=L;
	p2=p1;
	while(p1->next)
	{
		if(p1->next->next)
		{
			p1=p1->next->next;
			p2=p2->next;
		}else{
			p1->next=NULL;
		}
	}	
	return p2;
}

LinkList GetElem(LinkList L,int n)
{
	LinkList p;
	int i=1;
	p=L->next;
	while(p&&i<n)
	{
		p=p->next;
		++i;
	}
	return p;
}

int GetListElemNum(LinkList L,LinkList p)
{
	LinkList pTemp;
	int i=1;
	pTemp=L->next;
	while(pTemp)
	{		
		if(p==pTemp)
		{
			return i;
		}
		pTemp=pTemp->next;
		++i;
	}
	return i;
}

void showorder()
{
	printf("1.显示链表内容\n");
	printf("2.头插建立链表\n");
	printf("3.尾插建立链表\n");
	printf("4.显示链表长度\n");
	printf("5.取中间节点的值\n");
	printf("6.显示链表节点的值\n");
	printf("7.清空链表\n");
	printf("0.退出\n");
}

int main()
{
	int nflag=1;
	int norder=-1;
	int nLength;
	int n;
	LinkList L,pTemp;
	ElemType e;
	Status i=Init_LinkList(&L);
	if(i)
	{
	
	showorder();
	while(nflag)
	{
		printf("\n");
		printf("请输入指令:");
		scanf("%d",&norder);
		switch(norder)
		{
		   case 1:
		     if(IsLinkListEmpty(L))
		         printf("List is empty!\n");
		     else
		         print_LinkList(L);	
		         printf("\n");	   
		   break;
		   case 2:
		         CreateLinkListHead(&L,20);
		   break;
		   case 3:
		         CreateLinkListEnd(&L,20); 
		   break;
		   case 4:
		       nLength=ListLength(L);
		       printf("%d \n",nLength);
		   break;
		   case 5:
		        pTemp=GetMidNode(L);
		        e=pTemp->data;
		        nLength=GetListElemNum(L,pTemp);
		        printf("List: ");
		        printf("%d %d\n",nLength,e);
		   break;
		   case 6:
		        printf("请输入要查询的链表元素:");
		        scanf("%d",&n);
		        pTemp=GetElem(L,n);
		        printf("%d\n", pTemp->data);
		   break;
		   case 7:
		       ClearList(&L);
		   break;
		   case 0:
		    nflag=0;
		   break;
	   }
	}
}else{
	printf("Error!\n");
}
	
	return 0;
}
