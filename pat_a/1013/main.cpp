#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1001;
int n, m, k; //NΪ���еĸ�����MΪʣ�����·��������kΪ��ռ���е�����
int a[maxn][maxn] = {0};
bool visit[maxn];  // ��������
//������ȱ���
void dfs(int node){
   visit[node] = true; // ��ǵ�ǰ�Ľڵ�Ϊ�ѷ���
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
        int num = 0;   // ��¼��ͨ����
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
