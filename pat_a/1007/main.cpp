#include <stdio.h>

int main()
{
    int k, a[10001];
    scanf("%d", &k);
    int start = 0, end1 = k-1, sum=0, maxsum=0, temp1=0, temp2=0;//temp1和temp2暂存起始和结束位置
    for(int i=0; i<k; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<k; i++){
        if(sum >= 0){
            sum += a[i];
            temp2 = i;   //累加则结束位置更新
        }
        else {
            sum = a[i];  //sum小于0时前面的序列就没用了
            temp1 = temp2 = i;  //更新初始和结束位置
        }
        if(sum > maxsum || sum == 0 && end1 == k-1){
            maxsum = sum;
            start = temp1;
            end1 = temp2;
        }
    }
    printf("%d %d %d", maxsum, a[start], a[end1]);
}
