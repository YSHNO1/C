#include <stdio.h>

int main()
{
    int k, a[10001];
    scanf("%d", &k);
    int start = 0, end1 = k-1, sum=0, maxsum=0, temp1=0, temp2=0;//temp1��temp2�ݴ���ʼ�ͽ���λ��
    for(int i=0; i<k; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<k; i++){
        if(sum >= 0){
            sum += a[i];
            temp2 = i;   //�ۼ������λ�ø���
        }
        else {
            sum = a[i];  //sumС��0ʱǰ������о�û����
            temp1 = temp2 = i;  //���³�ʼ�ͽ���λ��
        }
        if(sum > maxsum || sum == 0 && end1 == k-1){
            maxsum = sum;
            start = temp1;
            end1 = temp2;
        }
    }
    printf("%d %d %d", maxsum, a[start], a[end1]);
}
