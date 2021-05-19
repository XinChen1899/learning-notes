#include<stdlib.h>
#include<stdio.h>

/***********背包问题***********/

void greedyKnaspsack(int* benifit, int* weight, float* solution, int m, int num){
    
    int i = 0, residual = m;        //分别作为循环变量和背包剩余空间
    for(i = 0; i < num; i++){
        if(weight[i] > residual){
            break;
        }
        solution[i] = 1.0;
        residual = residual - weight[i];
    }
    if(i < num){
        solution[i] = (float)residual/weight[i];
    }
    return;
}

void main(){
    int benifit[3] = {24, 15, 25};  //第i个物品的效益值
    int weight[3] = {15, 10, 18};   //第i个物品的重量
    float solution[3] = {0.0};
    greedyKnaspsack(benifit, weight, solution, 20, 3);
    for(int i = 0; i < 3; i++){
        printf("%d:  %f\n", i, solution[i]);
    }
}