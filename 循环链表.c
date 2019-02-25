#include<stdio.h>
#include<stdlib.h>
#define OK 1;
#define ERROR 0;

typedef struct node
{
   char data;
   struct node* piror;
   struct node* next;
}DuaLinkList;

void initlist(DuaLinkList *L)
{
   L=(DuaLinkList *)malloc(sizeof(DuaLinkList));
   if(L!=NULL)
   {
     L->next=L;
     L->piror=L;
   }else
     exit(0);
}

DuaLinkList * createlist(DuaLinkList *L,int n)
{
   DuaLinkList *p,*q;
   int i=0;
   p=L->piror;
   for(int i=0;i<n;++i)
   {
      q=(DuaLinkList*)malloc(sizeof(DuaLinkList));
       if(q==NULL)
        {
          exit(0);
        }
      q->data='A'+i;
      q->piror=p;
      q->next=p->next;
      p->next=q;
      p=q;
   }
   p->next=L->next;
   L->next->piror=p;
   return L->next;
}



void listprint(DuaLinkList *L)
{
   DuaLinkList *p;
   p=L->next;
   while(p!=L)
   {
      printf("%c ",p->data);
      p=p->next;
   }
   printf("\n");
}

void clearlist(DuaLinkList *L)
{
   DuaLinkList *p;
   p=L->next;
   while(p!=L)
   {
      p=p->next;
      free(p->piror);
   }
   L->piror=L;
   L->next=L->piror;
}

void destorylist(DuaLinkList *L)
{
   DuaLinkList *p;
   p=L->next;
   while(p!=L)
   {
      p=p->next;
      free(p->piror);
   }
   free(L);
   L=NULL;
}

int main()
{
   DuaLinkList *L;
   const int n=26;
   initlist(L);
   createlist(L,n);
   listprint(L);
   return 0;
}







