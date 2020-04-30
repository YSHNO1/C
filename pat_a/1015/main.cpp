#include <stdio.h>
#include <math.h>
bool isPrime(int n){
    if(n <= 1) return false;
    for(int i=2; i<=(int)sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    int n, d;
    while(scanf("%d", &n)!=EOF){
        if(n < 0) break;
        scanf("%d", &d);
        if(isPrime(n) == false) {
            printf("No\n");
            continue;
        }
        int len = 0, a[100];
        while(n!=0){
            a[len++] = n % d;
            n = n / d;
        }
        for(int i=0; i<len; i++){
            n = n * d + a[i];
        }
        if(isPrime(n) == true) printf("Yes\n");
        else printf("No\n");
    }
}
