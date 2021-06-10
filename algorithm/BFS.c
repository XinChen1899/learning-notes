#include"stdio.h"
#include"stdlib.h"
#define true 1
#define false 0
#define bool int

int graph[6][6] = {0, 6,  3, -1, 5, 9,
                  6, 0, -1, -1, 4, 7,
                  3, -1, 0,  6, 1, 8, 
                 -1, -1, 6,  0, 3, -1,
                  5, 4,  1,  3, 0, -1,
                  9, 7,  8, -1,-1, 0};

//主要是用于向not_finished_nodes插入结点
void insertNode(int node, int* array){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(array[i] == -1){
            array[i] = node;
            return;
        }
    }
}

//主要是用于从not_vistited_nodes取结点
int deleteNode(int* array){
    int i = 0, temp = 0;
    for(i = 0; i < 6; i++){
        if(array[i] == -1){
            temp = array[i-1];
            array[i-1] = -1;
            return temp;
        }
    }
}

bool visited[6] = {false};
int not_finished_nodes[6] = {-1, -1, -1, -1, -1, -1};

void BFS(int visiting_node){
    visited[visiting_node] = true;
    printf("%d\t", visiting_node);
    int present_node = visiting_node, adjacent_node = 0;
    while(true){
        for(adjacent_node = 0; adjacent_node < 6; adjacent_node++){
            if(graph[present_node][adjacent_node] > 0){
                if(!visited[adjacent_node]){
                    insertNode(adjacent_node, not_finished_nodes);
                    visited[adjacent_node] = true;
                    printf("%d\t", adjacent_node);
                }
            }
        }
        if(not_finished_nodes[0] == -1){
            return;
        }
        present_node = deleteNode(not_finished_nodes);
    }
}

void BFT(){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(!visited[i]){
            BFS(i);
        }
    }
}

void main(){
    printf("BFT:\t");
    BFT();
    printf("finish!");
}