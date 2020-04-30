#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person{
    char name[20];
    int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};

int main()
{
    int n, i;
    char nameInput[20];
    scanf("%d", &n);
    while(n--){
        scanf("%s", nameInput);
        if(strcmp(nameInput,leader[0].name) == 0) leader[0].count++;
        if(strcmp(nameInput,leader[1].name) == 0) leader[1].count++;
        if(strcmp(nameInput,leader[2].name) == 0) leader[2].count++;
    }
    for(i = 0; i < 3; i++){
        printf("%s:%d\n", leader[i].name, leader[i].count);
    }
}
