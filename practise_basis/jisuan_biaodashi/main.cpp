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

//��׺ת��׺
void Change(){
    double num;
    node temp;
    for(int i=0; i<str.length();){
        if(str[i]>='0'&&str[i]<='9'){
            temp.flag = true;  //��Ǹ�λΪ����
            temp.num = str[i++] - '0'; //��¼������
            //�����λ��
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
//�����׺���ʽ
double Cal(){
    double temp1, temp2;
    node cur, temp;    //temp������ʱ��¼������
    while(!q.empty()){
        cur = q.front();   //��¼����Ԫ��
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
            if(*it == ' ') str.erase(it); //ȥ�����ʽ�еĿո�
        }
        while(!s.empty()) s.pop();  //��ʼ��һ��ջ
        Change();
        printf("%.2f\n", Cal());  //�����׺���ʽ
    }
    return 0;
}
