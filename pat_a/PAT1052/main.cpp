#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node{
    int address, data, next;
    bool flag;   //判断节点是否在链表上
}node[maxn];
bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false){
        return a.flag > b.flag;
    }
    else return a.data < b.data;
}
int main()
{
    for(int i=0; i<maxn; i++){
        node[i].flag = false;
    }
    int n, address,  start;
    scanf("%d%d", &n, &start);
    for(int i=0; i<n; i++){
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int Count = 0, p = start;
    while(p != -1){
        node[p].flag = true;
        Count++;
        p = node[p].next;
    }
    if(Count == 0) printf("0 -1");
    else{
        sort(node, node+maxn, cmp);
        printf("%d %05d\n", Count, node[0].address);
        for(int i=0; i<Count; i++){
            if(i != Count-1){
                printf("%05d %d %05d", node[i].address, node[i].data, node[i].next);
                printf("\n");
            }
            else printf("%05d %d -1", node[i].address, node[i].data);
        }
    }
    return 0;
}
