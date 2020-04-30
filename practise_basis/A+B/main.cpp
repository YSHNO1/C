#include <stdio.h>
#include <string.h>
int main(){
    char s1[20], s2[20];
    long long m , n;
    int len1, len2;
    while(scanf("%s%s", s1, s2) != EOF){
        m = 0;
        n = 0;
        len1 = strlen(s1);
        len2 = strlen(s2);
        for(int i = 0; i < len1; i++){
            if((s1[i] >= '0')&&(s1[i] <= '9')){
                m = m*10 + s1[i] - '0';
            }
        }
        if(s1[0] == '-') m = -m;
        for(int i = 0; i < len2; i++){
            if((s2[i] >= '0')&&(s2[i] <= '9')){
                n = n*10 + s2[i] - '0';
            }
        }
        if(s2[0] == '-') n = -n;
        printf("%lld\n", m + n);
    }
}
