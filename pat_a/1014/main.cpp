#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct node{
    int intime, endtime;  //intime标记队首元素出队时间  endtime记录队末元素出队时间，判断是否超过5点
    queue<int> q;
};

int main()
{
    int n, m, k, p, index=1;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    vector<int> time(k+1), result(k+1);//顾客办理业务所需时间  顾客办理业务结束时间
    for(int i=1; i<=k; i++)
        scanf("%d", &time[i]);
    vector<node> window(n+1);   //n个窗口n个队
    vector<bool> sorry(k+1, false);
    //先处理黄线内的m个人
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(index <= k){
                window[j].q.push(time[index]);
                if(window[j].endtime >= 540)  //队尾的人结束时间超过了下午五点
                    sorry[index] = true;
                window[j].endtime += time[index];
                result[index] = window[j].endtime;
                index++;
            }
        }
    }
    //处理黄线外的人
    while(index <= k){
        int minIntime = window[1].intime, minWindow = 1;
        //先找到最先有空位的窗口，也就是endtime最小的队列
        for(int i=2; i<=n; i++){
            if(window[i].intime < minIntime){
                minIntime = window[i].intime;
                minWindow = i;
            }
        }
        window[minWindow].q.pop(); //找到最先出队的使其出队
        window[minWindow].q.push(time[index]);//黄线的人入队
        window[minWindow].intime += window[minWindow].q.front(); //队首的结束时间变化了
        if(window[minWindow].endtime >= 540){
            sorry[index] = true;
        }
        window[minWindow].endtime += time[index]; //更新队尾的结束时间
        result[index] = window[minWindow].endtime;//可以记录当前顾客结束时间
        index++;
    }
    //输出
    for(int i=1; i<=p; i++){
        int check;
        scanf("%d", &check);
        int temp = result[check];
        if(sorry[check] == true){
            printf("Sorry\n");
        }
        else printf("%02d:%02d\n", (temp+480)/60, (temp+480)%60);  //将全部的分钟转换为具体时间
    }
    return 0;
}
