#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 99999999;
const int maxn = 501;
int main()
{
    int n, m, C1, C2;     ///n为城市数量， m为路的数量, C1为在的地方， C2为要去的地方
    int teamNum[maxn];   ///存放没个城市的救援队数量
    int arr[maxn][maxn];  ///存放两个城市间的距离
    int visited[maxn] = {0};
    int w[maxn] = {0}, num[maxn] = {0}, dist[maxn];
    scanf("%d%d%d%d", &n, &m, &C1, &C2);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = INF;
        }
    }
    int c1, c2, L;
    for(int i=0; i<n; i++){
        scanf("%d", &teamNum[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &c1, &c2, &L);
        arr[c1][c2] = L;
        arr[c2][c1] = L;
    }
    fill(dist, dist+maxn, INF);
    dist[C1] = 0;
    num[C1] = 1;
    w[C1] = teamNum[C1];
    for(int i=0; i<n; i++){
        int min_dist = INF;
        int k=-1;
        for(int j=0; j<n; j++){
            if(visited[j]==0&&dist[j] < min_dist){
                k = j;
                min_dist = dist[j];
            }
        }
        visited[k] = 1;
        if(k==-1) break;
        for(int j=0; j<n; j++){
            if(arr[k][j]!=INF&&visited[j]==0){
                if(dist[j] > dist[k] + arr[k][j]){
                    dist[j] = dist[k] + arr[k][j];
                    w[j] = w[k] + teamNum[j];
                    num[j] = num[k];
                }else if(dist[j] == dist[k] + arr[k][j]){
                    if(w[k]+teamNum[j] > w[j]){
                        w[j] = w[k] + teamNum[j];
                    }
                    num[j] += num[k];
                }
            }
        }
    }
    printf("%d %d\n", num[C2], w[C2]);
    return 0;
}
