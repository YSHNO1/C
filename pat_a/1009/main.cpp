#include <stdio.h>
const int maxn = 2001;
struct Index{
    int exp; // 指数
    double coe; // 系数
}index[1000];
int main()
{
    int n, m, k, exp; //m存储
    double a[maxn] = {0.0}, coe;   //exp和coe存储第二个多项式的内容
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %lf", &index[i].exp, &index[i].coe);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %lf", &exp, &coe);   // 读入一项乘一项
        for(int j=0; j<n; j++){
            a[exp + index[j].exp] += (coe * index[j].coe);
        }
    }
    int sum = 0; // 记录总项数
    for(int i=0; i<maxn; i++){
        if(a[i] != 0.0) sum++;
    }
    //输出
    printf("%d", sum);
    for(int i=2000; i>=0; i--){
        if(a[i] != 0.0){
            printf(" %d %.1f", i, a[i]);
        }
    }
    return 0;
}
