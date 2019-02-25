#include<stdio.h>
#include<stdlib.h>

#define Error 1;
#define OK 0;

typedef int ElemType;

struct node
{
   ElemType data;
   struct node* next;

}node;

typedef struct node* CLinkList;


CLinkList Create(int n)
{
   CLinkList p=NULL,head,pEnd;
   int i=1;
   head=(CLinkList)malloc(sizeof(node));
   head->next=head;
   pEnd=head;
   while(i<=n)
   {
      p=(CLinkList)malloc(sizeof(node));
      p->data=i;
      pEnd->next=p;
      pEnd=p;
      ++i;
   }
   p->next=head->next;
   free(head);
   return p->next;
}

void ListPrint(CLinkList head,int n)
{
   int i=1;
   CLinkList p=head;
   while(p->next!=head&&i<n)
   {
      printf("%d ",p->data);
      p=p->next;
   }
   printf("%d\n",p->data);
}

int main()
{
   CLinkList head=NULL,pTemp=NULL,p=NULL;
   int n=41,m=3;
   head=Create(n);
   ListPrint(head,n);
   p=head;
   while(p->next!=p)
   {
      int i=1;
      while(i<m-1)
      {
         p=p->next;
         ++i;
      }
      printf("%d ->",p->next->data);
      pTemp=p->next;
      p->next=pTemp->next;
      free(pTemp);
      p=p->next;

   }
   printf("%d ->",p->data);
   free(p);

   return 0;
}

