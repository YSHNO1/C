#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int n, changeNum = 0, flag = 0;
    vector<string> v;
    string name , s;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        flag = 0;
        cin >> name >> s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '1'){
                s[j] = '@';
                flag = 1;
            }
            if(s[j] == '0'){
                s[j] = '%';
                flag = 1;
            }
            if(s[j] == 'l'){
                s[j] = 'L';
                flag = 1;
            }
            if(s[j] == 'O'){
                s[j] ='o';
                flag = 1;
            }
        }
        if(flag == 1) {
            string temp = name + " " + s;
            v.push_back(temp);
            changeNum++;
        }
    }
    if(changeNum != 0) {
        printf("%d\n", changeNum);
        for(int i=0; i<changeNum; i++)
            cout << v[i] <<endl;
    }
    else if(n==1) printf("There is 1 account and no account is modified");
    else printf("There are %d accounts and no account is modified", n);
    return 0;
}
