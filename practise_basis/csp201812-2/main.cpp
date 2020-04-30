#include <iostream>
#include <stdio.h>
#define MAXIZE 100000
using namespace std;

int main()
{
    int r, y, j, n, a[MAXIZE], b[MAXIZE], sum=0;
    scanf("%d%d%d", &r, &y, &j);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &a[i], &b[i]);
        if(a[i] == 0) sum+=b[i];
        if(a[i] == 1) {
            if(sum > b[i]){

            }
        }
    }
    printf("%d", sum);
    return 0;
}
