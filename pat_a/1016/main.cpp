#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int rate[25];
int n;
struct Customer{
    string name;
    int month, day, hour, minute;
    int status;
    int time;
}c[1010];

bool cmp(Customer c1, Customer c2){
    return c1.name != c2.name ? c1.name < c2.name : c1.time < c2.time;
}
//将时间转换为分钟
int convert(Customer c){
    return (c.day * 24 * 60) + (c.hour * 60) + c.minute;
}
//计算从当天零点到某个时间的花费
double calculate(Customer c){
    double sum = 0;
    sum += rate[c.hour]*c.minute;
    sum += rate[24] * c.day * 60;
    for(int i=0; i<c.hour; i++){
        sum += rate[i] * 60;
    }
    return sum;
}
//计算费用
double getfee(Customer c1, Customer c2){
    printf("%02d:%02d:%02d %02d:%02d:%02d %d ", c1.day, c1.hour, c1.minute, c2.day, c2.hour, c2.minute, c2.time - c1.time);
    return calculate(c2) - calculate(c1);
}
int main()
{
    rate[24] = 0;
    for(int i=0; i<24; i++){
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin>>c[i].name;
        scanf("%d:%d:%d:%d", &c[i].month, &c[i].day, &c[i].hour, &c[i].minute);
        string temp;
        cin>>temp;
        c[i].status = temp == "on-line" ? 1 : 0;
        c[i].time = 0;
        c[i].time += convert(c[i]);
    }
    sort(c, c+n, cmp);
    map<string, vector<Customer> > records;
    for(int i=1; i<n; i++){
        if(c[i].name == c[i-1].name && c[i].status == 0 && c[i-1].status == 1){
            records[c[i].name].push_back(c[i-1]);
            records[c[i].name].push_back(c[i]);
        }
    }
    //遍历输出
    map<string, vector<Customer> >::iterator it;
    for(it = records.begin(); it != records.end(); it++){
        double totl = 0;
        cout <<it->first;
        vector<Customer> temp = it->second;
        printf(" %02d\n", temp[0].month);
        for(int i=0; i<temp.size(); i+=2){
            double subtol = getfee(temp[i], temp[i+1]);
            totl += subtol;
            printf("$%.2lf\n", subtol/100.0);
        }
        printf("Total amount: $%.2lf\n", totl/100.0);
    }
    return 0;
}
