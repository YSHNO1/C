#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string earth[13] = {"####", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string mars[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

//10进制转13进制
void translate(string s){
    int num = 0, shang = 0, yushu = 0;
    for(int i=0; i<s.length(); i++){
        num = num*10 + s[i] - '0';
    }
    if(num < 13){
        cout<<earth[num]<<endl;
    }
    else {
        shang = num/13;
        yushu = num%13;
        if(yushu != 0){
            cout<<mars[shang]<<" "<<earth[yushu]<<endl;
        }
        else cout<<mars[shang]<<endl;
    }
}
//火星文转数字
void translate2(string s){
    int n1=0, n2=0;
    string s3, s4;
    s3 = s.substr(0, 3);
    if(s.length() > 3){
        s4 = s.substr(4, 3);
    }
    for(int i=0; i<13; i++){
        if(s3 == mars[i]) n1 = i;
        if(s3 == earth[i]||s4 == earth[i]) n2 = i;
    }
    printf("%d\n", n1*13 + n2);
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    string s;
    for(int i=0; i<n; i++){
        getline(cin, s);
        if(s[0] <= '9' && s[0] >= '0'){
            translate(s);
        }
        else translate2(s);
    }
    return 0;
}
