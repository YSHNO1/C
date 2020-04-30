#include <stdio.h>
#include <stdlib.h>
const int maxn=10010;
int Partition(int a[], int left, int right){
    int temp = a[left];
    while(left<right){
        while(left<right&&a[right]>temp) right--;
        a[left] = a[right];
        while(left<right&&a[left]<=temp) left++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}
void quickSort(int a[], int left, int right){
   if(left < right){
        int pos = Partition(a, left, right);
        quickSort(a, left, pos-1);
        quickSort(a, pos+1, right);
   }
}
int main()
{
    int n, a[maxn];
    scanf("%d", &n);
    for(int i =0; i< n; i++){
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
}
