#include <stdio.h>
#include <string.h>

const int maxn = 30;
int n, V, maxValue = 0;  //物品件数n，背包容量v，最大价值m
int w[maxn], c[maxn];

void DFS(int index, int sumN, int sumC){
    if(index == n){
        if(sumN <= V &&sumC > maxValue){
            maxValue = sumC;
        }
        return;
    }
    DFS(index+1, sumN, sumC);
    DFS(index+1, sumN + w[index], sumC+c[index]);
}
int main()
{
    scanf("%d%d", &n, &V);
    for(int i=0; i<n; i++){
        scanf("%d", &w[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &c[i]);
    }
    DFS(0,0,0);
    printf("%d", maxValue);
    return 0;

}
