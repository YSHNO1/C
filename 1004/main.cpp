#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct student{
    char name[15];
    char IDnumber[100];
    int score;
};
typedef struct student student;

int main()
{
    int n;
    scanf("%d", &n);
    student max = {"","",0},min = {"","",100};
    while(n--){
        student new;
        scanf("%s%s%d",new.name,new.IDnumber,&new.score);
        if(new.score>max.score)
            max = new;
        if(new.score<min.score)
            min = new;
    }
    printf("%s %s\n",max.name,max.IDnumber);
    printf("%s %s\n",min.name,min.IDnumber);
    return 0;
}
