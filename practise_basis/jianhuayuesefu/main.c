#include <stdio.h>
#include <stdlib.h>

int f(int n, int m){
    return n == 1 ? n : (f(n-1, m) + m - 1) % n + 1;
}
int main()
{
    int m,n;///n为人数，m为报到几出列
    while(scanf("%d %d",&n, &m)){
        printf("%d\n",f(n, m));
    }
}

