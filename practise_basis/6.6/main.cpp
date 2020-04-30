#include <stdio.h>
#include <string.h>
int main(){
    int n, i, j, a[10][10] = {0};
    scanf("%d", &n);
    a[0][0] = 1;
    for(i = 1; i < n; i++){
        for(j = 0; j <= i; j++){
            a[i][0] = 1;
            a[i][j] = a[i-1][j]+a[i-1][j-1];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
            printf("%d ",a[i][j]);
            printf("\n");
}
}
