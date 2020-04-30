#include <stdio.h>
#include <string.h>
void vowels(char s1[], char s2[]){
    int len = strlen(s1);
    int i = 0, j=0;
    for(i = 0; i < len; i++){
       if (s1[i]=='a'||s1[i]=='A')
            s2[j++]=s1[i];
        else if (s1[i]=='e'||s1[i]=='E')
            s2[j++]=s1[i];
        else if (s1[i]=='i'||s1[i]=='I')
            s2[j++]=s1[i];
        else if (s1[i]=='o'||s1[i]=='O')
            s2[j++]=s1[i];
        else if (s1[i]=='u'||s1[i]=='U')
            s2[j++]=s1[i];
    }
    s2[j] = '\0';
}
int main(){
    char a[20], b[20];
    gets(a);
    vowels(a,b);
    puts(b);
}
