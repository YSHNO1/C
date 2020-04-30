#include <stdio.h>
#include <string.h>
int main(){
    char a[3][21], *p[3] = {a[0], a[1], a[2]}, *temp;
    for(int i = 0; i < 3; i++){
        gets(a[i]);
    }
    for(int i = 1; i < 3; i++){
        for(int j = 0; j < 3 - 1; j++)
            if(strcmp(p[j], p[j+1]) > 0){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
    }
    for(int i = 0; i < 3; i++){
        printf("%s\n", p[i]);
    }
}
