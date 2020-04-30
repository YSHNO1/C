#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
string s;
int k;
void add(string t){
    int len = s.length(), flag = 0;
    for(int i=0; i<len; i++){
        s[i] = s[i] + t[i] + flag - '0';
        flag = 0;
        if(s[i] > '9'){
            s[i] = s[i] - 10;
            flag = 1;
        }
    }
    if(flag == 1) s += '1';
    reverse(s.begin(), s.end());
}
int main()
{
    int i;
    cin >> s >> k;
    for(i=0; i<k; i++){
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t || i == k) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}
