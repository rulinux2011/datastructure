#include<iostream>
#include<cstddef>
#include<cstdio>
using namespace  std;

const int OK = 1;
const int ERROR = 0;
const int LETTERNUM = 26;
typedef char ElemType;

struct Node{
    ElemType data;
    Node * prior;//前驱结点
    Node * next;//后驱结点
};

int InitList(Node *&L){
    Node *p,*q;
    int i;

    L = new Node; //头结点
    L->next = L->prior = NULL;
    p = L; //p是当前指针

    for(int i=0;i<LETTERNUM;i++){
        q = new Node; //q是临时指针
        q->data = 'A' + i;
        q->prior = p;
        q->next = p->next;
        p->next = q;
        p = q;//指针移动
    }
    p->next = L->next; //尾结点指向head->next(第一个有字母的地址)
    L->next->prior = p;

    return OK;
}

void Change(Node *&L,int i){ //移动头指针
    if (i>0){
        while(i--){
            L = L->next;
        }
    }
    else if (i<0){
        L = L->next ;
        while(i++){
            L = L->prior;
        }
    }
    else{
        L = L->next;
    }
}


int main(){
    Node *head = NULL;
    int i,n;
    InitList(head);
    //Node *s_head = head; // 保存头结点之后删除
    cout<<"输入位置："<<endl;
    cin>>n;
    Change(head,n);

    for(i = 0;i<LETTERNUM;++i){
        head = head->next;
        cout<<head->data<<" ";
    }

    cout<<endl;
    return 0;
}
