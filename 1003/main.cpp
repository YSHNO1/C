#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        char str[105];
        scanf("%s", str);
        int i, state = 0, Afront = 0, Amiddle = 0, Aafter = 0;
        for(i = 0; i < strlen(str); i++){
            if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T')
                break;
            if(str[i] == 'P'){
                if(state == 0)
                    state = 1;
                else
                    break;
            }
            if(str[i] == 'A'){
                if(state == 1)
                    state = 2;
                else if(state == 2)
                    Amiddle ++;
                else if(state == 0)
                    Afront ++;
                else Aafter ++;
            }
            if(str[i] == 'T'){
                if(state == 2)
                    state = 3;
                    else break;
            }
        }
         while(Amiddle){
                Aafter -= Afront;
                Amiddle --;
            }
            if(i<strlen(str)||state!=3||Afront!=Aafter)
			printf("NO\n");
		else
			printf("YES\n");
    }
    return 0;
}
