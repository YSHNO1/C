/*շת�����gcd��˼·��
��a��b�������������Լ����
1. ��bΪ0ʱ��������aΪ���Լ��
2. ���򣬼���a����b��Լ������aΪb������Ϊb

*/
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int t;
    while(b != 0){
        t = a % b;
        a = b;
        b = t;
    }
    printf("gcd = %d", a);
    return 0;
}
