#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n, a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    double a4 = 0;
    scanf("%d", &n);
    int flag = 1, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        switch(temp%5){
            case 0 : if(temp%2 == 0) {a1 += temp; n1++;}break;
            case 1 : a2 = a2 + temp * flag; flag = -flag; n2++; break;
            case 2 : a3++, n3++; break;
            case 3 : a4 += temp;  n4++; break;
            case 4 : if(temp > a5) {a5 = temp; n5++;}
        }
    }
    if(n1 == 0) printf("N "); else printf("%d ", a1);
    if(n2 == 0) printf("N "); else printf("%d ", a2);
    if(n3 == 0) printf("N "); else printf("%d ", a3);
    if(n4 == 0) printf("N "); else printf("%.1f ", (a4*1.0)/(n4*1.0) );
    if(n5 == 0) printf("N"); else printf("%d", a5);
    return 0;
}
