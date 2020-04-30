#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int num;
    char name[20];
    int grade1, grade2, grade3;
}stu[10];

int main()
{
    int i, k;
    double sum1 = 0, sum2 = 0, sum3 = 0;
    double average[10];
    for(i = 0; i < 10; i++)
    {
        scanf("%d %s %d %d %d", &(stu[i].num), stu[i].name, &(stu[i].grade1), &(stu[i].grade2), &(stu[i].grade3) );
    }
     for(i = 0; i < 10; i++){
            sum1 += stu[i].grade1;
            sum2 += stu[i].grade2;
            sum3 += stu[i].grade3;
            average[i] = (stu[i].grade1 + stu[i].grade2 + stu[i].grade3)/3;
    }
    double maxgrade = 0 ;
    for(i = 0; i < 10; i++){
        if(average[i] > maxgrade){
            maxgrade = average[i];
            k = i;
        }
    }
        printf("%.2f %.2f %.2f\n", sum1/10.0, sum2/10.0, sum3/10.0);
        printf("%d %s %d %d %d\n",stu[k].num, stu[k].name, stu[k].grade1, stu[k].grade2, stu[k].grade3);
}
