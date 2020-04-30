#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long LL;
//ת�������ֵĺ���
int judge(char c){
    if(c >= '0' && c <= '9'){
        return c- '0';
    }
    else return c - 'a' + 10;
}
//��ĳ����ת��λ10����
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
    LL t, c, num = 0;  //tΪ���λ�� rλ����һ���Ľ���
    scanf("%s %s %lld %lld", a, b, &t, &c);
    int flag=0, p, q=2;  //p q�����жϴ�ȷ�����Ƶ�����������С
    if(t == 2) swap(a, b);
    //����֪���Ƶ�ת��Ϊʮ����
    for(int i=0; i<strlen(a); i++){
        num *= c;
        num += judge(a[i]);
    }
    for(int i=0; i<strlen(b); i++){
        q = max(q, judge(b[i]+1));
    }
    LL r = num + 1;
    //���ַ����ҽ���
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
