#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   char s[101][101];
   char s1[101];
   char s2[101];
   char ch;
   int op=0,oq=0,i;
   while(scanf("%c",&ch)&&ch!='\n'){
        if(ch == ' '){
            oq = 0;
            op++;
        }
        else s[op][oq++] = ch;
   }
   gets(s1);
   gets(s2);
   for(i = 0; i <= op;i++){
        if(strcmp(s[i],s1)==0) strcpy(s[i],s2);
   }
   for(i = 0; i <= op; i++){
      i?printf(" %s",s[i]):printf("%s",s[i]);
   }
}
