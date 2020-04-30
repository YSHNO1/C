#include <stdio.h>
#include <string.h>

int main(){
    int a[3], *b[3];
    for( int i = 0; i < 3; i++){
        scanf("%d",&a[i]);
        b[i] = &a[i];
    }
    for(int i = 1;i < 3; i++){
        for(int j = 0; j < 3 - i; j++){
            if(*b[j] < *b[j+1]){
                int temp = *b[j];
                *b[j] = *b[j+1];
                *b[j+1] = temp;
            }
        }
    }
    for( int i = 0; i < 3; i++){
        printf("%d ",*b[i]);
    }
}
