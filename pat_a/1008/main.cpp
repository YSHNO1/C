#include <stdio.h>

int main()
{
    int n, a1=0, a2=0, sum = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a1);
        if(a1 > a2) sum += 6*(a1-a2);
        if(a1 < a2) sum += 4*(a2-a1);
        a2 = a1;
    }
    sum += n*5;
    printf("%d\n", sum);
}
