
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

struct node
{
    ElemType data;
    struct node* next;
    
}Node;

typedef struct node* CLinkList;

CLinkList CreateList(int n)
{
    CLinkList rear=NULL,head;
    head=(CLinkList)malloc(sizeof(node));
    rear=head;
    CLinkList p;
    int i=1;
    if(n)
    {
        while(i<=n)
        {
            p=(CLinkList)malloc(sizeof(node));
            p->data=i++;
            rear->next=p;
            rear=p;
        }
       p->next=head->next;
    }
    free(head);
    return p->next;
}

int main()
{
    const int n=41;
    const int m=3;
    CLinkList p=CreateList(n);
    CLinkList q=p;
    CLinkList pTemp=NULL;
    int i=1;

    while(p->next!=p&&i<n)
    {
        printf("%d ", p->data);
        p=p->next;
        ++i;
    }
    printf("%d\n", p->data);
    while(q->next!=q)
    {
        
        for(int i=1;i<m-1;++i)
        {
            q=q->next;
        }
        printf("%d -> ",q->next->data);
        pTemp=q->next;
        q->next=pTemp->next;
        free(pTemp);
        q=q->next;
    }
    printf("%d->\n", q->data);
    free(q);
    return 0;
}

