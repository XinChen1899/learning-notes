#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#define bool int
#define true 1
#define false 0
#define capacity 25
#define num 3

struct obj{
    int weight;
    int value;
} objs[num] = {{20, 20}, {15, 30}, {10, 25}};

//限界函数
int bound(int value_total, int present_weight, int taken_out){
    //value_total -------- 当前效益值总和
    //present_weight ----- 当前背包重量
    //taken_out ---------- 上次去掉的物品
    int value_test = value_total, weight_test = present_weight;
    int i = 0;
    for(i = taken_out + 1; i < num; i++){
        weight_test += objs[i].weight;
        if(weight_test < capacity){
            value_test += objs[i].value;
        }
        else{
            return (value_test + (1 - (weight_test-capacity)/objs[i].weight)*objs[i].value);
        }
    }
    return value_test;
}

bool result[3] = {false, false, false};     //最优解向量
int result_weight_total = 0;                //最优解的最终重量
int result_value_total = 0; 

//核心算法
void knap(){
    int i = 0, j = 0;
    bool present_result[num] = {false};                     //当前正在计算的解
    int present_weight_total = 0, present_value_total = 0;  //分别是当前解的总重量和总效益值
    while(true){
        while(i < num && (present_weight_total + objs[i].weight) <= capacity){
            present_weight_total += objs[i].weight;
            present_value_total += objs[i].value;
            present_result[i] = true;
            i++;
        }
        if(i >= num){
            result_value_total = present_value_total;
            result_weight_total = present_weight_total;
            printf("\n%d\tvalue:%d\tweight:%d", i, result_value_total, result_weight_total);
            for(j = 0; j < num; j++){
                result[j] = present_result[j];
            }
        }
        else{
            present_result[i] = false;
        }
        while(bound(present_value_total, present_weight_total, i) <= result_value_total){
            //while(i != 0 && present_result[i] != true)
            while(i >= 0 && present_result[i] != true){
                i--;
            }
            if(i < 0){
                return;
            }
            present_result[i] = false;
            present_value_total = present_value_total - objs[i].value;
            present_weight_total = present_weight_total - objs[i].weight;
        }
        i++;
    }
}

int main(){
    knap();
    int i;
    printf("\nresult:\n");
    for(i = 0; i < num; i++){
        printf("%d:%d\t", i+1, result[i]);
    }
    printf("\nvalue:%d\tweight:%d", result_value_total, result_weight_total);
    return 0;
}
