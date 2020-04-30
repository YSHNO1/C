#include <cstdio>
#include <string.h>
int main(){
    char a[11], b[11];
    int da, db, pa = 0, pb = 0;
    scanf("%s%d%s%d", a, &da, b, &db);
    for(int i = 0; i < strlen(a); i++){
        if(da == a[i]-'0'){
            pa = pa*10 + da;
        }
    }
    for(int i = 0; i < strlen(b); i++){
        if(db == b[i]-'0'){
            pb = pb*10 + db;
        }
    }
    printf("%d", pa+pb);

}
