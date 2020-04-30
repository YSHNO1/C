#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[101][21];
    int i,j,m;
    char str[21];
    scanf("%d", &m);
    for(i = 1; i <= m;i++){
        scanf("%s",str);
        if(i==1) strcpy(s[i],str);
        else{
             for(j = i; j > 0; j--){
                strcpy(s[j+1],s[j]);
            }
            strcpy(s[1],str);
        }
        for(j=1;j <= i;j++){
            printf("%d=%s ",j,s[j]);
            if(j==4) break;
        }
        printf("\n");
    }
}
