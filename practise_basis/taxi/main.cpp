#include <stdio.h>
const double eps = 1e-6;
int main()
{
    int n;
    double sum = 0.0;
    while(scanf("%d",&n) != EOF)
    {
        sum = 0.0;
        if(n == 0)
        break;
        if(n <= 4)
        {
            sum    = 10.0;
        }else
        if(n > 4&&n <= 8)
        {
            sum = 10 + 2 * (n - 4);
        }else
        if(n > 8)
        {
            while(n > 8)
            {
                sum += 18 ;
                n -= 8;
            }
            if(n <= 4)
            {
                sum += 2.4 * n;
            }else
            {
                sum += 10 + (n - 4) * 2;
            }
        }
        int temp = (int)sum;
        if(sum - temp < eps)
        {
            printf("%d\n",temp);
        }else
        printf("%.1lf\n",sum);
    }
    return 0;
}
