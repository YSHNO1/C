#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[256];
    scanf("%s",s);
    int length = strlen(s);
    int i,flag=1;
    for(i=0;i < length;i++){
        if(s[i]!=s[length-1-i]) flag = 0;
    }
    if(flag == 1) printf("YES");
    else printf("NO");
}
