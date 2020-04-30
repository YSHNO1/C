#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[101];
    int i;
    while(gets(str)){
        i = 0;
        while (str[i]!='\0'){
            if(i==0&&str[i]>='a'&&str[i]<='z'){
                str[i] -= 32;
                i++;
            }
            else if(str[i]!=' '&&str[i]!='\n'&&str[i]!='\t'&&str[i]!='\r'){
                ++i;
            }
            else {
                ++i;
                if(str[i]>='a'&&str[i]<='z')
                    str[i] -= 32;
                ++i;
            }
        }
        puts(str);
    }
}
