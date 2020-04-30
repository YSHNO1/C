#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct tv{
    int start, t_end;
}t[101];
bool cmp(tv a, tv b){
    if(a.start != b.start) return a.start>b.start;
    else return a.t_end < b.t_end;
}
int main()
{
    int n;
    while(scanf("%d", &n)!=0){
        for(int i=0;i<n;i++){
            scanf("%d%d", &t[i].start,&t[i].t_end);
        }
        sort(t, t+n, cmp);
        int sum = 1, time = t[0].start;
        for(int i=1; i<n; i++){
            if(t[i].t_end < time){
                time = t[i].t_end;
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
