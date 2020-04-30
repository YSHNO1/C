#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100010;
int main(){
    int n;
    char s, t;
    int awin = 0, bwin = 0;
    int a[3] = {0}, b[3] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> s >> t;
        if (s == 'B' && t == 'C'){
            awin++;
            a[0]++;
        }else if(s == 'B' && t == 'J'){
            bwin++;
            b[2]++;
        }else if (s == 'C' && t == 'B') {
            bwin++;
            b[0]++;
        }else if(s == 'C' && t == 'J'){
            awin++;
            a[1]++;
        }else if(s == 'J' && t == 'B'){
            awin++;
            a[2]++;
        }else if(s == 'J' && t == 'C'){
            bwin++;
            b[1]++;
        }
    }
    printf("%d %d %d\n", awin, n-awin-bwin, bwin);
    printf("%d %d %d\n", bwin, n-awin-bwin, awin);
    int maxa = a[0] >= a[1] ? 0 : 1;
    maxa = a[maxa] >= a[2] ? maxa : 2;
    int maxb = b[0] >= b[1] ? 0 : 1;
    maxb = b[maxb] >= b[2] ? maxb : 2;
    char str[4] = {"BCJ"};
    printf("%c %c\n", str[maxa], str[maxb]);
}
