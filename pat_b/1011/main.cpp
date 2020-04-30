#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long int a, b, c;
    for(int i=0; i<n; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: %s\n", i + 1, a + b > c ? "true" : "false");
    }
    return 0;
}
