#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    node *next;
};
node *create(int Array[]){
    node *p, *pre, *head;
    head = new node;    // �½�ͷ�ڵ�
    head->next = NULL;
    pre = head;
    for(int i=0; i < 5; i++){
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}
int Search(node *head, int x){
    int Count = 0;
    node *p = head->next;
    while(p!=NULL){
        if(p->data == x){
            Count++;
        }
        p = p->next;
    }
    return Count;
}
void Insert(node *head, int pos, int x){
    node *p = head;
    for(int i=0; i<pos-1; i++){
        p = p->next;
    }
    node *q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}
int main()
{
    int Array[5] = {5, 3, 6, 2, 1};
    node *L = create(Array);
    Insert(L, 2, 8);   // ���Բ��뺯��
    node*p  = L->next;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    //���Ҳ���
    int x, num;
    scanf("%d", &x);
    num = Search(L, x);
    printf("%d", num);
}
