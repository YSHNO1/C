//�������������ÿһλ
#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    int cnt = 0; //����������λ��
    int mask = 1;
    int t = x;
    while(t > 9){
        t/=10;
        cnt++;
        mask *= 10;
    }
    do{
        int d = x / mask;
        printf("%d", d);
        if(mask > 9){
            printf(" ");
        }
        x %= mask;
        mask /= 10;
    }while(mask > 0);
    printf("\n");
    return 0;
}
