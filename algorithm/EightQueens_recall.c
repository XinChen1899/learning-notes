#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#define bool int
#define true 1
#define false 0
#define num 8

int queen_location[num];    //标记每一行皇后的坐标

bool place(int row){
    int i;
    for(i = 0; i < row; i++){
        if(queen_location[i] == queen_location[row] ||
         abs(queen_location[i] - queen_location[row]) == abs(i - row)){
            return false;
        }
    }
    return true;
}

void printResult(int result_num){
    int i, j;
    printf("\nresult %d:\n", result_num);
    for(i = 0; i < num; i++){
        for(j = 0; j < num; j++){
            if(j == queen_location[i]){
                printf("1\t");
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void eightQueens(){
    int row = 0, result_num = 0;
    queen_location[0] = -1;
    while(row >= 0){
        //printf("%d\n", row);
        queen_location[row]++;
        while(queen_location[row] < num && !place(row)){
            queen_location[row]++;
        }
        if(queen_location[row] < num){
            if(row == num-1){
                result_num++;
                printResult(result_num);
                row--;
            }
            else{
                row++;
                queen_location[row] = -1;
            }
        }
        else{
            row--;
        }
    }
}

int main(){
    eightQueens();
}
