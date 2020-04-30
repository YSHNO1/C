#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = 99999999;
int cmax, n, sp, m;     //Cmax最大容量, N总车站的数量，sp出问题的车站 m路线的数量
int e[501][501], dis[501], weight[501];
bool visit[501];
int minNeed = inf, minBack = inf;
vector<int> pre[501], path, tempppath;

void dfs(int v){
    tempppath.push_back(v);
    if(v==0){
        int need = 0, Back = 0;
        for(int i=tempppath.size()-1; i>=0; i--){
            int id = tempppath[i];
            if(weight[id] > 0){
                Back += weight[id];
            }
            else{
                if(Back > (0 - weight[id])){
                    Back += weight[id];
                }
                else{
                    need += ((0 - weight[id]) - Back);
                    Back = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            minBack = Back;
            path = tempppath;
        }
        else if(need == minNeed && Back < minBack){
            minBack = Back;
            path = tempppath;
        }
        tempppath.pop_back();
        return ;
    }
    for(int i=0; i<pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    tempppath.pop_back();

}

int main()
{
    fill(e[0], e[0]+501*501, inf);
    fill(dis, dis+501, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax/2; //各节点权重计为距离完美状态的差
    }
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    for(int i=0; i<=n; i++){
        int u=-1, minn = inf;
        for(int j=0; j<=n; j++){
            if(visit[j] == false && dis[j] < minn){
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v=0; v<=n; v++){
            if(visit[v] == false &&e[u][v] != inf){
                if(dis[v] > dis[u] + e[u][v]){
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v] == dis[u] + e[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i=path.size() - 2; i>=0; i--){
        printf("->%d", path[i]);
    }
    printf(" %d", minBack);
    return 0;
}
