#include <cstdio>
#include <string.h>
int main(){
    int  n, a, m, sum;
    scanf("%d", &n);
    while(n--){
        sum = 0;
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
        printf("\n");
    }
}
