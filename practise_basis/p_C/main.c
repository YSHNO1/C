#include<stdio.h>
#include<string.h>
int main()
{
    int k=0;
    char a[10000],ans[10000];
    char temp[10000];
    gets(temp);
    for(int i=0; i<strlen(temp);i++)
    {//A 65 a 97
        if(temp[i]>='A'&&temp[i]<='Z')
            temp[i]+=32;
    }
    int len = strlen(temp);
    while(scanf("%c",&a[k])!=EOF)
    {
        ans[k] = a[k];
        if(a[k]>='A'&&a[k]<='Z')
            a[k]+=32;
        if(a[k]==temp[len-1])
        {
            int i=0,t=0;
            for(i=k-len+1; i<=k; i++)
            {
                if(temp[t++]!=a[i])
                    break;
            }
            if(i==k+1)
                k = k-len+1;
            else
                k++;
        }
        else
            k++;
    }
    for(int i=0; i<k; i++)
    {
        if(ans[i]!=' ')
            printf("%c",ans[i]);
    }
    printf("\n");


}
