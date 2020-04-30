#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
const int maxn = 100001;
using namespace std;
int c;
struct Student{
    int no, score;
    char name[10];
}s[maxn];
int cmp(Student a, Student b){
    if(c == 1){
        return a.no < b.no;
    }
    else if(c == 2){
        if(strcmp(a.name, b.name) == 0) return a.no < b.no;
        return strcmp(a.name , b.name) <= 0;
    }
    else {
        if(a.score == b.score) return a.no < b.no;
        return a.score <= b.score;
    }
}
int main()
{
    int n;
    scanf("%d%d", &n, &c);
    for(int i=0; i<n; i++){
        scanf("%d %s %d", &s[i].no, s[i].name, &s[i].score);
    }
    sort(s, s+n, cmp);
    for(int i=0; i<n; i++){
        printf("%06d %s %d\n", s[i].no, s[i].name, s[i].score);
    }
    return 0;
}
