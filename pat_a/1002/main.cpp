#include <stdio.h>
const int maxn = 1001;

int main(){
    int k, n;
    double a[maxn], num;
    for(int i=0;i<maxn;i++){
        a[i] = 0.0;
    }
    for(int i=0;i<2;i++){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &n);
            scanf("%lf", &num);
            a[n] += num;
        }
    }
    k=0;
    for(int i=0; i<maxn; i++){
        if(a[i]!=0.0) k++;
    }
    printf("%d", k);
    if(k!=0) printf(" ");
    for(int i=maxn-1; i>=0; i--){
        if(a[i]!=0.0){
            printf("%d ", i);
            printf("%0.1f", a[i]);
            k--;
            if(k!=0){
                printf(" ");
            }
        }
    }
return 0;

}

