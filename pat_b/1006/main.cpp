#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n, bai = -1, shi = -1, ge = -1;
    scanf("%d", &n);
    if(n >= 100){
        bai = n / 100;
        shi = n % 100 / 10;
        ge = n % 10;
    }
    else if(n >= 10){
        shi = n / 10;
        ge = n % 10;
    }
    else ge = n;
    if(bai != -1){
        for(int i=0; i<bai; i++){
            printf("B");
        }
    }
    if(shi != -1){
        for(int i=0; i<shi; i++){
            printf("S");
        }
    }
    for(int i=0; i<ge; i++){
        printf("%d", i+1);
    }

    return 0;
}
