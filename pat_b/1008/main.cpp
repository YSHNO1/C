#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n, m, a[110], temp;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        a[(i+m+1)%n] = temp;
    }
    printf("%d", a[0]);
    for(int i=1; i<n; i++){
        printf(" %d", a[i]);
    }
    return 0;
}
