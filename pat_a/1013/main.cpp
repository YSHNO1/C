#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1001;
int n, m, k; //N为城市的个数，M为剩余的铁路现数量，k为被占城市的数量
int a[maxn][maxn] = {0};
bool visit[maxn];  // 访问数组
//深度优先遍历
void dfs(int node){
   visit[node] = true; // 标记当前的节点为已访问
   for(int i=1; i<=n; i++){
        if(visit[i]==false && a[node][i] == 1){
            dfs(i);
        }
   }
}
int main()
{
    int c1, c2;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<m; i++){
        scanf("%d%d", &c1, &c2);
        a[c1][c2] = 1;
        a[c2][c1] = 1;
    }
    for(int i=0; i<k; i++){
        fill(visit, visit+1001, false);
        int temp = 0;
        scanf("%d", &temp);
        visit[temp] = true;
        int num = 0;   // 记录连通分量
        for(int j=1; j<=n; j++){
            if(visit[j] == false){
                dfs(j);
                num++;
            }
        }
        printf("%d\n", num-1);
    }
    return 0;
}
