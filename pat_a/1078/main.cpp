#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int hashTable[10010], sizen;
bool isPrime(int num){
    if(num == 1) return false;
    for(int i=2; i <= (int)sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}
void insertn(int key){
    for(int step = 0; step < sizen; step++){
        int index = (key + step * step) % sizen;
        if(hashTable[index] == 0){
            hashTable[index] = 1;
            printf("%d", index % sizen);
            return ;
        }
    }
    printf("-");
}
int main()
{
    int n;
    scanf("%d %d", &sizen, &n);
    while(!isPrime(sizen)) sizen++;
    for(int i=0; i<n; i++){
        int key;
        scanf("%d", &key);
        if(i!=0) printf(" ");
        insertn(key);
    }
    return 0;
}
