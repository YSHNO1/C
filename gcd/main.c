/*辗转相除法gcd的思路：
求a和b的两个数的最大公约数：
1. 当b为0时，结束，a为最大公约数
2. 否则，计算a除以b的约数，令a为b，余数为b

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
