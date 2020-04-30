#include <stdio.h>
#include <string.h>

int main(){
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    int result;
    int i = 0;
    while((s1[i] == s2[i]) && s1[i] != '\0'){
        i++;
    }
    if((s1[i] == 0) && (s2[i] == 0)){
        result = 0;
    }
    else{
        result = s1[i] - s2[i];
    }
    printf("%d", result);
}
