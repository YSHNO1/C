#include <stdio.h>
#include <string.h>
const int L = 10010;
int a[L];
int main(){
    int l, m, start, stop, sum;
    while(scanf("%d%d", &l, &m) != EOF){
        if(l == 0 || m == 0) break;
        sum = 0;
        memset(a, 0, l+1);
        for(int i = 0; i < m; i++){
             scanf("%d%d", &start, &stop);
             for(int j = start; j <= stop; j++){
                a[j] = 1;
             }
        }
        for(int i = 0; i < l+1; i++){
            if(a[i] == 0) sum++;
        }
        printf("%d\n", sum);
    }
}
