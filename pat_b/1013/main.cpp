#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<=(int)sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}
int main()
{
    int n, m, num=0, prime = 2;
    scanf("%d %d", &n, &m);
    vector<int> v;
    while(num < m){
        if(isPrime(prime)){
            num ++;
            if(num >= n) v.push_back(prime);
        }
        prime++;
    }
    num = 0;
    for(int i=0; i<v.size(); i++){
        num++;
        if(num % 10 != 1) printf(" ");
        printf("%d", v[i]);
        if(num%10 == 0) printf("\n");
    }
    return 0;
}
