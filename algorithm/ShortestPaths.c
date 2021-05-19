#include<stdlib.h>
#include<stdio.h>
#define true 1
#define false 0
#define bool int

int cost[6][6] = {0, 6,  3, -1, 5, 9,
                  6, 0, -1, -1, 4, 7,
                  3, -1, 0,  6, 1, 8, 
                 -1, -1, 6,  0, 3, -1,
                  5, 4,  1,  3, 0, -1,
                  9, 7,  8, -1,-1, 0};

int finished_nodes[6] = {-1, -1, -1, -1, -1, -1};

int short_distances[6] = {-1, -1, -1, -1, -1, -1};

int short_paths[6][6] = {-1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1}; 

//判断元素是否在数组中，返回布尔值
bool isInArray(int value, int* array, int length){
    int i = 0;
    for(i = 0; i < length; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;
}

//向结点数组插入结点
void insertNode(int node, int* array){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(array[i] == -1){
            array[i] = node;
            return;
        }
    }
}

//合并两个结点子树
void unionNodeArray(int* array1, int* array2){
    int i;
    for(i = 0; i < 6; i++){
        array1[i] = array2[i];
    }
}

void shortTestPaths(int start){
    int i = 0, counter = 1;
    int mincost = -1, minnode = -1;
    insertNode(start, finished_nodes);
    unionNodeArray(short_distances, cost[start]);
    for(i = 0; i < 6; i++){
        short_paths[i][0] = start;
        if(cost[start][i] != -1 && i != start){
            short_paths[i][1] = i;
        }
    }
    while(counter < 6){
        for(i = 0; i < 6; i++){
            if(isInArray(i, finished_nodes, 6)){
                continue;
            }
            if(mincost == -1){
                mincost = short_distances[i];
                minnode = i;
            }
            else if(short_distances[i] < mincost){
                mincost = short_distances[i];
                minnode = i;
            }
        }
        insertNode(minnode, finished_nodes);
        for(i = 0; i < 6; i++){
            if(i != start && i != minnode && cost[minnode][i] != -1){
                if((mincost + cost[minnode][i] < short_distances[i]) || short_distances[i] == -1){
                    short_distances[i] = mincost + cost[minnode][i];
                    unionNodeArray(short_paths[i], short_paths[minnode]);
                }
            }
        }
        counter++;
    }
}

void main(){
    int i, j;
    shortTestPaths(2);
    for(i = 0; i < 6; i++){
        printf("%d:path: ", i);
        for(j = 0; j < 6 && short_paths[i][j] != -1; j++){
            printf("%d\t", short_paths[i][j]);
        }
        printf("distance: %d\n", short_distances[i]);
    }
}