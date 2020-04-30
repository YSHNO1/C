#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp(int a, int b){
    return strcmp(name[a], name[b]) < 0;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j=0; j<cnt; j++){
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }
    for(int i=1; i<=k; i++){
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j=0; j<course[i].size(); j++){
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}