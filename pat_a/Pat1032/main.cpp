#include <stdio.h>
#include <string.h>

const int maxn = 100010;
struct node{
    char data;
    int next;   //指针域
    bool flag; //标记当前节点在上个链表是否出现
}node[maxn];
int main()
{
    for(int i=0; i<maxn; i++){
        node[i].flag = false;
    }
    int s1, s2, n;   //s1s2是两条链表的首地址
    scanf("%d%d%d", &s1, &s2, &n);
    int address, next;
    char data;
    for(int i=0; i<n; i++){
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }

    int p;
    //便利第一条链表
    for(p = s1; p != -1; p = node[p].next){
        node[p].flag = true;
    }
    //便利第二条链表
    for(p=s2; p!=-1; p = node[p].next){
        if(node[p].flag == true) break;
    }
    if(p!=-1){
        printf("%05d", p);
    }
    else printf("-1\n");
    return 0;
}

