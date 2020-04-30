#include <stdio.h>
#include <stdlib.h>
int findX(int low, int high, int a[], int x){
    int mid;
    while(low<=high){
             mid = (low+high)/2;
            if(a[mid] > x){
                high = mid-1;
            }
            else if(a[mid] < x){
                low = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
}
int main()
{
    int n,a[210],x;
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        scanf("%d", &x);
        int answer = findX(0, n-1, a, x);
        printf("%d\n", answer);
    }
}
