#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string female, male;
    int femaleScore = -1, maleScore = 101;
    for(int i=0; i<n; i++){
        string name, sex, num;
        int score;
        cin >> name >> sex >> num;
        scanf("%d", &score);
        if(sex == "F"){
            if(femaleScore< score){
                femaleScore = score;
                female = name + " " + num;
            }
        } else if(maleScore > score){
            maleScore = score;
            male = name + " " + num;
        }
    }
    if(femaleScore != -1)
        cout << female << endl;
    else printf("Absent\n");
    if(maleScore != 101)
        cout << male << endl;
    else printf("Absent\n");
    if(femaleScore !=-1 && maleScore != 101){
        printf("%d", femaleScore - maleScore);
    }
    else printf("NA");
    return 0;
}
