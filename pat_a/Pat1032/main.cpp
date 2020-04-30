#include <stdio.h>
#include <string.h>

const int maxn = 100010;
struct node{
    char data;
    int next;   //ָ����
    bool flag; //��ǵ�ǰ�ڵ����ϸ������Ƿ����
}node[maxn];
int main()
{
    for(int i=0; i<maxn; i++){
        node[i].flag = false;
    }
    int s1, s2, n;   //s1s2������������׵�ַ
    scanf("%d%d%d", &s1, &s2, &n);
    int address, next;
    char data;
    for(int i=0; i<n; i++){
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }

    int p;
    //������һ������
    for(p = s1; p != -1; p = node[p].next){
        node[p].flag = true;
    }
    //�����ڶ�������
    for(p=s2; p!=-1; p = node[p].next){
        if(node[p].flag == true) break;
    }
    if(p!=-1){
        printf("%05d", p);
    }
    else printf("-1\n");
    return 0;
}

