#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        //溢出情况 两个正数相加或者两个负数相加
        if(a > 0 && b > 0 && sum < 0){
            printf("Case #%d: true\n", i + 1);
        }
        else if(a < 0 && b < 0 && sum >= 0){
            printf("Case #%d: false\n", i + 1);
        }
        else if(sum > c){
             printf("Case #%d: true\n", i + 1);
        }
        else printf("Case #%d: false\n", i + 1);
    }
    return 0;
}
