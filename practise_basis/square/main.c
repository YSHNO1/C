#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, j, col, row;
   char c;
   scanf("%d %c", &col, &c);
   if(col % 2 == 1) row = col / 2 + 1;
   else row = col / 2;
   for(i = 0; i < col; i++){
        printf("%c", c);
   }
   printf("\n");
   for(i = 2; i < row; i++){
        printf("%c", c);
        for(j = 2; j < col; j++){
            printf(" ");
        }
        printf("%c\n", c);
   }
  for(i = 0; i < col; i++){
        printf("%c", c);
   }
   return 0;
}
