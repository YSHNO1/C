#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Student{
    long long int id;
    int score, finrank, local, localrank;
};
bool cmp(Student a, Student b){
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int main()
{
    int n, k;  //n个考场, 考场人数k
    scanf("%d", &n);
    vector<Student> fin;
    for(int i=1; i<=n; i++){
        scanf("%d", &k);
        vector<Student> v(k);
        for(int j=0; j<k; j++){
            scanf("%lld %d", &v[j].id, &v[j].score);
            v[j].local = i;  //考场号
        }
        sort(v.begin(), v.end(), cmp);
        v[0].localrank = 1;
        fin.push_back(v[0]);
        for(int j=1; j<k; j++){
            if(v[j].score == v[j-1].score)
                v[j].localrank = v[j-1].localrank;
            else v[j].localrank = j + 1;
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp);
    fin[0].finrank = 1;
    for(int j=1; j<fin.size(); j++){
        if(fin[j].score  == fin[j-1].score)
            fin[j].finrank = fin[j-1].finrank;
        else fin[j].finrank = j + 1;
    }
    printf("%d\n", fin.size());
    for(int i=0; i<fin.size(); i++){
        printf("%013lld %d %d %d\n", fin[i].id, fin[i].finrank, fin[i].local, fin[i].localrank);
    }
}
