#include <stdio.h>
#include <math.h>
const int maxn = 10010;
bool isPrime(int n){
    if(n==1)n return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i=2; i<sqr; i++){
        if(n%2==0) return false;
    }
    return true;
}
//求素数表
int prime[maxn], pNum=0;
void Find_Prime(){
    for(int i=0; i< maxn; i++){
        if(isPrime(i)==true)
            prime[pNum++] == i;
    }
}
struct factor{
    int x, cnt;
}fac[10];
int main()
{
    Find_Prime();
    int n, num=0;
    scanf("%d", &n);
    if(n==1) printf("1==1");
    else {
        printf("%d=", n);
        int sqr = (int)sqrt(1.0*n);
        for(int i=0; i<pNum&&prime[i]<=sqr; i++){
            if(n%prime[i]==0){
                fac[num].x = i;
                fac[num].cnt = 0;
                while(n%prime[i]==0){
                    fac[num].cnt++;
                    n/=prime[i];
                }
                num++;
            }
            if(n==1) break;
        }
        ///n 不为1时，会有一个大于根号n的质因子
        if(n!=1){
            fac[num].x = n;
            fac[num].cnt = 1;
        }
        for(int i=0; i<num; i++){
            if(i>0) printf("*");
            printf("%d", fac[i].x);
            if(fac[i].cnt>1)
            printf("^%d", fac[i].cnt);
        }
    }
    return 0;
}
