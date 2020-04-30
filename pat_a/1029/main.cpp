#include <iostream>
#include <stdio.h>

using namespace std;
const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], a3[maxn];
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a1[i]);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &a2[i]);
    }
    int i = 0, j = 0, index = 0;
    while(i < n && j < m){
        if(a1[i] <= a2[j]){
            a3[index++] = a1[i++];
        }
        else {
            a3[index++] = a2[j++];
        }
    }
    while(i < n) a3[index++] = a1[i++];
    while(j < m) a3[index++] = a2[j++];
    if(index % 2 == 0){
       printf("%d", a3[index/2-1]);
    }
    else printf("%d", a3[index/2]);
    return 0;
}
