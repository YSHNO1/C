#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void inputData(int array[][SIZE], int n);
void printWinner(int array[][SIZE], int n);
int whoIsWin(int array[][SIZE], int n);

int main()
{
    int jzq[SIZE][SIZE];

    inputData(jzq, SIZE);
    printWinner(jzq, SIZE);

    return 0;
}

//�������ݣ�1����X 0����O
void inputData(int array[][SIZE], int n){
    int i , j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
        }
    }
}

//�жϺ����ͣ��ж����м��Խ����Ƿ�����
int whoIsWin(int array[][SIZE], int n){
    int i, j;
    int rowOfo, rowOfx, columnOfo, columnOfx;
    int diagonalOfo, diagonalOfx, rDiagonalOfo, rDiagonalOfx;
    int flag = -1;       // -1 û��Ӯ�ң� 0 oӮ�� 1 xӮ

    // �ж������Ƿ����
    for ( i = 0; i < n && flag == -1; i++ ) {
        rowOfo = rowOfx = columnOfo = columnOfx = 0;
        for ( j = 0; j < n && flag == -1; j++ ) {
            // �ж��У��Խ���ۼ�
            if ( array[i][j] == 1 ) {
                rowOfx++;
            } else {
                rowOfo++;
            }

            // �ж��У��Խ���ۼ�
            if ( array[j][i] == 1 ) {
                columnOfx++;
            } else {
                columnOfo++;
            }

            if ( rowOfx == n || columnOfx == n ) {
                flag = 1;
            } else if ( rowOfo == n || columnOfo == n ) {
                flag = 0;
            }
        }
    }

    // �ж�б���Ƿ����
    diagonalOfo = diagonalOfx =  rDiagonalOfo = rDiagonalOfx = 0;
    for ( i = 0; i < n && flag == -1; i++) {
        if ( array[i][i] == 1 ) {
            diagonalOfx++;
        } else {
            diagonalOfo++;
        }
        if ( array[i][n - 1 - i] == 1 ) {
            rDiagonalOfx++;
        } else {
            rDiagonalOfo++;
        }
    }

    if ( flag == -1 && (diagonalOfx == n || rDiagonalOfx == n) ) {
        flag = 1;
    } else if ( flag == -1 && (diagonalOfo == n || rDiagonalOfo == n)) {
        flag = 0;
    }

    return flag;
}

void printWinner(int array[][SIZE], int n) {
    switch ( whoIsWin(array, n) ) {
    case -1:
        printf("����û��Ӯ�ҡ�\n");
        break;
    case 0:
        printf("O һ�����ʤ����\n");
        break;
    case 1:
        printf("X һ�����ʤ����\n");
    }
}
