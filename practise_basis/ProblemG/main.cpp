#include <cstdio>
#include <math.h>
int main(){
    int n, m;
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    int a4 = 0, counta4 = 0;;
    scanf("%d", &n);
    bool exitA1 = false, exitA2 = false;
    for(int i = 0,j = 0; i < n; i++){
        scanf("%d", &m);
        if(m % 5 == 0){
            if(m % 2 == 0){
                exitA1 = true;
                a1 += m;
            }
        }
        else if(m % 5 == 1){
            exitA2 = true;
            a2 += m * pow((double)(-1),j);
            j++;
        }
        else if(m % 5 == 2){
            a3++;
        }
        else if(m % 5 == 3){
             a4 += m;
             counta4++;
        }
        else{
            if(m > a5) a5 = m;
        }
    }
     if(exitA1) printf("%d ", a1);
        else printf("%c ", 'N');
        if(exitA2) printf("%d ", a2);
        else printf("%c ", 'N');
        if(a3 != 0) printf("%d ", a3);
        else printf("%c ", 'N');
        if(counta4 != 0) printf("%.1f ", double(a4)/counta4);
        else printf("%c ", 'N');
        if(a5 != 0) printf("%d\n", a5);
        else printf("%c\n", 'N');
}
