//水仙花数，给定一个N位正整数，使得他每个位上的数字的N次幂的和等于他本身，这样的数字称为水仙花数
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    //先锁定需要判断的数字的范围，比如N=为3时，则应该判断100-999
    int first = 1;
    int i = 1;
    while(i < n){
        first *= 10;
        i++;
    }
    //遍历给定的范围的数字，逐个判断其是否符合条件
    i = first;
    while(i < first*10){
        int t = i;
        int sum = 0;
        do{
            int  d = t%10;   //取每一位
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
