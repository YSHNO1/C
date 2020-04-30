#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
//树的fs遍历
int N, M;   // N为节点个数， M为非叶子节点的个数
int a, K, c, maxD = -1;   //a为一个非叶子节点， K为对应非叶子节点孩子的个数, c用来暂时记录非叶子节点的某个孩子
int tree[101];
vector<int> ID[101];

//深度优先遍历
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
                ID[a].push_back(c);    //容器的用法
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
