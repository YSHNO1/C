#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;

int n;
char a[10];

stack<int> num;
stack<char> sign;
int all;
int main()
{
    cin>>n;
    getchar();
    for(int i=1;i<=n;i++)
    {

        gets(a);
        all=0;
    while(!num.empty())num.pop();
    while(!sign.empty())sign.pop();
    int j=0;
    while(j<strlen(a))
    {

        if(a[j]<='9'&&a[j]>='0')
        {
            num.push(a[j]-'0');
        }
        else
            if(a[j]=='+')
        {
            sign.push(a[j]);

        }
        else
            if(a[j]=='-')
        {
            sign.push('+');
            num.push((a[j+1]-'0')*(-1));
            j++;
        }
        else
            if(a[j]=='x')
        {
            int ans=num.top();
            num.pop();
            num.push(ans*(a[j+1]-'0'));
            j++;
        }
        else
        {
            int ans=num.top();
            num.pop();
            num.push(ans/(a[j+1]-'0'));
            j++;
        }
        j++;
    }

    while(!num.empty())
    {
        all+=num.top();
        num.pop();

    }


    if(all==24) printf("Yes\n");
		else printf("No\n");
}
    return 0;
}
