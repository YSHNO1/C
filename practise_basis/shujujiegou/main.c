#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR -1
#define MAX_SIZE 100

typedef struct sqlist
{
    int elem[MAX_SIZE];
    int length;
}Sqlist;

void PrintList(Sqlist *L)
{
    int i;
    for(i = 0;i<L->length;i++)
    {
        printf("%d ",L->elem[i]);
    }
}

int CreatList(Sqlist *L)
{
    int len;
    int i;
    printf("input length:\n");
        scanf("%d",&len);
    if(len<0||len>MAX_SIZE)
        return ERROR;
    L->length = len;
    for(i = 0;i<len;i++)
    {
        scanf("%d",&L->elem[i]);
    }
}
int ReverseList(Sqlist *L)
{
    int i;
    int temp;
    if(L->length==0)
    {
        printf("list is empty\n");
        return ERROR;
    }

    else
    {
        for(i = 0;i<L->length/2;i++)
        {
            temp = L->elem[i];
            L->elem[i] = L->elem[L->length-i-1];
            L->elem[L->length-i-1]=temp;

        }
    }
}



void main()
{
    Sqlist l;
    l.length = 0;
    CreatList(&l);
    printf("start:\n");
    PrintList(&l);
    ReverseList(&l);
    printf("\n");
    printf("end:\n");
    PrintList(&l);

}
