#include<stdio.h>
int main(){
    int a[10],i,j,n;
    for(i = 0;i<10;i++)
        scanf("%d",&a[i]);
    n = i = 9;
    while(i>=1){
        if(a[i] == a[i-1]){
            if((i<n)&&(a[i]<a[i+1])||i==n)
                for(j=i+1;j<=n;j++) a[j-1] = a[j];
            n--;
        }
        i--;
    }
    for(i = 0; i<=n;i++){
        printf("%d",a[i]);
    }
}
