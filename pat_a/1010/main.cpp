#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long LL;
//转换成数字的函数
int judge(char c){
    if(c >= '0' && c <= '9'){
        return c- '0';
    }
    else return c - 'a' + 10;
}
//将某进制转化位10进制
LL calculate(char s[], LL r){
    LL sum = 0;
    for(int i=0; i<strlen(s); i++){
        sum *= r;
        sum += judge(s[i]);
        if(sum < 0) return -1;
    }
    return sum;
}
int main()
{
    char a[11], b[11];
    LL t, c, num = 0;  //t为标记位， r位其中一个的进制
    scanf("%s %s %lld %lld", a, b, &t, &c);
    int flag=0, p, q=2;  //p q用来判断待确定进制的数的最大和最小
    if(t == 2) swap(a, b);
    //将已知进制的转化为十进制
    for(int i=0; i<strlen(a); i++){
        num *= c;
        num += judge(a[i]);
    }
    for(int i=0; i<strlen(b); i++){
        q = max(q, judge(b[i]+1));
    }
    LL r = num + 1;
    //二分法查找进制
    while(q <= r){
        LL mid = (q + r) / 2;
        LL sum = calculate(b, mid);
        if(sum == num){
            flag = mid; break;
        }
        else if(sum == -1 || sum > num) r = mid - 1;
        else q = mid + 1;
    }
    if(flag) printf("%d\n", flag);
    else printf("Impossible");
    return 0;
}
