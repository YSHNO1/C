#include<stdio.h>

void input(int *number){
    int i;
    for (i=0;i<10;i++)
        scanf("%d",&number[i]);
}

void max_min_value(int *number){
    int*maxnum,*minnum,*p,temp;
    maxnum=minnum=number;
    for(p=number+1;p<number+10;p++)
        if(*p>*maxnum)maxnum=p;
    else if(*p<*minnum)minnum=p;
    temp=number[0];
    number[0]=*minnum;
    *minnum=temp;
    if(maxnum==number)maxnum=minnum;
    temp=number[9];
    number[9]=*maxnum;
    *maxnum=temp;
}

void output(int *number){
    int *p;
    for(p=number;p<number+10;p++)
        printf("%d ",*p);
    printf("\n");
}

int main(){
    int number[10];
    input(number);
    max_min_value(number);
    output( number);
    return 0;
}

