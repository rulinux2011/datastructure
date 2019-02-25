#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define OK 1
#define Error 0
#define TRUE 1
#define FALSE 0


typedef int Status;
typedef int ElemType;

struct node
{
   ElemType data;
   struct node* next;
}Node;

typedef struct node* LinkList;

Status InitList(LinkList *L)
{
   *L=(LinkList)malloc(sizeof(Node));
   if(!(*L))
      return Error;
   (*L)->next=NULL;
      return OK;
}

Status IsListEmpty(LinkList L)
{
   return L->next==NULL;
}

int ListLength(LinkList L)
{
   int j=0;
   LinkList p=L->next;
   while(p)
   {
      p=p->next;
      ++j;
   }
   return j;
}

void print_List(LinkList L)
{
   LinkList p=L->next;
   while(p!=NULL)
   {
      printf("%d ",p->data);
      p=p->next;
   }
}


void LinkList_insert_head(LinkList *L,int n)
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

void LinkList_insert_end(LinkList *L,int n)
{
     LinkList p,pEnd;
     srand(time(0));
     pEnd=*L;
     for(int i=0;i<n;++i)
     {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        pEnd->next=p;
        pEnd=p;
     }
     pEnd->next=NULL;
}

Status GetMidNode(LinkList L,ElemType *e)
{
   LinkList search,mid;
   mid=L;
   search=L;

   while(search->next!=NULL)
   {
      if(search->next->next!=NULL)
      {
         search=search->next->next;
         mid=mid->next;
      }
      else
      {
         search=search->next;
      }
   }
   *e=mid->data;
   return OK;
}

Status ClearList(LinkList* L)
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
   return OK;
}


void ShowOrder()
{
   printf("1.Lookup the LinkList\n");
   printf("2.Create the LinkList by insert at head\n");
   printf("3.Create the LinkList by insert at end\n");
   printf("4.ListLength\n");
   printf("5.Value of the Middle Node\n");
   printf("6.Clear the List\n");
   printf("0.Quit\n");
}

int main()
{
   int nflag=1;
   int nOrder=-1;
   int nLength=0;
   LinkList L;
   ElemType e;
   Status i;
   i=InitList(&L);
   ShowOrder();




   while(nflag)
   {
      printf("\n");
      printf("Please take your order:");
      scanf("%d",&nOrder);

      switch(nOrder)
      {
        case 1:
           if(IsListEmpty(L))
                printf("LinkList is empty!\n");
           else
                print_List(L);
           break;
        case 2:
           LinkList_insert_head(&L,10);
           break;
        case 3:
           LinkList_insert_end(&L,10);
           break;
        case 4:
           nLength=ListLength(L);
           printf("%d\n",nLength);
           break;
        case 5:
           GetMidNode(L,&e);
           printf("%d \n",e);
           break;
        case 6:
           ClearList(&L);
           break;
        case 0:
            nflag=0;
           break;
      }
   }

   return 0;
}
