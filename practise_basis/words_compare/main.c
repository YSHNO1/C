#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    char sa[101];
    char sb[101];
    scanf("%d",&n);
    while(n--){
        scanf("%s %s",sa,sb);
        if(strlen(sa)>strlen(sb)) printf("%s is longer than %s\n",sa,sb);
        else if(strlen(sa)==strlen(sb)) printf("%s is equal long to %s\n",sa,sb);
        else printf("%s is shorter than %s\n",sa,sb);
    }
}
