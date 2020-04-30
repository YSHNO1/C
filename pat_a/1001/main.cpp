#include <cstdio>

void print(int c){
    int flag = 0, i=0;
    char s[10];
    if(c < 0){
        flag = 1;
        c = -c;
    }
    while(c!=0){
        if((i+1)%4==0){
            s[i++] = ',';
        }
        else {
            s[i++] = c%10 + '0';
            c /= 10;
        }
    }
    if(flag == 1) s[i++] = '-';
    for(int j=i-1; j>=0; j--){
        printf("%c",s[j]);
    }
    printf("\n");
}

int main()
{
    int a, b, c;
    while(scanf("%d%d", &a, &b)!=EOF){
        c = a+b;
        print(c);
    }
    return 0;
}
