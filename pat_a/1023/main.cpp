#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int digit[10]; //记录某个数字出现的次数
int main()
{
    char num[21];
    scanf("%s", num);
    int len = strlen(num), flag = 0;//标记进位
    //从个位开始计算
    for(int i=len-1; i>=0; i--){
        int temp = num[i] - '0';
        digit[temp]++;
        temp = temp * 2 + flag;
        flag = 0;
        if(temp >= 10){
            temp = temp % 10;
            flag = 1;
        }
        num[i] = temp + '0';
        digit[temp]--;   //直接减去出现的数字
    }
    int check  = 0;
    for(int i=0; i<10; i++){
        if(digit[i] != 0){
            check = 1;
        }
    }
    if(check != 0 || flag == 1) printf("No\n");   //2倍的位数多了肯定不可能
    else printf("Yes\n");
    if(flag == 1) printf("1"); //需要输出2倍后多出的那一位
    printf("%s", num);
    return 0;
}
