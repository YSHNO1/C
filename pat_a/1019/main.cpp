#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n, d;
    int a[40], i=0, flag=1;
    while(scanf("%d %d", &n, &d)!=EOF){

        while(n != 0){
            a[i++] = n%d;
            n /= d;
        }
        for(int j=0; j<i/2; j++){
            if(a[j] != a[i-1-j]){
                flag=0; break;
            }
        }
        if(flag==0) printf("No\n");
        else printf("Yes\n");
        for(int j=i-1; j>=0; j--){
            if(j!=0){
                 printf("%d ", a[j]);
            }
            else printf("%d\n", a[j]);
        }
    }
}
