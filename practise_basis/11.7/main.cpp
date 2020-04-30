#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int num;
    char name[20];
    int grade1, grade2, grade3;
}stu[5];

void input(){
    int i;
    for(i = 0; i < 5; i++)
    {
        scanf("%d %s %d %d %d", &(stu[i].num), stu[i].name, &(stu[i].grade1), &(stu[i].grade2), &(stu[i].grade3) );
    }
}
void output(){
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%d %s %d %d %d\n", stu[i].num, stu[i].name, stu[i].grade1, stu[i].grade2, stu[i].grade3);
    }
}
int main()
{
    input();
    output();
}
