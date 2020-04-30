#include <cstdio>
#include <string.h>
int main(){
    int n, jsum, osum, m;
    while(scanf("%d", &n) != EOF){
        osum = 0;
        jsum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            if(m%2 == 0) osum++;
            else jsum++;
        }
        if(jsum < osum){
            printf("NO\n");
        }
        else printf("YES\n");
    }
}
