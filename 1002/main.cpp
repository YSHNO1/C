#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char b[100] ;//´æ´¢ÊäÈëµÄÊı×Ö
    char pinyin[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int sum = 0, i;
    scanf("%s", &b);
    for(i = 0; b[i] != '\0'; i++){
        sum += b[i] - '0';
    }
    if(sum / 100)
        printf("%s ", pinyin[sum/100]);
    if(sum / 10)
        printf("%s ", pinyin[sum/10%10]);
    printf("%s", pinyin[sum%10]);
    return 0;
}
