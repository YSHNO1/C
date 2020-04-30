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

//读入数据，1代表X 0代表O
void inputData(int array[][SIZE], int n){
    int i , j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
        }
    }
}

//判断函数和，判断行列及对角线是否连续
int whoIsWin(int array[][SIZE], int n){
    int i, j;
    int rowOfo, rowOfx, columnOfo, columnOfx;
    int diagonalOfo, diagonalOfx, rDiagonalOfo, rDiagonalOfx;
    int flag = -1;       // -1 没有赢家， 0 o赢， 1 x赢

    // 判断行列是否相等
    for ( i = 0; i < n && flag == -1; i++ ) {
        rowOfo = rowOfx = columnOfo = columnOfx = 0;
        for ( j = 0; j < n && flag == -1; j++ ) {
            // 判断行，对结果累加
            if ( array[i][j] == 1 ) {
                rowOfx++;
            } else {
                rowOfo++;
            }

            // 判断列，对结果累加
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

    // 判断斜线是否相等
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
        printf("比赛没有赢家。\n");
        break;
    case 0:
        printf("O 一方获得胜利！\n");
        break;
    case 1:
        printf("X 一方获得胜利！\n");
    }
}
