#include <iostream>
#include <stdio.h>

using namespace std;
int book[201], a[10001], dp[10001];
int main()
{
    int n, m, l, num = 0, maxn = 0;
    int temp;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &temp);
        book[temp] = i;
    }
    scanf("%d", &l);
    for(int i=0; i<l; i++){
        scanf("%d", &temp);
        if(book[temp] >= 1){
            a[num++] = book[temp];
        }
    }
    for(int i=0; i<num; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
