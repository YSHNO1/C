#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int num = 0, countt = 0, countp = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'T') countt++;
    }
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'P') countp++;
        if(s[i] == 'T') countt--;
        if(s[i] == 'A') num = (num + (countp * countt)%1000000007)%1000000007;
    }
    cout << num;
    return 0;
}
