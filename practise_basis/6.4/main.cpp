#include <stdio.h>
#include <string.h>
int main(){
    int a[10], i, n, j;
    memset(a,0,sizeof(a));
    for(i = 0; i < 9; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    for(i=0; i<=9; i++) {
		if(a[i]>n) {
			for(j=0; j<9-i ; j++) {
				a[9 -j] =a[9-j-1];//��������a[j] =a[j-1]
			}
		a[i]=n;
		break;
		}
		a[9]=n;//�����a[8] ��ֱ�ӽ�a[9] ��Ϊn
	}
    for(i = 0; i <= 9; i++){
        printf("%d\n", a[i]);
    }
}
