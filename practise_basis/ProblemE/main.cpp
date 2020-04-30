#include <stdio.h>
const int N = 100010;
int main(){
    int n, m, start, stop, total = 0, len;
    int a[N];
    scanf("%d", &n);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        total += a[i];
    }
    scanf("%d", &m);
    while(m--){
        len = 0;
        scanf("%d%d", &start, &stop);
        if(start > stop) {
            int temp = start;
            start = stop;
            stop = temp;
        }
        for(int i = start; i < stop; i++){
            len += a[i];
        }
        if(len < (total - len)) printf("%d\n", len);
        else printf("%d\n", total - len);
    }
}
