#include <stdio.h>
#include <algorithm>
using namespace std;
struct Student{
    int ID;
    int best;   //记录最好的科目代号
    int score[4];
    int ranks[4];
}s[2001];
int exist[1000000];  //检查数组
int flag = -1;   //flag用来标记科目
int cmd(Student a, Student b){
    return a.score[flag] > b.score[flag];
}
int main()
{
   int n, m;  // n为学生总数，m检查成绩的学生人数
   scanf("%d%d", &n, &m);
   for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &s[i].ID, &s[i].score[1], &s[i].score[2], &s[i].score[3]);
        s[i].score[0] = (s[i].score[1] + s[i].score[2] + s[i].score[3] + 1.5)/3;
   }
   //给各科排名
   for(flag=0; flag<4; flag++){
        sort(s, s+n, cmd);
        s[0].ranks[flag] = 1;
        for(int i=1; i<n; i++){
            s[i].ranks[flag] = i+1; // 排名赋值
            if(s[i].score[flag] == s[i-1].score[flag])  // 成绩相同，改成相同的排名
            s[i].ranks[flag] = s[i-1].ranks[flag];
        }
   }
   for(int i=0; i<n; i++){
       exist[s[i].ID] = i+1;
       s[i].best = 0;
       int t = s[i].ranks[0];
       for(int j=1; j<4; j++){
            if(s[i].ranks[j] < t){
                t = s[i].ranks[j];
                s[i].best = j;
            }
       }
   }
   char c[] = {'A', 'C', 'M', 'E'};
   for(int i=0; i<m; i++){
        int ID;
        scanf("%d", &ID);
        int temp = exist[ID];
        if(temp!=0){
            int best = s[temp-1].best;
            printf("%d %c\n", s[temp-1].ranks[best], c[best]);
        }
        else printf("N/A\n");
   }
   return 0;
}
