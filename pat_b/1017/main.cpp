#include <iostream>

using namespace std;
int main()
{
    string s;
    int b;
    cin >> s >> b;
    int t = 0, temp = 0;
    t = (s[0] - '0') / b;
    if(t != 0 && s.length() > 1 || s.length() == 1)
        cout << t;
    temp = (s[0] - '0') % b;
    for(int i=1; i<s.length(); i++){
        t = (temp * 10 + s[i] - '0') / b;
        cout << t;
        temp = (temp * 10 + s[i] - '0') % b;
    }
    cout << " " << temp;
    return 0;
}
