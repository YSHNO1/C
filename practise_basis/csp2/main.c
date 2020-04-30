#include <stdio.h>

int main()
{
    int n, num[4], sum = 0;
    char sigh[3];
    scanf("%d", &n);
    while(n--){
        scanf("%d%c%d%c%d%c%d",&num[0], sigh[0], &num[1], sigh[1], &num[2], sigh[2], &num[3]);
        int i;
        for(i = 0; i < 2; i++){
            if(sigh[i] == 'x'){
               num[i+1] = num[i] * num[i+1];
               num[i] = 0;
            }
            if(sigh[i] == '/')
               num[i+1] = num[i]/num[i+1];
               num[i] = 0;
        }
        for(i = 0; i < 2; i++){
            if(sigh[i] == '-') num[i+1] = -num[i+1];
        }
        for(i = 0; i < 3; i++){
            sum += num[i];
        }
        if(sum == 24) printf("Yes");
        else printf("No");
    }
    return 0;
}
