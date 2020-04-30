#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count[10], i, j;
    for(i=0 ; i<10; i++){
        scanf("%d", &count[i]);
    }
    for(i=1; i<10; i++){
        if(count[i] > 0){
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for(i=0; i<10; i++){
        for(j=0; j<count[i]; j++){
            printf("%d", i);
        }
    }
}
