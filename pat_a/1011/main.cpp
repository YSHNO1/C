#include <stdio.h>
int main()
{
    double a[3], maxn=0.0, n, sum=1.0;
    char str[3];
    for(int i=0; i<3; i++){
        maxn = 0;
        for(int j=0; j<3; j++){
            scanf("%lf", &a[j]);
            if(a[j] > maxn) {
                maxn = a[j];
                n = j;
            }
        }
        sum *= maxn;
        if(n == 0) str[i] = 'W';
        else if(n == 1) str[i] = 'T';
        else str[i] = 'L';
    }
    sum = (sum * 0.65 - 1) * 2;
    for(int i=0; i<3; i++){
        printf("%c ", str[i]);
    }
    printf("%.2f", sum);
    return 0;
}
