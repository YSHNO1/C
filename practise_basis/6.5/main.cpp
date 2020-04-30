#include <stdio.h>
#include <string.h>
int main(){
    int a[10], i, temp;
    for(i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < 5; i ++){
        temp = a[i];
        a[i] = a[9-i];
        a[9-i] = temp;
    }
    for(i = 0; i < 10; i++){
        printf("%d\n", a[i]);
    }
}
