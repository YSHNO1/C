#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int num;
    char name[20];
    char sex;
    int age;
}stu[20];

int main()
{
    int i, n;
    scanf("%d", &n);
    student *p = stu;
    for(i = 0; i < n; i++)
    {
        scanf("%d %s %c %d", &((p+i)->num), (p+i)->name, &((p+i)->sex), &((p+i)->age));
    }
    for(i = 0; i < n; i++)
    {
        printf("%d %s %c %d\n", (p+i)->num, (p+i)->name, (p+i)->sex, (p+i)->age);
    }
}
