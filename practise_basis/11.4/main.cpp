#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct {
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int clas;
        char position[10];
    }category;
}person[100];

int main()
{
    int i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %s %c %c", &(person[i].num), &(person[i].name), &(person[i].sex), &(person[i].job));
        if(person[i].job == 's'){
            scanf("%d", &(person[i].category.clas));
        }
        if(person[i].job == 't'){
            scanf("%s", person[i].category.position);
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d %s %c %c ",person[i].num, person[i].name, person[i].sex, person[i].job);
        if(person[i].job == 's'){
            printf("%d\n", person[i].category.clas);
        }
        if(person[i].job == 't'){
            printf("%s\n", person[i].category.position);
    }
}
}
