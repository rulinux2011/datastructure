#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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

Status init_CLinkList(CLinkList *L)
{
	(*L)=(CLinkList)malloc(sizeof(node));
	if(!(*L))
		  return Error;
	else
		(*L)->next=(*L);
	      return OK;
}

Status IsLinkListEmpty(CLinkList L)
{
	return L->next==L;
}

int LinkLength(CLinkList L)
{
	int i=0;
	CLinkList p=L->next;
	while(p!=L)
	{
		p=p->next;
		++i;
	}
	return i;
}

void ListPrint(CLinkList L)
{
	CLinkList p=L->next;
	while(p!=L)
	{
		printf("%d ", p->data);
		p=p->next;
	}
}

void ClearList(CLinkList *L)
{
	CLinkList p,q;
	p=(*L)->next;
	while(p!=(*L))
	{
		q=p;
		p=p->next;
		free(q);
	}
	(*L)->next=(*L);
}

void CreateLinkListHead(CLinkList *L,int n)
{
	CLinkList p;
	srand(time(0));
	for(int i=0;i<n;++i)
	{
		p=(CLinkList)malloc(sizeof(node));
		p->data=rand()%100+1;
		p->next=(*L)->next;
		(*L)->next=p;
	}
}

void CreateLinkListEnd(CLinkList *L,int n)
{
	CLinkList p,rear;
	rear=(*L);
	srand(time(0));
	for(int i=0;i<n;++i)
	{
		p=(CLinkList)malloc(sizeof(node));
		p->data=rand()%100+1;
	    rear->next=p;
		rear=p;
	}
	rear->next=(*L);
}

CLinkList GetMidNode(CLinkList L)
{
	CLinkList p,q;
	p=L;q=L;
	while(p->next!=L)
	{
		if(p->next->next!=L)
		{
			p=p->next->next;
			q=q->next;
		}else{
			p->next=L;
		}
	}
    return q;
}

CLinkList GetElem(CLinkList L,int n)
{
	CLinkList p=L->next;
	int i=1;
	while(p!=L&&i<n)
	{
		p=p->next;
		++i;
	}
	return p;
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
	int nOrder=-1;
	int nLength=0;
	int n;
	CLinkList L,pTemp;
	showorder();
	Status i=init_CLinkList(&L);

    if(i)
    {
    	while(nflag)
    	{
    		printf("\n");
    		printf("请输入指令:");
    		scanf("%d",&nOrder);
    		switch(nOrder)
    		{
    			case 1:
    			     if(IsLinkListEmpty(L))
    			     {
    			     	printf("List is empty!\n");
    			     }else{
    			     	ListPrint(L);
    			     	printf("\n");
    			     }
    			break;
    			case 2:
    			      CreateLinkListHead(&L,20);
                break;
                case 3:
                      CreateLinkListEnd(&L,20);
                break;
                case 4:
                       nLength=LinkLength(L);
                       printf("%d\n", nLength);
                break;
                case 5:
                       pTemp=GetMidNode(L);
                       printf("%d\n", pTemp->data);
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
    	return 0;
    }
	return 0;
}