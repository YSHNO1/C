#include <stdio.h>
#include <string.h>

void judge(int *a, int *b){
    int temp;
    if(*b > *a){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}
int main(){
    int a, b;
    int *p1 = &a, *p2 = &b;
    scanf("%d%d", &a, &b);
    judge(p1, p2);
    printf("%d %d", *p1, *p2);
}
