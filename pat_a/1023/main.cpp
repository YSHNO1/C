#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int digit[10]; //��¼ĳ�����ֳ��ֵĴ���
int main()
{
    char num[21];
    scanf("%s", num);
    int len = strlen(num), flag = 0;//��ǽ�λ
    //�Ӹ�λ��ʼ����
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
        digit[temp]--;   //ֱ�Ӽ�ȥ���ֵ�����
    }
    int check  = 0;
    for(int i=0; i<10; i++){
        if(digit[i] != 0){
            check = 1;
        }
    }
    if(check != 0 || flag == 1) printf("No\n");   //2����λ�����˿϶�������
    else printf("Yes\n");
    if(flag == 1) printf("1"); //��Ҫ���2����������һλ
    printf("%s", num);
    return 0;
}
