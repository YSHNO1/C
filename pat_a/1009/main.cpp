#include <stdio.h>
const int maxn = 2001;
struct Index{
    int exp; // ָ��
    double coe; // ϵ��
}index[1000];
int main()
{
    int n, m, k, exp; //m�洢
    double a[maxn] = {0.0}, coe;   //exp��coe�洢�ڶ�������ʽ������
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %lf", &index[i].exp, &index[i].coe);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %lf", &exp, &coe);   // ����һ���һ��
        for(int j=0; j<n; j++){
            a[exp + index[j].exp] += (coe * index[j].coe);
        }
    }
    int sum = 0; // ��¼������
    for(int i=0; i<maxn; i++){
        if(a[i] != 0.0) sum++;
    }
    //���
    printf("%d", sum);
    for(int i=2000; i>=0; i--){
        if(a[i] != 0.0){
            printf(" %d %.1f", i, a[i]);
        }
    }
    return 0;
}
