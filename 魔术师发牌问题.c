#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node* next;
}linknode,*LinkList;

LinkList initlist(LinkList *L,int n)
{
    LinkList p,q;
    (*L)=(LinkList)malloc(sizeof(linknode));
    if(!(*L))
    {
        return NULL;
    }
    (*L)->next=NULL;
    p=(*L);
    for(int i=1;i<=n;++i)
    {
        q=(LinkList)malloc(sizeof(linknode));
        q->data=0;
        q->next=p->next;
        p->next=q;
        p=q;
    }
    p->next=(*L)->next;
    return p->next;
}

void magican(LinkList *L,int n)
{
    LinkList p=(*L);
    p->data=1;
    for(int i=2;i<=n;++i)
    {
        int j=1;
        while(j<=i)
        {
            p=p->next;
            if(p->data==0)
               ++j;
        }
        p->data=i;
    }
}

void printlist(LinkList L)
{
    LinkList p=L;
    while(p->next!=L)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}

int main()
{
    LinkList L;
    const int n=13;
    L=initlist(&L,n);
    magican(&L,n);
    printlist(L);
    return 0;
}