#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct node{
    double num;
    char op;
    bool flag;
};
string str;
stack<node> s;
queue<node> q;
map<char, int> op;

//中缀转后缀
void Change(){
    double num;
    node temp;
    for(int i=0; i<str.length();){
        if(str[i]>='0'&&str[i]<='9'){
            temp.flag = true;  //标记该位为数字
            temp.num = str[i++] - '0'; //记录操作数
            //处理多位数
            while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
                   temp.num = temp.num*10+(str[i]-'0');
            }
            q.push(temp);
        }
        else {
            temp.flag = false;
            while(!s.empty()&&op[str[i]]<=op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
//计算后缀表达式
double Cal(){
    double temp1, temp2;
    node cur, temp;    //temp用于临时记录操作数
    while(!q.empty()){
        cur = q.front();   //记录队首元素
        q.pop();
        if(cur.flag == true) s.push(cur);
        else {
            temp2 = s.top().num;
            s.pop();
            temp.flag = true;
            if(cur.op == '+') temp.num = temp1+temp2;
            else if(cur.op == '-') temp.num = temp1 - temp2;
            else if(cur.op == '*') temp.num = temp1*temp2;
            else temp.num = temp1/ temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin, str), str!= "0"){
        for(string::iterator it = str.end(); it!=str.begin(); it--){
            if(*it == ' ') str.erase(it); //去除表达式中的空格
        }
        while(!s.empty()) s.pop();  //初始化一个栈
        Change();
        printf("%.2f\n", Cal());  //计算后缀表达式
    }
    return 0;
}
