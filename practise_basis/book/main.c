#include <stdio.h>
#define MAXSIZE 100000
int main(){
    int n, a[MAXSIZE], maxm, minm;
    double midm;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    if(a[0] > a[n-1]){
        maxm = a[0];
        minm = a[n-1];
    }
    else {
        maxm = a[n-1];
        minm = a[0];
    }
    if(n % 2 == 0 ){
        midm = (a[n/2-1]+a[n/2])/2.0;
        if((a[n/2-1]+a[n/2])%2 == 1)
        printf("%d %.1f %d", maxm, midm, minm);
        else printf("%d %.0f %d", maxm, midm, minm);
    }
    else {
        midm = a[n/2];
        printf("%d %.0f %d", maxm, midm, minm);
        }
    return 0;

}
