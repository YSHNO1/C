#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[101];
    int i;
    while(gets(str)!=EOF){
        i=0;
        while(str[i]!='\0'){
        if((i==0)&&(str[i]<='z'&&str[i]>='a')){str[i] = str[i] - 32;i++;}
        else if((str[i]!=' ')||(str[i]!='\t')||(str[i]!='\n')||(str[i]!='\r'))
            ++i;
        else {
            ++i;
            if(str[i]<='z'&&str[i]>='a'){
            str[i] = str[i] - 32;
            ++i;
        }
        }
    }
     printf("%s",str);
}
}
