#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a[100001], num[100000];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        num[a[i]]++;
    }
    for(int i=0; i<n; i++){
        if(num[a[i]] == 1){
            printf("%d", a[i]);
            return 0;
        }
    }
    printf("None");
    return 0;

}
