#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
//����fs����
int N, M;   // NΪ�ڵ������ MΪ��Ҷ�ӽڵ�ĸ���
int a, K, c, maxD = -1;   //aΪһ����Ҷ�ӽڵ㣬 KΪ��Ӧ��Ҷ�ӽڵ㺢�ӵĸ���, c������ʱ��¼��Ҷ�ӽڵ��ĳ������
int tree[101];
vector<int> ID[101];

//������ȱ���
void dfs(int index, int depth){
    if(ID[index].size() == 0){
        tree[depth] += 1;
        maxD = max(depth, maxD);
    }
    for(int i=0; i<ID[index].size(); i++){
        dfs(ID[index][i], depth+1);
    }
}
int main()
{
    while(scanf("%d%d", &N, &M)!=EOF){
        for(int i=0; i<M; i++){
            scanf("%d%d", &a, &K);
            for(int j=0; j<K; j++){
                scanf("%d", &c);
                ID[a].push_back(c);    //�������÷�
            }
        }
        dfs(1, 1);
        for(int i=1; i <= maxD; i++){
            if(i != 1){
                printf(" ");
            }
            printf("%d", tree[i]);
        }
    }
    return 0;
}
