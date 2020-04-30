#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[201],c;
    int i;
    while(gets(s)){
        scanf("%c",&c);
        int len = strlen(s);
        for(i=0;i<len;i++){
            if(s[i]!=c)
                printf("%c",s[i]);
        }
        printf("\n");
        getchar();//Ïû³ý»»ÐÐ
    }
}
