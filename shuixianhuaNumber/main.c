//ˮ�ɻ���������һ��Nλ��������ʹ����ÿ��λ�ϵ����ֵ�N���ݵĺ͵������������������ֳ�Ϊˮ�ɻ���
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    //��������Ҫ�жϵ����ֵķ�Χ������N=Ϊ3ʱ����Ӧ���ж�100-999
    int first = 1;
    int i = 1;
    while(i < n){
        first *= 10;
        i++;
    }
    //���������ķ�Χ�����֣�����ж����Ƿ��������
    i = first;
    while(i < first*10){
        int t = i;
        int sum = 0;
        do{
            int  d = t%10;   //ȡÿһλ
            t /= 10;
            int p = d;
            int j = 1;
            while(j < n){
                p *= d;
                j++;
            }
            sum += p;
        }while(t > 0);
        if(sum == i){
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}
