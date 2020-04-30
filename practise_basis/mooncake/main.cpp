#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct mooncake{
    double store;
    double sellPrice;
    double price;
}cake[1010];

bool cmp(mooncake a, mooncake b){
    return a.price > b.price;
}
int main()
{
    int n, needs;
    scanf("%d", &n);
    scanf("%d", &needs);
    for(int i=0; i<n; i++){
        scanf("%lf", &cake[i].store);
    }
    for(int i=0; i<n; i++){
        scanf("%lf", &cake[i].sellPrice);
        cake[i].price = cake[i].sellPrice/cake[i].store;
    }
    sort(cake, cake+n, cmp);
    double ans = 0;
    for(int i=0; i<n; i++){
        if(cake[i].store <= needs){
            needs = needs - cake[i].store;
            ans+=cake[i].sellPrice;
        }
        else {ans += cake[i].price*needs;
        break;
        }
    }
    printf("%.2f\n",ans);
}
