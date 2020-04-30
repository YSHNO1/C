#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int t[101];
struct Customer{
    int arrivetime, needtime;
}c[10001];
bool cmp(Customer a, Customer b){
    return a.arrivetime < b.arrivetime;
}

int main()
{
    int n, k, sum = 0;
    scanf("%d%d", &n, &k);
    int hour, minute, second, need;
    int starttime = 28800, endtime = 61200; //17：00转化为秒
    for(int i=0; i<k; i++){
        t[i] = starttime;
    }
    for(int i=0; i<n; i++){
        scanf("%d:%d:%d %d", &hour, &minute, &second, &need);
        c[i].arrivetime = hour*60*60 + minute*60 + second;
        c[i].needtime = need*60;
    }
    sort (c, c+n, cmp);
    int num = 0;//记录能够处理业务的人数
    for(int i=0; i<n; i++){
        if(c[i].arrivetime > endtime) continue;
        int temp = 0;   //找到最先结束的人，也就是结束时间最早的人
        for(int j=0; j<k; j++){
            if(t[j] < t[temp]) temp = j;
        }
        if(t[temp] >= c[i].arrivetime){
            sum += t[temp] - c[i].arrivetime;
            t[temp] += c[i].needtime;
        }
        else t[temp] = c[i].arrivetime + c[i].needtime;
        num++;
    }
    printf("%.1f\n", (sum * 1.0) / (60 * num));
}
