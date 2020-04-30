#include <stdio.h>
#include <string.h>
#define maxn 105
int main(){
    char num[maxn];
    char change[][10] = {"zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine"};
    int len = 0, sum = 0;
    int finalNum[5];
    scanf("%s", num);
    for(int i=0; i<strlen(num); i++){
        sum += (num[i] - '0');
    }
    if(sum == 0)
        printf("zero\n");
    else{
        while(sum!=0){
            finalNum[len++] = sum%10;
            sum /= 10;
        }
        for(int i=len-1; i>0; i--){
            printf("%s ", change[finalNum[i]]);
        }
        printf("%s\n", change[finalNum[0]]);
    }
}
