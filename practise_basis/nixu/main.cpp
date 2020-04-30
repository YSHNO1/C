#include <stdio.h>
#include <string.h>
int i = 0;
int fanxu(char str[100]){
    int len = strlen(str);
    for(i = 0; i < len/2; i++){
            char temp;
            temp = str[i];
            str[i] = str[len-1-i];
            str[len-1-i] = temp;
    }
}
int main(){
    char a[100];
	gets(a);
 	fanxu(a);
 	puts(a);
 	return 0;
}

