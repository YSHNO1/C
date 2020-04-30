#include <stdio.h>
#include <stdlib.h>
const int maxn = 10010;
void merge(int a[], int L1, int R1, int L2, int R2){
    int i=L1, j=L2;
    int temp[maxn], index = 0;
    while(i<=R1&&j<=R2){
        if(a[i]<=a[j]){
            temp[index++] = a[i++];
        }
        else temp[index++] = a[j++];
    }
    while(i<=R1){
        temp[index++] = a[i++];
    }
    while(j<=R2){
        temp[index++] = a[j++];
    }
    for(int i = 0; i < index; i++){
        a[L1+i] = temp[i];
    }
}
void mergeSort(int a[], int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a,left, mid, mid+1, right);
    }
}

int main()
{
    int n, a[maxn];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n-1);
    for(int i=0; i < n; i++){
        printf("%d\n", a[i]);
    }
}
