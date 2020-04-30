#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, a[81];
    scanf("%d", &n);
    while(n--){
        scanf("%d", &k);
        for(int i=0; i<k; i++){
            scanf("%d", &a[i]);
        }
        printf("0 ");
        for(int j=1; j<k-1; j++){
            if((a[j]>a[j+1]&&a[j]>a[j-1])||(a[j]<a[j+1]&&a[j]<a[j-1])){
                printf("%d ",j);
            }
        }
        printf("%d\n", k-1);
    }
}
