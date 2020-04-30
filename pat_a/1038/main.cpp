#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
//Ì°ÐÄ
bool cmp(string a, string b){
    return a + b < b + a;
}
string str[10001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string s;
    for(int i=0; i<n; i++){
        s += str[i];
    }
    while(s.length()!=0 && s[0] == '0'){
        s.erase(s.begin());
    }
    if(s.length() == 0) printf("0");
    cout << s;
    return 0;

}
