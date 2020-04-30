#include<stdio.h>
#include<string.h>

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len=0;
    }
};

bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i=0; i<a.len; i++){
        a.d[i] = str[a.len-i-1] - '0';
    }
    return a;
}

bign sub(bign a, bign b){
    bign c;
    for(int i=0; i<a.len||i<b.len;i++){
        if(a.d[i]<b.d[i]){
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len-1>=1&&c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}
bool cmp(bign a, bign b){
    if(a.len > b.len) return true;
    else if(a.len == b.len){
        for(int i=a.len-1; i>0; i--){
            if(a.d[i]!=b.d[i]){
                if(a.d[i]>b.d[i])
                    return true;
                    else return false;
            }
        }
    }
    else return false;
}
void print(bign c){
    for(int i=c.len-1; i>=0; i--){
        printf("%d", c.d[i]);
    }
}
int main(){
    char str1[1000], str2[1000];
    bign a, b;
    scanf("%s%s", str1, str2);
    a = change(str1);
    b = change(str2);
    if(cmp(a,b)==true){
        print(sub(a,b));
    }
    else {
        printf("-");
        print(sub(b,a));
    }

}
