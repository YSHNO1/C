#include <cstdio>
#include <string.h>
const int N = 21;
struct student{
    int id;
    char name[200];
    char sex[20];
    int age;
}stu[N];
int main(){
    int n, m, temp;
    scanf("%d", &m);
    while(m--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%s%s%d", &(stu[i].id), stu[i].name,stu[i].sex, &(stu[i].age));
        }
            scanf("%d", &temp);
            for(int j = 0; j < n; j++){
            if(stu[j].id == temp)
               printf("%d %s %s %d\n", stu[j].id, stu[j].name, stu[j].sex, stu[j].age);
            }

    }
}
