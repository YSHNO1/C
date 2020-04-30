#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
//堆排序的向下调整
void downAdjust(int b[], int low, int high){
    int i = 1, j = i * 2;
    while(j <= high){
        if(j + 1 <= high && b[j] < b[j + 1]) j = j + 1;
        if(b[i] >= b[j]) break;
        swap(b[i], b[j]);
        i = j; j = i*2;
    }
}
int main()
{
    int n, a[101], b[101], i, j;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(i = 2; i <= n && b[i-1] < b[i]; i++);
    for(j = i; j <= n && a[j] == b[j]; j++);
    if(j == n + 1){
        cout << "Insertion Sort" << endl;
        sort(b+1, b+i+1);
    }
    else{
        cout << "Heap Sort" << endl;
        j = n;
        while(j > 2 && b[j] >= b[1]) j--;
        swap(b[1], b[j]);
        downAdjust(b, 1, j-1);
    }
    printf("%d", b[1]);
    for(int i = 2; i <= n; i++){
        printf(" %d", b[i]);
    }
}
