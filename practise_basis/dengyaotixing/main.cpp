#include<cstdio>

int main(){
    int m, h;
    int width;
    scanf("%d", &m);
    while(m--){
        scanf("%d", &h);
        width = h + 2 * (h-1);
        for(int i = 0; i < h; i++){
                for(int j = 0; j < (width - h -2*i)/2; j++){
                    printf(" ");
                }
                for(int j = 0; j < (h + 2*i); j++){
                    printf("*");
                }
                 for(int j = 0; j < (width - h + 2*i)/2; j++){
                    printf(" ");
                }
                printf("\n");
        }
    }
}
