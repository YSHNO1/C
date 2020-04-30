#include <stdio.h>
#include <string.h>

int main()
{
    char ID[16];
    char sign_in_time[10];
    char sign_out_time[10];
    char E_p[16], L_p[16];
    char early[10] = "23:59:59";
    char late[10] = "00:00:00";
    int M;
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%s %s %s", ID, sign_in_time, sign_out_time);
        if(strcmp(sign_in_time, early) <= 0){
            strcpy(early, sign_in_time);
            strcpy(E_p, ID);
        }
        if(strcmp(sign_out_time, late) >= 0){
            strcpy(late, sign_out_time);
            strcpy(L_p, ID);
        }
    }
    printf("%s %s\n", E_p, L_p);
    return 0;
}

