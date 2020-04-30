#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct point{
    int x;
    int y;
}P[110];

bool cmp(point a, point b){
    if(a.x != b.x) return a.x > b.x;
    else return a.y < b.y;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=0){
        for(int i=0; i<n; i++){
            scanf("%d%d", &P[i].x, &P[i].y);
        }
        sort(P, P+n, cmp);
        int ans = 1, lastX = P[0].x;
        for(int i=1; i<n; i++){
            if(P[i].y<=lastX){
                lastX = P[i].x;
                ans++;
            }
        }
    printf("%d\n", ans);
    }
}
