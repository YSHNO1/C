#include <stdio.h>
#include <stdlib.h>

int record[5000];
//求过程数的函数
void find(int num){
    if(record[num]){
        return;   //如果这一位被标记为1，代表已经判断过了，直接返回。
    }
    while(num != 1){
        if(num%2){
            num = (3 * num + 1) / 2;
        }
        else
            num /= 2;
        record[num]  = 1;
    }
}

int main()
{
    int n, num, array[101] = {0};
    scanf("%d",&n);
    while(n--){
        scanf("%d", &num);
        find(num);
        array[num] = 1;
    }
    int flag = 0;
    for(int i = 100; i > 0; i--){
        if(array[i] && record[i] == 0 && flag == 0){
            printf("%d ", i);
            flag = 1;
        }
        else if(array[i] && record[i] == 0){
            printf("%d", i);
        }
    }
    return 0;
}
