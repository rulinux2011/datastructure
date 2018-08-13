#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
      int data;
      struct node* next;
}CLinkList;

CLinkList *head,*rear;

CLinkList *createlist(int n)
{
      CLinkList *p=NULL;
      int i=1;
      head=(CLinkList*)malloc(sizeof(CLinkList));
      rear=head;
      rear->next=head;
         while(i<=n)
         {
            p=(CLinkList*)malloc(sizeof(CLinkList));
            p->data=i++;
            rear->next=p;
            rear=p;          
         }
         p->next=head->next;
         free(head);
         return p->next;
      
}

void printlist_1(CLinkList *head,int n)
{
    CLinkList *p=head;
    for(int i=1;i<=n;++i)
    {
       printf("%d ", p->data);
       p=p->next;
    }
}

void printlist_2(CLinkList *head)
{
     CLinkList *p=head;
     while(p->next!=head)
     {
         printf("%d ", p->data);
         p=p->next;
     }
     printf("%d\n",p->data);
}
void clearlist(CLinkList *head)
{
      CLinkList *p,*q;
      p=head->next;
      while(p->next!=head)
      {
        q=p;
        free(q);
        p=p->next;
      }
      head->next=head;
      free(head);
}

int main()
{
    CLinkList *pTemp,*q;
    const int n=41,m=3;
    head=createlist(n);
    printlist_2(head);
    q=head;
    while(q->next!=q)
    {
        int i=1;
        while(i<m-1)
        {
          q=q->next;
          ++i;
        }
        printf("%d ->",q->next->data );
        pTemp=q->next;
        q->next=pTemp->next;
        free(pTemp);
        q=q->next;
    }
    printf("%d ->",q->data ); 
    clearlist(q);    
    return 0;
}