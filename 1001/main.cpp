#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
   int num;
   int n;
   n = 0;
   scanf("%d", &num);
   while(num != 1){
        if(num%2 == 0)
            num = num/2;
        else
            num = (3*num + 1)/2;
        n++;
   }
   printf("%d", n);
}
