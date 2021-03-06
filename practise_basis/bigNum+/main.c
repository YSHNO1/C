#include <stdio.h>

#include <string.h>

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i=0;i<a.len; i++){
        a.d[i] = str[len-i-1] - '0';
    }
    return a;
}
bign add(bign a, bign b){
    bign c;
    int carry =0;
    for(int i=0; i<a.len||i<b.len; i++){
        int temp = a.d[i] +b.d[i] + carry;
        c.d[len++] = temp%10;
        carry = temp/10;
    }
    if(carry!=0){
        c.d[len++] = carry;
    }
    return c;
}
void print(bign c){
    for(int i=c.len-1; i>=0; i++){
        printf("%d". c.d[i]);
    }
}
int main()
{
    bign a, b;
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    a = change(str1);
    b = change(str2);
    print(add(a, b));
    return 0;
}
