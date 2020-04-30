#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    while(scanf("%s", a)!=EOF){
    int len = strlen(a);
    int side = (len + 2)/3;
    int bottom = len - 2*side;
    int flag;
    for(int i = 0; i < side-1; i++){
        printf("%c",a[i]);
        for(int j = 0;j < bottom; j++){
            printf(" ");
        }
        printf("%c\n", a[len-i-1]);
        flag = i;
    }
    printf("%c", a[flag+1]);
    for(int i = 0; i < side; i++){
        printf("%c", a[flag+2+i]);
    }
    printf("\n");
    }
    return 0;
}
