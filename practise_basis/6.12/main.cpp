#include <stdio.h>
#include <string.h>
int main(){
    char a[20];
    int i = 0;
    gets(a);
    while(a[i] != '\0'){
        if(a[i] >= 'a' && a[i] <= 'z'){
            a[i] = 'a' + 'z' - a[i];
        }
        else if(a[i] >= 'A' && a[i] <= 'Z'){
             a[i] = 'A' + 'Z' - a[i];
        }
        printf("%c", a[i]);
        i++;
    }
}
