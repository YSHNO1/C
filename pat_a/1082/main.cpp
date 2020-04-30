#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string s[6] = {"ge", "shi", "bai", "qian", "wan", "yi"};
int main()
{
    int n;
    cin >> n;
    if(n == 0) cout << "zero" <<endl;
    if(n < 0){
        cout << "fu";
        n = -n;
    }
    int part[3];
    part[0] = n / 100000000; //亿
    part[1] = (n % 100000000) / 10000; // 万
    part[2] = n % 10000;
    bool zero = false; //判断是否需要输出0
    for(int i = 0; i < 3; i++){
        int temp = part[i];
        if
    }
}
