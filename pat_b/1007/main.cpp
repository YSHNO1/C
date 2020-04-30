#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<=(int)sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    int n, num=0;
    scanf("%d",&n);
    for(int i=5; i<=n; i++){
        if(isPrime(i)&&isPrime(i-2)) num++;
    }
    printf("%d", num);
    return 0;
}
