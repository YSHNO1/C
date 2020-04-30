#include <stdio.h>
#include <algorithm>
using namespace std;
struct Student{
    int ID;
    int best;   //��¼��õĿ�Ŀ����
    int score[4];
    int ranks[4];
}s[2001];
int exist[1000000];  //�������
int flag = -1;   //flag������ǿ�Ŀ
int cmd(Student a, Student b){
    return a.score[flag] > b.score[flag];
}
int main()
{
   int n, m;  // nΪѧ��������m���ɼ���ѧ������
   scanf("%d%d", &n, &m);
   for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &s[i].ID, &s[i].score[1], &s[i].score[2], &s[i].score[3]);
        s[i].score[0] = (s[i].score[1] + s[i].score[2] + s[i].score[3] + 1.5)/3;
   }
   //����������
   for(flag=0; flag<4; flag++){
        sort(s, s+n, cmd);
        s[0].ranks[flag] = 1;
        for(int i=1; i<n; i++){
            s[i].ranks[flag] = i+1; // ������ֵ
            if(s[i].score[flag] == s[i-1].score[flag])  // �ɼ���ͬ���ĳ���ͬ������
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
